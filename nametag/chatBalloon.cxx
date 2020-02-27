/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file chatBalloon.cxx
 * @author loblao
 */

#include "chatBalloon.h"
#include "nametagGlobals.h"
#include "cullFaceAttrib.h"
#include "cullBinAttrib.h"
#include "colorAttrib.h"
#include "decalEffect.h"
#include "sceneGraphReducer.h"
#include "textNode.h"
#include "modelNode.h"

PT(PandaNode) ChatBalloon::find_geom_node(PT(PandaNode) node) {
  if (node->is_geom_node())
    return node;

  for (int i = 0; i < node->get_num_children(); i++) {
    PT(PandaNode) n = ChatBalloon::find_geom_node(node->get_child(i));
    if (n != nullptr)
      return n;
  }

  return nullptr;
}

PT(PandaNode) ChatBalloon::find_middle_geom(PT(PandaNode) node) {
  if (!node->get_num_children())
    return nullptr;

  PT(PandaNode) child;
  for (int i = 0; i < node->get_num_children(); i++) {
    child = node->get_child(i);
    if (child->get_name() == "middle")
      return child;

    PT(PandaNode) n = ChatBalloon::find_middle_geom(child);
    if (n != nullptr)
      return n;
  }

  return ChatBalloon::find_middle_geom(child);
}

bool ChatBalloon::scan(PT(PandaNode) node) {
  if (node->get_name() == "chatBalloon")
    return scan_balloon(node);

  for (int i = 0; i < node->get_num_children(); i++) {
    if (scan(node->get_child(i)))
      return true;
  }

  return false;
}

bool ChatBalloon::scan_balloon(PT(PandaNode) node) {
  m_copy_node = node->copy_subgraph();

  for (int i = 0; i < node->get_num_children(); i++) {
    PT(PandaNode) child = node->get_child(i);
    if (child->get_name() == "top") {
      m_top_node = child;
      m_top_mat = child->get_transform()->get_mat();
    }

    else if (child->get_name() == "middle") {
      m_middle_node = child;
      m_middle_mat = child->get_transform()->get_mat();
    }

    else if (child->get_name() == "bottom") {
      m_bottom_node = child;
      m_bottom_mat = child->get_transform()->get_mat();
    }
  }

  if (m_top_node != nullptr && m_middle_node != nullptr && m_bottom_node != nullptr)
    return true;

  // XXX TODO warning('ChatBalloon geometry does not include top, middle, and bottom nodes.')
  return false;
}

