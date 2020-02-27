/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametag3d.cxx
 * @author loblao
 */

#include "nametag3d.h"
#include "boundingSphere.h"
#include "cardMaker.h"
#include "look_at.h"

TypeHandle Nametag3d::_type_handle;

Nametag3d::Nametag3d() : Nametag(10.5), PandaNode("unnamed"),
    m_np_360(NodePath()), m_np_372(NodePath()),
    m_np_balloon(NodePath()), m_billboard_offset(3.0),
    m_is_3d(true), m_field_396(0) {
  set_cull_callback();
  m_np_top = NodePath::any_path(new PandaNode("top"));
  m_chat_contents = 0;

  set_bounds(new BoundingSphere(LPoint3f(0, 0, 0), 2.0));
}

bool Nametag3d::cull_callback(CullTraverser* trav, CullTraverserData& data) {
  if (is_group_managed()) {
    int sort = CullBinManager::get_global_ptr()->get_bin_sort(data._state->get_bin_index());
    adjust_to_camera(data.get_node_path(), sort);
  }

  return true;
}

void Nametag3d::update_contents() {
  stop_flash();

  if (m_has_draw_order)
    m_np_top.set_bin(nametag_fixed_bin, m_draw_order);

  else
    m_np_top.clear_bin();

  set_name(has_group() ? m_group->get_name() : "unnamed");

  if (!m_np_360.is_empty())
    m_np_360.remove_node();

  if (!m_np_372.is_empty())
    m_np_372.remove_node();

  if (!m_np_balloon.is_empty())
    m_np_balloon.remove_node();

  m_np_top.node()->remove_all_children();

  m_chat_contents = determine_contents();
  if (is_group_managed()) {
    if (m_chat_contents & Nametag::C_speech)
      generate_chat(NametagGlobals::_speech_balloon_3d);

    else if (m_chat_contents & Nametag::C_thought)
      generate_chat(NametagGlobals::_thought_balloon_3d);

    else if (m_chat_contents & Nametag::C_name)
      generate_name();
  }
}

