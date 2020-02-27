/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametagGroup.I
 * @author loblao
 */

INLINE NametagGroup::~NametagGroup() {
  m_tag2d = nullptr;
  m_tag3d = nullptr;
  m_nametags.clear();
  m_name_font = nullptr;
  m_chat_font = nullptr;
  m_node = nullptr;
  m_chat_pages.clear();
  m_manager = nullptr;
}

INLINE void NametagGroup::set_font(PT(TextFont) font) {
  set_name_font(font);
  set_chat_font(font);
}

INLINE void NametagGroup::set_name_font(PT(TextFont) font) {
  m_name_font = font;
}

INLINE PT(TextFont) NametagGroup::get_name_font() {
  return m_name_font;
}

INLINE void NametagGroup::set_chat_font(PT(TextFont) font) {
  m_chat_font = font;
}

INLINE PT(TextFont) NametagGroup::get_chat_font() {
  return m_chat_font;
}

INLINE void NametagGroup::set_avatar(const NodePath& avatar) {
  m_avatar = avatar;
}

INLINE NodePath NametagGroup::get_avatar() {
  return m_avatar;
}

INLINE void NametagGroup::set_name_icon(const NodePath& icon) {
  m_name_icon = icon;
}

INLINE NodePath NametagGroup::get_name_icon() {
  return m_name_icon;
}

INLINE void NametagGroup::set_color_code(NametagGroup::ColorCode code) {
  m_color_code = code;
}

INLINE NametagGroup::ColorCode NametagGroup::get_color_code() {
  return m_color_code;
}

INLINE void NametagGroup::set_contents(int contents) {
  m_contents = contents;
}

INLINE int NametagGroup::get_contents() {
  return m_contents;
}

INLINE std::string NametagGroup::get_display_name() {
  return m_display_name;
}

INLINE void NametagGroup::set_name(const std::string& name) {
  m_name = name;
  set_display_name(name);
}

INLINE std::string NametagGroup::get_name() {
  return m_name;
}

INLINE LVector4f NametagGroup::get_name_frame() {
  return m_name_frame;
}

INLINE void NametagGroup::set_name_wordwrap(float wordwrap) {
  m_wordwrap = wordwrap;
  set_display_name(m_display_name);
}

INLINE Nametag* NametagGroup::get_nametag(int index) {
  return m_nametags[index];
}

INLINE Nametag2d* NametagGroup::get_nametag2d() {
  return m_tag2d;
}

INLINE Nametag3d* NametagGroup::get_nametag3d() {
  return m_tag3d;
}

INLINE int NametagGroup::get_num_nametags() {
  return m_nametags.size();
}

INLINE int NametagGroup::get_page_number() {
  return m_page_number;
}

INLINE int NametagGroup::get_num_chat_pages() {
  return m_chat_pages.size();
}

INLINE void NametagGroup::set_object_code(int code) {
  m_object_code = code;
}

INLINE int NametagGroup::get_object_code() {
  return m_object_code;
}

INLINE void NametagGroup::set_qt_color(LColorf color) {
  m_qt_color = color;
}

INLINE LColorf NametagGroup::get_qt_color() {
  return m_qt_color;
}

INLINE LColorf NametagGroup::get_balloon_modulation_color() {
  return m_balloon_color;
}

INLINE void NametagGroup::set_shadow(LVector2f shadow) {
  m_shadow = shadow;
}

INLINE LVector2f NametagGroup::get_shadow() {
  return m_shadow;
}

INLINE bool NametagGroup::has_shadow() {
  return m_has_shadow;
}

INLINE void NametagGroup::clear_shadow() {
  m_has_shadow = false;
}

INLINE float NametagGroup::get_stomp_delay() {
  return m_stomp_delay;
}

INLINE std::string NametagGroup::get_stomp_text() {
  return m_stomp_text;
}

INLINE void NametagGroup::set_unique_id(const std::string& name) {
  m_unique_name = name;
}

INLINE std::string NametagGroup::get_unique_id() {
  return m_unique_name;
}

INLINE bool NametagGroup::has_button() {
  return !m_is_flashing && will_have_button();
}

INLINE bool NametagGroup::has_no_quit_button() {
  return !m_is_flashing && m_chat_flags & CF_speech;
}

INLINE bool NametagGroup::has_quit_button() {
  return !m_is_flashing && m_chat_flags & CF_quit_button;
}

INLINE bool NametagGroup::has_page_button() {
  return !m_is_flashing && m_chat_flags & CF_page_button;
}

INLINE bool NametagGroup::will_have_button() {
  return m_chat_flags & (CF_page_button | CF_quit_button);
}

INLINE bool NametagGroup::is_managed() {
  return m_manager != nullptr;
}

INLINE void NametagGroup::set_active(bool active) {
  m_is_active = active;
}

INLINE bool NametagGroup::is_active() {
  return m_active;
}

INLINE std::string NametagGroup::get_chat() {
  if (m_chat_pages.size())
    return m_chat_pages[m_page_number];

  return "";
}

INLINE void NametagGroup::clear_chat() {
  set_chat("", 0, 0);
}

INLINE int NametagGroup::get_chat_stomp() {
  return m_chat_stomp;
}

INLINE int NametagGroup::get_chat_flags() {
  return m_chat_flags;
}

INLINE void NametagGroup::set_nametag3d_flag(int flag) {
  m_nametag3d_flag = flag;
}

INLINE void NametagGroup::increment_nametag3d_flag(int flag) {
  if (flag > m_nametag3d_flag)
    m_nametag3d_flag = flag;
}

INLINE int NametagGroup::get_nametag3d_flag() {
  return m_nametag3d_flag;
}

INLINE int NametagGroup::get_region_seq() {
  return m_region_seq;
}

INLINE NodePath NametagGroup::copy_name_to(const NodePath& to) {
  return to.attach_new_node(m_node->copy_subgraph());
}

INLINE bool NametagGroup::display_as_active() {
  if (m_is_active && NametagGlobals::_master_nametags_active)
    return true;

  return has_button();
}