PT(PandaNode) ChatBalloon::generate(const std::string& text, PT(TextFont) font, float wordwrap,
                                    LColorf text_color, LColorf balloon_color, bool for_3d,
                                    bool has_draw_order, int draw_order, const NodePath& page_button,
                                    bool space_for_button, bool reversed, NodePath& new_button) {
  PT(PandaNode) chat_node = new PandaNode("chat");
  chat_node->set_attrib(CullFaceAttrib::make(CullFaceAttrib::M_cull_none));

  PT(TextNode) text_node = NametagGlobals::get_text_node();
  text_node->set_font(font);
  text_node->set_wordwrap(wordwrap);
  text_node->set_align(TextNode::A_left);
  text_node->set_text(text);

  float v116 = NametagGlobals::_balloon_text_origin[0];
  if (reversed)
    v116 += 9.0;

  m_hscale = (text_node->get_right() - text_node->get_left()) * 0.11111111;
  if (m_hscale < 0.25) {
    m_hscale = 0.25;
    text_node->set_align(TextNode::A_center);

    v116 += reversed ? -4.5 : 4.5;
  }

  else if (reversed)
    m_hscale *= -1;

  m_text_frame = text_node->get_card_actual();

  float space = space_for_button ? 0.2 : 0.0;
  int num_rows = std::max(1, text_node->get_num_rows());
  int num_rows_minus_1 = num_rows - 1;

  float line_h = text_node->get_font()->get_line_height();
  m_text_height = num_rows * line_h + space;

  LMatrix4f subgraph_copy_mat(m_hscale, 0, 0, 0,
                              0, 1.0, 0, 0,
                              0, 0, 1.0, 0,
                              0, 0, 0, 1.0);
  LMatrix4f middle_mat(1, 0, 0, 0,
                       0, 1, 0, 0,
                       0, 0, m_text_height, 0,
                       0, 0, 0, 1);
  middle_mat *= m_middle_mat;

  LMatrix4f top_mat(1, 0, 0, 0,
                    0, 1, 0, 0,
                    0, 0, 1, 0,
                    0, 0, m_text_height - 1.0, 1);
  top_mat *= m_top_mat;

  float v137 = v116 * m_hscale;
  float v138 = 0.0;
  float v139 = NametagGlobals::_balloon_text_origin[2] + num_rows_minus_1 * line_h + space + 0.2;

  m_text_frame += LVector4f(v137, v137, v139, v139);

  /*if (m_top_node != nullptr)
    m_top_node->set_transform(TransformState::make_mat(top_mat));

  if (m_middle_node != nullptr)
    m_middle_node->set_transform(TransformState::make_mat(middle_mat));

  PT(PandaNode) subgraph_copy = m_copy_node->copy_subgraph();
  chat_node->add_child(subgraph_copy);
  subgraph_copy->set_transform(TransformState::make_mat(subgraph_copy_mat));*/

  PT(PandaNode) subgraph_copy = m_copy_node->copy_subgraph();
  NodePath::any_path(subgraph_copy).find("**/top").node()->set_transform(TransformState::make_mat(top_mat));
  NodePath::any_path(subgraph_copy).find("**/middle").node()->set_transform(TransformState::make_mat(middle_mat));
  chat_node->add_child(subgraph_copy);
  subgraph_copy->set_transform(TransformState::make_mat(subgraph_copy_mat));

  if (has_draw_order)
    subgraph_copy->set_attrib(CullBinAttrib::make(nametag_fixed_bin, draw_order));

  subgraph_copy->set_attrib(ColorAttrib::make_flat(balloon_color));
  if (balloon_color[3] != 1.0)
    subgraph_copy->set_attrib(TransparencyAttrib::make(TransparencyAttrib::M_alpha));

  {
    SceneGraphReducer reducer;
    reducer.apply_attribs(subgraph_copy);
    reducer.flatten(chat_node, -1);
  }

  PT(PandaNode) generated_text = text_node->generate();
  PT(PandaNode) v86;
  if (for_3d) {
    v86 = ChatBalloon::find_middle_geom(chat_node);
    if (v86 == nullptr)
      v86 = ChatBalloon::find_geom_node(chat_node);

    v86->set_effect(DecalEffect::make());
  }

  else {
    v86 = chat_node;
    if (has_draw_order)
      generated_text->set_attrib(CullBinAttrib::make(nametag_fixed_bin, draw_order + 1));
  }

  NodePath np = NodePath::any_path(v86);
  NodePath v144 = np.attach_new_node(generated_text);
  v144.set_pos(v137, v138, v139);
  v144.set_color(text_color);
  v144.set_y(-0.01); // Panda3D 1.10 hack to prevent z-fighting.
  if (text_color[3] != 1.0)
    v144.set_transparency(TransparencyAttrib::M_alpha);

  if (!page_button.is_empty()) {
    nassertr(false, nullptr);
    PT(ModelNode) v116 = new ModelNode("button");
    new_button = np.attach_new_node(v116);
    NodePath button_copy = page_button.copy_to(new_button);
    button_copy.set_pos(m_hscale * (reversed ? 1.7 : 9.0), 0, 1.8);
    button_copy.set_scale(8.0, 8.0, 8.0);
    button_copy.set_y(-0.01); // Panda3D 1.10 hack to prevent z-fighting.
  }

  {
    SceneGraphReducer reducer;
    reducer.apply_attribs(generated_text);
    reducer.flatten(chat_node, 1);
  }

  return chat_node;
}
