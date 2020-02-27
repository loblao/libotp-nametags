/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametag.I
 * @author loblao
 */

INLINE Nametag::Nametag(float wordwrap) : ClickablePopup(),
    m_avatar(NodePath()), m_ival(nullptr),
    m_popup_region(nullptr), m_seq2d(0),
    m_mouse_watcher(nullptr), m_draw_order(0),
    m_has_draw_order(false), m_contents(CF_speech | CF_thought | CF_quicktalker),
    m_active(true), m_group(nullptr), m_wordwrap(wordwrap), m_has_region(false) {
  char ival_name[136];
  sprintf(ival_name, "flash-%p", this);
  m_ival_name = std::string(ival_name);
}

INLINE Nametag::~Nametag() {
  m_mouse_watcher = nullptr;
  m_popup_region = nullptr;
  m_ival = nullptr;
}

INLINE void Nametag::set_contents(int contents) {
  m_contents = contents;
  update_contents();
}

INLINE void Nametag::set_active(bool active) {
  m_active = active;
  update_contents();
}

INLINE bool Nametag::has_group() {
  return m_group != nullptr;
}

INLINE NametagGroup* Nametag::get_group() {
  return m_group;
}

INLINE void Nametag::set_draw_order(int draw_order) {
  m_draw_order = draw_order;
  m_has_draw_order = true;
  update_contents();
}

INLINE void Nametag::clear_draw_order() {
  m_has_draw_order = false;
  update_contents();
}

INLINE void Nametag::set_chat_wordwrap(float wordwrap) {
  m_wordwrap = wordwrap;
}

INLINE float Nametag::get_chat_wordwrap() {
  return m_wordwrap;
}

INLINE void Nametag::set_avatar(const NodePath& avatar) {
  m_avatar = avatar;
}

INLINE NodePath Nametag::get_avatar() {
  return m_avatar;
}

INLINE void Nametag::clear_avatar() {
  m_avatar = NodePath();
}

INLINE bool Nametag::is_group_managed() {
  return has_group() && m_group->is_managed();
}

INLINE void Nametag::click() {
  if (has_group())
    m_group->click();
}

INLINE void Nametag::manage(PT(MarginManager) manager) {
  update_contents();
}

INLINE void Nametag::unmanage(PT(MarginManager) manager) {
  update_contents();
  deactivate();
}

INLINE void Nametag::keep_region() {
  if (m_popup_region != nullptr)
    m_seq2d = m_group->get_region_seq();
}