void Nametag3d::adjust_to_camera(NodePath np, int sort) {
  if (m_is_3d) {
    PT(Lens) lens = DCAST(LensNode, NametagGlobals::_camera.node())->get_lens(0);
    NodePath v131 = (!m_avatar.is_empty() || !has_group()) ? m_avatar : m_group->get_avatar();
    LMatrix4f v25 = NametagGlobals::_camera.get_transform(np)->get_mat();
    LVector3f v204 = v25.xform_vec(LVector3f::up());
    LVector3f v203 = v25.xform_vec(LVector3f::forward());

    LMatrix3f v193;
    look_at(v193, v203, v204);
    LMatrix4f v177(v193);
    float v177_3_0 = v177[3][0];
    float v177_3_1 = v177[3][1];

    LMatrix4f a3 = np.get_transform(NametagGlobals::_camera)->get_mat();
    float v122 = a3[3][1];
    float v30 = (v122 > 0.1) ? v122 : 0.1;
    float v31 = v30 * 0.02;
    float v121 = std::pow(v31, 0.5) * NametagGlobals::get_global_nametag_scale() * 0.56;

    float v42 = 0;
    if (m_billboard_offset != 0.0) {
      float v32 = v25[0][1];
      float v33 = v25[0][0];
      float v136 = v25[0][2];
      float v134 = v33;
      float v127 = m_billboard_offset;
      float v144 = sqrt(v136 * v136 + v32 * v32 + v134 * v134);
      float v129 = m_billboard_offset / v144;

      if (v122 > 0.0) {
        if (lens->get_type().is_derived_from(PerspectiveLens::get_class_type())) {
          float v37 = lens->get_near() + 0.001;
          if (v122 - v129 < v37) {
            v129 = v122 - v37;
            v127 = v129 * v144;
          }

          v121 = (v122 - v129) / v122 * v121;
        }
      }

      float v38 = v25[3][0];
      float v39 = v25[3][1];
      float v126 = v25[3][2];
      float v125 = v39;
      v129 = v126 * v126 + v39 * v39 + v38 * v38;
      if (v129 == 0.0) {
        v125 = 0.0;
        v38 = 0.0;
        v126 = 0.0;
      }

      else {
        float v40 = v129 - 1.0;
        if (!IS_NEARLY_ZERO(v40)) {
          float v41 = 1.0 / sqrt(v129);
          v38 *= v41;
          v125 *= v41;
          v126 *= v41;
        }
      }

      v126 *= v127;
      v177_3_0 = v38 * v127;
      v177_3_1 = v125 * v127;
      v42 = v126;
    }

    LMatrix4f v205(v177[0][0] * v121, v177[0][1] * v121, v177[0][2] * v121, v177[0][3] * v121,
                   v177[1][0] * v121, v177[1][1] * v121, v177[1][2] * v121, v177[1][3] * v121,
                   v177[2][0] * v121, v177[2][1] * v121, v177[2][2] * v121, v177[2][3] * v121,
                   v177_3_0, v177_3_1, v42, v177[3][3]);
    m_np_top.set_mat(v205);

    int v51 = 0;
    if (display_as_active()) {
      if (!(m_chat_contents & (Nametag::C_speech | Nametag::C_thought)))
        v51 = 1;

      else if (!has_group())
        v51 = 1;

      else if (!m_group->m_is_flashing)
        v51 = 1;

      else if (!m_group->will_have_button())
        v51 = 1;

      else if (m_group->get_page_number() >= m_group->get_num_chat_pages() - 1)
        v51 = 1;
    }

    int v123 = 0;
    int sorta = 0;
    LVector4f frame(0, 0, 0, 0);
    LMatrix4f v150 = lens->get_projection_mat();

    if (v51) {
      LVector3f v138_vec = v205.xform_vec(LVector3f(-2.5, 0.0, 1.0));
      float v138 = v138_vec[0];
      float v139 = v138_vec[1];
      float v140 = v138_vec[2];

      LVector3f v124_vec = v205.xform_vec(LVector3f(2.5, 0.0, 1.0));
      float v124 = v124_vec[0];
      float v125 = v124_vec[1];
      float v126 = v124_vec[2];

      CPT(TransformState) v121 = np.get_transform(v131);
      if (v121->is_invalid())
        return;

      LMatrix4f v64 = v121->get_mat();
      LPoint3f v138_point = v64.xform_point(LPoint3f(v138, v139, v140));
      v138 = v138_point[0];
      v139 = v138_point[1];
      v140 = v138_point[2];

      LPoint3f v124_point = v64.xform_point(LPoint3f(v124, v125, v126));
      v124 = v124_point[0];
      v125 = v124_point[1];
      v126 = v124_point[2];

      CPT(TransformState) v122 = v131.get_transform(NametagGlobals::_camera);
      if (v122->is_invalid())
        return;

      v124_point = v122->get_mat().xform_point(LPoint3f(v124, v125, v126));
      v124 = v124_point[0];
      v125 = v124_point[1];
      v126 = v124_point[2];

      LPoint3f v134_point = v122->get_mat().xform_point(LPoint3f(v138, v139, 0.0));
      float v134 = v134_point[0];
      float v135 = v134_point[1];
      float v136 = v134_point[2];

      LVector4f a2 = v150.xform(LVector4f(v124, v125, v126, 1.0));
      frame = v150.xform(LVector4f(v134, v135, v136, 1.0));

      if (a2[3] <= 0.0 || frame[3] <= 0.0) {
        m_group->m_nametag3d_flag &= (m_group->m_nametag3d_flag <= 0) - 1;
        deactivate();
        return;
      }

      v123 = 1;
      float v133 = 1.0 / frame[3];
      float v128 = 1.0 / a2[3];
      frame = LVector4f(frame[0] * v133, a2[0] * v128, frame[1] * v133, a2[1] * v128);
    }

    int v89 = 0;
    if (m_field_396) {
      LPoint3f v124_point = v205.xform_point(LPoint3f(m_name_frame[0] - 0.5, 0.0, m_name_frame[2] - 1.0));
      v124_point = a3.xform_point(v124_point);
      float v124 = v124_point[0];
      float v125 = v124_point[1];
      float v126 = v124_point[2];

      LPoint3f v138_point = v205.xform_point(LPoint3f(m_name_frame[1] + 0.5, 0.0, m_name_frame[3] + 1.0));
      v138_point = a3.xform_point(v138_point);
      float v138 = v138_point[0];
      float v139 = v138_point[1];
      float v140 = v138_point[2];

      LVector4f a2 = v150.xform(LVector4f(v138, v139, v140, 1.0));
      LVector4f v134_vec = v150.xform(LVector4f(v124, v125, v126, 1.0));
      float v134 = v134_vec[0];
      float v135 = v134_vec[1];
      float v137 = v134_vec[3];

      if (v137 <= 0.0 || a2[3] <= 0.0)
        v89 = 1;

      else {
        float v133 = 1.0 / v137;
        float v109 = 1.0 / a2[3];
        float v110 = v109 * a2[1];
        float v127 = v133 * v135;
        float v131b = v109 * a2[0];
        float v111 = v133 * v134;
        float v146 = v111;

        if (v111 < -1.0 || v131b > 1.0 || v127 < -1.0 || v110 > 1.0)
          v89 = 1;

        if (v123) {
          if (frame[3] > v110)
            v110 = frame[3];

          float v115 = (frame[2] >= v127) ? v127 : frame[2];
          float v116 = (frame[1] <= v131b) ? v131b : frame[1];

          if (frame[0] >= v146)
            frame[0] = v146;

          frame[1] = v116;
          frame[2] = v115;
        }

        else {
          frame[0] = v146;
          frame[1] = v131b;
          frame[2] = v127;
          v123 = 1;
        }

        frame[3] = v110;
        sorta = (int)(v125 * -100.0);
      }
    }

    if (v123 && display_as_active())
      set_region(frame, sorta);

    int v118 = m_group->get_nametag3d_flag();
    if (v89)
      v118 = (v118 > 1) ? v118 : 1;

    else if (v118 <= 2)
      v118 = 2;

    m_group->set_nametag3d_flag(v118);
    return;
  }

  m_group->increment_nametag3d_flag(2);
  if (!display_as_active())
    return;

  if (!m_field_396)
    return;

  LMatrix4f v12 = np.get_net_transform()->get_mat();
  LPoint3f v124 = v12.xform_point(LPoint3f(m_name_frame[0] - 0.5, 0, m_name_frame[2] - 1.0));
  LPoint3f v16 = v12.xform_point(LPoint3f(m_name_frame[1] + 0.5, 0, m_name_frame[3] + 1.0));

  LVector4f v131(v124[0], v16[0], v124[2], v16[2]);
  set_region(v131, sort);
}

