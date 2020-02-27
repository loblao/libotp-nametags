/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametag2d.cxx
 * @author mfwass
 * @author loblao
 */

#include "nametag2d.h"
#include "cardMaker.h"

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <math.h>

TypeHandle Nametag2d::_type_handle;

Nametag2d::Nametag2d() : Nametag(8.075), MarginPopup(),
    m_copied_np(NodePath()),
    m_attached_np(NodePath()),
    m_arrow(NodePath()),
    m_unknown_np(NodePath()),
    m_on(NametagGlobals::_master_arrows_on) {
  set_cull_callback();
  set_name("unnamed");
  m_contents = Nametag::C_speech | Nametag::C_name;
  m_chat_contents = 0;
  update_contents();
}

bool Nametag2d::cull_callback(CullTraverser* trav, CullTraverserData& data) {
  rotate_arrow();
  return true;
}

void Nametag2d::update_contents() {
  stop_flash();

  set_name(has_group() ? m_group->get_name() : "unnamed");

  if (!m_copied_np.is_empty())
      m_copied_np.remove_node();

  if (!m_attached_np.is_empty())
      m_attached_np.remove_node();

  if (!m_arrow.is_empty())
      m_arrow.remove_node();

  if (!m_unknown_np.is_empty())
      m_unknown_np.remove_node();

  m_chat_contents = determine_contents();
  if (!NametagGlobals::_master_arrows_on)
    m_chat_contents &= ~Nametag::C_name;

  if (m_visible && is_group_managed()) {
    int v10 = m_chat_contents;
    if (v10 & Nametag::C_speech)
      generate_chat(NametagGlobals::_speech_balloon_2d);

    else if (v10 & Nametag::C_thought)
      generate_chat(NametagGlobals::_thought_balloon_2d);

    else if (v10 & Nametag::C_name)
      generate_name();
  }
}

bool Nametag2d::consider_visible() {
  bool v2 = false;
  bool do_update = true;

  if (m_on != NametagGlobals::_master_arrows_on) {
    m_on = NametagGlobals::_master_arrows_on;
    v2 = true;
  }

  if (m_seq2d == NametagGlobals::_margin_prop_seq) {
    if (!v2)
      do_update = false;
  }

  else
    m_seq2d = NametagGlobals::_margin_prop_seq;

  if (do_update)
    update_contents();

  if (!m_chat_contents)
    return false;

  bool result = m_group->get_nametag3d_flag() != 2;
  if (NametagGlobals::_onscreen_chat_forced && m_chat_contents & (Nametag::C_speech | Nametag::C_thought))
    result = 1;

  m_group->set_nametag3d_flag(0);
  if (!result)
    return false;

  switch (m_group->get_color_code()) {
    case NametagGroup::CC_toon_building:
    case NametagGroup::CC_suit_building:
    case NametagGroup::CC_house_building:
      return get_distance2() < 1600;
    default:
      return result;
  }
}

void Nametag2d::rotate_arrow() {
  if (m_arrow.is_empty())
    return;

  NodePath np = m_avatar.is_empty() ? m_group->get_avatar() : m_avatar;
  if (np.is_empty())
    return;

  LVector3f relpos = np.get_pos(NametagGlobals::_camera) - NametagGlobals::_toon.get_pos(NametagGlobals::_camera);
  LVector3f hpr(0, 0, -atan2(relpos[1], relpos[0]) * 180.0 / M_PI);
  LVector3f scale(0.5, 0.5, 0.5);
  LVector3f shear(0, 0, 0);

  LMatrix3f temp_mat_3;
  compose_matrix(temp_mat_3, scale, shear, hpr);
  LMatrix4f arrow_mat(temp_mat_3, m_trans_vec);
  m_arrow.set_mat(arrow_mat);
}

void Nametag2d::generate_chat(PT(ChatBalloon) balloon) {
  PGButton::State v5 = this->Nametag::get_state();
  LVector4f text_color = NametagGlobals::get_chat_fg(m_group->get_color_code(), v5);
  LVector4f balloon_color = NametagGlobals::get_chat_bg(m_group->get_color_code(), v5);

  if (m_group->m_chat_flags & CF_quicktalker)
    balloon_color = m_group->get_qt_color();

  balloon_color[3] = std::max(balloon_color[3], NametagGlobals::_min_2d_alpha);
  balloon_color[3] = std::min(balloon_color[3], NametagGlobals::_max_2d_alpha);

  std::string text = m_group->get_chat();
  if (m_group->m_name.size())
    text = m_group->m_name + ": " + text;

  bool has_page_button = false;
  bool has_quit_button = false;
  if (!m_group->m_is_flashing) {
    has_page_button = m_group->m_chat_flags & CF_page_button;
    if (m_group->get_page_number() >= m_group->get_num_chat_pages() - 1) {
      if (m_group->m_chat_flags & CF_quit_button) {
        has_page_button = false;
        has_quit_button = true;
      }
    }
  }

  NodePath page_button, new_button;

  if (has_page_button)
    page_button = NametagGlobals::get_page_button(v5);

  else if (has_quit_button)
    page_button = NametagGlobals::get_quit_button(v5);

  bool reversed = m_group->m_chat_flags & CF_reversed;

  PT(PandaNode) balloon_result;
  balloon_result = balloon->generate(text, m_group->get_chat_font(), m_wordwrap,
                                     text_color, balloon_color, false,
                                     m_has_draw_order, m_draw_order,
                                     page_button, m_group->will_have_button(),
                                     reversed, new_button);
  m_unknown_np = m_np.attach_new_node(balloon_result);

  float v88, v49, a6, v50, v85, v113, v51, v67, v68;

  v88 = 8.0;  // XXX THIS IS A GUESS
  v49 = 2 * m_cell_width;
  a6 = v49 / (v88 + 1.0);
  v50 = balloon->get_text_height() * balloon->get_hscale();
  v85 = balloon->get_hscale() * 5.0;
  v88 = v50 * 0.5;
  v113 = -(balloon->get_hscale() * 0.5 + v85);
  v51 = -(NametagGlobals::_balloon_text_origin[2] + v88);

  v67 = v113 * a6;
  v68 = v51 * a6;

  LMatrix4f v118(a6, 0, 0, 0,
                 0, a6, 0, 0,
                 0, 0, a6, 0,
                 v67, 0, v68, 1.0);
  m_unknown_np.set_mat(v118);

  SceneGraphReducer reducer;
  reducer.apply_attribs(m_unknown_np.node());

  LMatrix4f v66 = m_np.get_net_transform()->get_mat();

  // XXX THE LINES BELOW ARE A GUESS
  LPoint3f v94 = v66.xform_point(LPoint3f(v67, 0.0, v68));
  LPoint3f v97 = v66.xform_point(LPoint3f(-v67, 0.0, -v68));

  LVector4f frame = LVector4f(v94[0], v97[0], v94[2], v97[2]);
  set_region(frame, 0);
}

