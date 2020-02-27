/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file whisperPopup.cxx
 * @author mfwass
 * @author loblao
 */

#include "whisperPopup.h"
#include "sceneGraphReducer.h"

TypeHandle WhisperPopup::_type_handle;

WhisperPopup::WhisperPopup(const std::string& text, PT(TextFont) font, WhisperPopup::WhisperType type) :
    ClickablePopup(), MarginPopup(), m_text(text),
    m_font(font), m_type(type), m_np_balloon(NodePath()),
    m_region(nullptr), m_mouse_watcher(nullptr),
    m_culled(false), m_clickable(false),
    m_avid(0), m_is_player_id(false) {
  set_cull_callback();
  this->ClickablePopup::set_state(PGButton::S_inactive);
}

void WhisperPopup::set_visible(bool visible) {
  MarginPopup::set_visible(visible);
  update_contents();

  if (!m_clickable || m_region == nullptr)
    return;

  if (m_visible) {
    m_mouse_watcher = NametagGlobals::_mouse_watcher;
    m_mouse_watcher->add_region(m_region);
  }

  else if (m_mouse_watcher != nullptr) {
    m_mouse_watcher->remove_region(m_region);
    m_mouse_watcher = nullptr;
  }
}

bool WhisperPopup::cull_callback(CullTraverser* trav, CullTraverserData& data) {
  if (!m_culled) {
    m_culled = true;
    m_time = ClockObject::get_global_clock()->get_frame_time();
  }

  return true;
}

void WhisperPopup::click() {
  // TODO
}

void WhisperPopup::update_contents() {
  if (!m_np_balloon.is_empty()) {
    m_np_balloon.remove_node();
    m_np_balloon = NodePath();
  }

  if (m_visible)
    generate_text(NametagGlobals::_speech_balloon_2d, m_text, m_font);
}

float WhisperPopup::get_score() {
  float result = 2000.0;

  if (m_culled) {
    double elapsed = ClockObject::get_global_clock()->get_frame_time() - m_time;
    result -= 200.0 * elapsed;
  }

  return result;
}

bool WhisperPopup::consider_visible() {
  if (m_clickable && m_visible && m_mouse_watcher != NametagGlobals::_mouse_watcher)
    return false;

  return MarginPopup::consider_visible();
}

bool WhisperPopup::consider_manage() {
  bool result = true;

  if (m_culled) {
    double elapsed = ClockObject::get_global_clock()->get_frame_time() - m_time;
    result = elapsed < 15.0;
  }

  return result;
}

void WhisperPopup::generate_text(PT(ChatBalloon) balloon,
                                 const std::string& text,
                                 PT(TextFont) font) {
  LVector4f text_color = NametagGlobals::get_whisper_fg(m_type, m_state);
  LVector4f balloon_color = NametagGlobals::get_whisper_bg(m_type, m_state);
  balloon_color[3] = std::max(balloon_color[3], NametagGlobals::_min_2d_alpha);
  balloon_color[3] = std::min(balloon_color[3], NametagGlobals::_max_2d_alpha);

  NodePath new_button;
  PT(PandaNode) balloon_result;
  balloon_result = balloon->generate(text, font, 8.0,
                                     text_color, balloon_color,
                                     false, false, 0, NodePath(),
                                     false, false, new_button);
  m_np_balloon = m_np.attach_new_node(balloon_result);

  float v34, v35, v57, v16;
  v34 = m_cell_width * 0.22222222;
  v35 = balloon->get_text_height() * balloon->get_hscale() * 0.5;
  v57 = -balloon->get_hscale() * 5.5;
  v16 = -(NametagGlobals::_balloon_text_origin[2] + v35);

  LMatrix4f v64(v34, 0, 0, 0,
                0, v34, 0, 0,
                0, 0, v34, 0,
                v57 * v34, 0, v16 * v34, 1.0);
  m_np_balloon.set_mat(v64);

  SceneGraphReducer reducer;
  reducer.apply_attribs(m_np_balloon.node());

  if (m_clickable) {
    LMatrix4f v22 = m_np.get_net_transform()->get_mat();
    LPoint3f v39 = v22.xform_point(LPoint3f(v57 * v34, 0.0, v16 * v34));
    LPoint3f v27 = v22.xform_point(LPoint3f(-v57 * v34, 0.0, -v16 * v34));

    LVector4f frame(v39[0], v27[0], v39[2], v27[2]);
    set_region(frame, 0);
  }
}

void WhisperPopup::set_region(LVector4f& frame, int sort) {
  if (m_region != nullptr)
    m_region->set_frame(frame);

  else {
    std::string v7 = get_type().get_name();
    m_region = new PopupMouseWatcherRegion(this, v7, frame);
  }

  m_region->set_sort(sort);
}