void Nametag3d::generate_chat(PT(ChatBalloon) balloon) {
  PGButton::State v5 = this->Nametag::get_state();
  LVector4f text_color = NametagGlobals::get_chat_fg(m_group->get_color_code(), v5);
  LVector4f balloon_color = NametagGlobals::get_chat_bg(m_group->get_color_code(), v5);

  if (m_group->get_chat_flags() & CF_quicktalker)
    balloon_color = m_group->get_qt_color();

  std::string text = m_group->get_chat();
  bool has_page_button = false;
  bool has_quit_button = false;
  if (!m_group->m_is_flashing) {
    has_page_button = m_group->get_chat_flags() & CF_page_button;
    if (m_group->get_page_number() >= m_group->get_num_chat_pages() - 1) {
      if (m_group->get_chat_flags() & CF_quit_button) {
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

  bool reversed = m_group->get_chat_flags() & CF_reversed;
  PT(PandaNode) balloon_result;
  balloon_result = balloon->generate(text, m_group->get_chat_font(),
                                     m_wordwrap, text_color, balloon_color,
                                     m_is_3d, m_has_draw_order, m_draw_order,
                                     page_button, m_group->will_have_button(),
                                     reversed, new_button);
  m_np_balloon = m_np_top.attach_new_node(balloon_result);
  if (!new_button.is_empty())
    start_flash(new_button);

  m_name_frame = balloon->get_text_frame();
  m_field_396 = 1;
}

void Nametag3d::generate_name() {
  PGButton::State v4 = this->Nametag::get_state();
  LVector4f v56 = NametagGlobals::get_chat_fg(m_group->get_color_code(), v4);
  LVector4f v54 = NametagGlobals::get_chat_bg(m_group->get_color_code(), v4);

  m_name_frame = m_group->get_name_frame();
  m_name_frame[0] -= NametagGlobals::_card_pad[0];
  m_name_frame[1] += NametagGlobals::_card_pad[1];
  m_name_frame[2] -= NametagGlobals::_card_pad[2];
  m_name_frame[3] += NametagGlobals::_card_pad[3];

  m_field_396 = 1;

  NodePath v47 = NodePath();
  if (v54[3] != 0.0) {
    CardMaker card("nametag");
    card.set_frame(m_name_frame);
    card.set_color(v54);
    if (!NametagGlobals::_nametag_card.is_empty())
      card.set_source_geometry(NametagGlobals::_nametag_card.node(),
                               NametagGlobals::_nametag_card_frame);

    m_np_372 = m_np_top.attach_new_node(card.generate());
    m_np_372.set_transparency(TransparencyAttrib::M_alpha);
    v47 = m_np_372.find("**/+GeomNode");
  }

  bool label86 = false;
  if (m_is_3d) {
    if (!m_group->m_name_icon.is_empty())
      m_group->m_name_icon.instance_to(m_np_top);

    if (!v47.is_empty()) {
      m_np_360 = m_group->copy_name_to(v47);
      m_np_360.set_depth_write(0);
      m_np_360.set_y(-0.01); // Panda3D 1.10 hack to prevent z-fighting.
      v47.node()->set_effect(DecalEffect::make());
    }

    else
      label86 = true;
  }

  else
    label86 = true;

  if (label86) {
    m_np_360 = m_group->copy_name_to(m_np_top);
    if (m_has_draw_order) {
      m_group->m_name_icon.set_bin(nametag_fixed_bin, m_draw_order + 1);
      m_np_360.set_bin(nametag_fixed_bin, m_draw_order + 2);
    }
  }

  m_np_360.set_color(v56);
  if (v56[3] != 1.0)
    m_np_360.set_transparency(TransparencyAttrib::M_alpha);
}