void Nametag2d::generate_name() {
  PGButton::State v4 = this->Nametag::get_state();
  LVector4f v84 = NametagGlobals::get_name_fg(m_group->get_color_code(), v4);
  LVector4f v75 = NametagGlobals::get_name_bg(m_group->get_color_code(), v4);
  v75[3] = std::max(v75[3], NametagGlobals::_min_2d_alpha);
  v75[3] = std::min(v75[3], NametagGlobals::_max_2d_alpha);

  float v67, v68;
  v67 = NametagGlobals::_card_pad[3] + m_group->m_name_frame[3];
  v68 = m_group->m_name_frame[2] - NametagGlobals::_card_pad[2];

  float wordwrap, v17, v66;
  wordwrap = m_group->get_name_wordwrap();
  v17 = m_cell_width / wordwrap * 2.0;
  v66 = 0.333 * (1.0 / v17) - (v68 + v67) * 0.5;
  float v18 = 1.0 / v17 - v67;
  if (v66 < v18)
    v18 = v66;

  LMatrix4f v69(v17, 0, 0, 0,
                0, v17, 0, 0,
                0, 0, v17, 0,
                0, 0, v18 * v17, 1.0);
  LMatrix4f a3 = v69;

  if (v75[3] != 0.0) {
    CardMaker card("nametag");
    card.set_frame(m_group->m_name_frame[0] - NametagGlobals::_card_pad[0],
                   m_group->m_name_frame[1] + NametagGlobals::_card_pad[1],
                   v68, v67);
    card.set_color(v75);
    if (!NametagGlobals::_nametag_card.is_empty())
      card.set_source_geometry(NametagGlobals::_nametag_card.node(),
                               NametagGlobals::_nametag_card_frame);

    m_attached_np = m_np.attach_new_node(card.generate());
    m_attached_np.set_mat(v69);
    if (v75[3] != 1.0)
      m_attached_np.set_transparency(TransparencyAttrib::M_alpha);

    if (m_has_draw_order)
      m_attached_np.set_bin(nametag_fixed_bin, m_draw_order);
  }

  m_copied_np = m_group->copy_name_to(m_np);
  m_copied_np.set_mat(a3);

  if (m_has_draw_order)
    m_copied_np.set_bin(nametag_fixed_bin, m_draw_order);

  m_copied_np.set_color(v84);
  if (v84[3] != 1.0)
      m_copied_np.set_transparency(TransparencyAttrib::M_alpha);

  SceneGraphReducer reducer;
  reducer.apply_attribs(m_copied_np.node());
  reducer.apply_attribs(m_attached_np.node());

  if (!NametagGlobals::_arrow_model.is_empty()) {
    m_arrow = NametagGlobals::_arrow_model.copy_to(m_np);
    if (m_has_draw_order)
      m_arrow.set_bin(nametag_fixed_bin, m_draw_order);

    m_trans_vec = a3.xform_point(LPoint3f(0, 0, v68 - 1.0));

    LVector4f color = NametagGlobals::get_arrow_color(m_group->get_color_code());
    m_arrow.set_color(color);
    if (color[3] != 1.0)
        m_arrow.set_transparency(TransparencyAttrib::M_alpha);

    rotate_arrow();
  }

  else if (!m_arrow.is_empty())
    m_arrow.remove_node();

  v69 = m_np.get_net_transform()->get_mat();
  v69 = a3 * v69;

  LPoint3f v77 = v69.xform_point(LPoint3f(m_group->m_name_frame[0] - NametagGlobals::_card_pad[0], 0, v68));
  LPoint3f v80 = v69.xform_point(LPoint3f(m_group->m_name_frame[1] + NametagGlobals::_card_pad[1], 0, v67));

  LVector4f frame(v77[0], v80[0], v77[2], v80[2]);
  set_region(frame, 0);
}
