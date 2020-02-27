/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametagGlobals.I
 * @author loblao
 */

INLINE NametagGlobals::NametagGlobals() {
  nassertv(false);
}

INLINE void NametagGlobals::set_speech_balloon_3d(PT(ChatBalloon) value) {
  NametagGlobals::_speech_balloon_3d = value;
}

INLINE PT(ChatBalloon) NametagGlobals::get_speech_balloon_3d() {
  return NametagGlobals::_speech_balloon_3d;
}

INLINE void NametagGlobals::set_global_nametag_scale(float value) {
  NametagGlobals::_global_nametag_scale = value;
}

INLINE float NametagGlobals::get_global_nametag_scale() {
  return NametagGlobals::_global_nametag_scale;
}

INLINE void NametagGlobals::set_camera(const NodePath& value) {
  NametagGlobals::_camera = value;
}

INLINE NodePath NametagGlobals::get_camera() {
  return NametagGlobals::_camera;
}

INLINE void NametagGlobals::set_master_nametags_active(bool value) {
  NametagGlobals::_master_nametags_active = value;
}

INLINE bool NametagGlobals::get_master_nametags_active() {
  return NametagGlobals::_master_nametags_active;
}

INLINE void NametagGlobals::set_min_2d_alpha(float value) {
  NametagGlobals::_min_2d_alpha = value;
  NametagGlobals::_margin_prop_seq++;
}

INLINE float NametagGlobals::get_min_2d_alpha() {
  return NametagGlobals::_min_2d_alpha;
}

INLINE void NametagGlobals::set_mouse_watcher(PT(MouseWatcher) value) {
  NametagGlobals::_mouse_watcher = value;
}

INLINE PT(MouseWatcher) NametagGlobals::get_mouse_watcher() {
  return NametagGlobals::_mouse_watcher;
}

INLINE void NametagGlobals::set_master_arrows_on(bool value) {
  NametagGlobals::_master_arrows_on = value;
}

INLINE bool NametagGlobals::get_master_arrows_on() {
  return NametagGlobals::_master_arrows_on;
}

INLINE void NametagGlobals::set_toon(const NodePath& value) {
  NametagGlobals::_toon = value;
}

INLINE NodePath NametagGlobals::get_toon() {
  return NametagGlobals::_toon;
}

INLINE void NametagGlobals::set_master_nametags_visible(bool value) {
  NametagGlobals::_master_nametags_visible = value;
}

INLINE bool NametagGlobals::get_master_nametags_visible() {
  return NametagGlobals::_master_nametags_visible;
}

INLINE void NametagGlobals::set_thought_balloon_2d(PT(ChatBalloon) value) {
  NametagGlobals::_thought_balloon_2d = value;
}

INLINE PT(ChatBalloon) NametagGlobals::get_thought_balloon_2d() {
  return NametagGlobals::_thought_balloon_2d;
}

INLINE void NametagGlobals::set_max_2d_alpha(float value) {
  NametagGlobals::_max_2d_alpha = value;
  NametagGlobals::_margin_prop_seq++;
}

INLINE float NametagGlobals::get_max_2d_alpha() {
  return NametagGlobals::_max_2d_alpha;
}

INLINE void NametagGlobals::set_onscreen_chat_forced(bool value) {
  NametagGlobals::_onscreen_chat_forced = value;
}

INLINE bool NametagGlobals::get_onscreen_chat_forced() {
  return NametagGlobals::_onscreen_chat_forced;
}

INLINE void NametagGlobals::set_nametag_card(const NodePath& value, LVector4f frame) {
  NametagGlobals::_nametag_card = value;
  NametagGlobals::_nametag_card_frame = frame;
}

INLINE NodePath NametagGlobals::get_nametag_card() {
  return NametagGlobals::_nametag_card;
}

INLINE LVector4f NametagGlobals::get_nametag_card_frame() {
  return NametagGlobals::_nametag_card_frame;
}

INLINE void NametagGlobals::set_rollover_sound(PT(AudioSound) value) {
  NametagGlobals::_rollover_sound = value;
}

INLINE PT(AudioSound) NametagGlobals::get_rollover_sound() {
  return NametagGlobals::_rollover_sound;
}

INLINE void NametagGlobals::set_click_sound(PT(AudioSound) value) {
  NametagGlobals::_click_sound = value;
}

INLINE PT(AudioSound) NametagGlobals::get_click_sound() {
  return NametagGlobals::_click_sound;
}

INLINE void NametagGlobals::set_speech_balloon_2d(PT(ChatBalloon) value) {
  NametagGlobals::_speech_balloon_2d = value;
}

INLINE PT(ChatBalloon) NametagGlobals::get_speech_balloon_2d() {
  return NametagGlobals::_speech_balloon_2d;
}

INLINE PT(TextNode) NametagGlobals::get_text_node() {
  if (NametagGlobals::_text_node == nullptr)
    NametagGlobals::_text_node = new TextNode("nametag");

  return NametagGlobals::_text_node;
}

INLINE void NametagGlobals::set_quit_button(PGButton::State state, NodePath value) {
  NametagGlobals::_quit_button[state] = value;
}

INLINE NodePath NametagGlobals::get_quit_button(PGButton::State state) {
  return NametagGlobals::_quit_button[state];
}

INLINE void NametagGlobals::set_page_button(PGButton::State state, NodePath value) {
  NametagGlobals::_page_button[state] = value;
}

INLINE NodePath NametagGlobals::get_page_button(PGButton::State state) {
  return NametagGlobals::_page_button[state];
}

INLINE void NametagGlobals::set_arrow_model(const NodePath& value) {
  NametagGlobals::_arrow_model = value;
}

INLINE NodePath NametagGlobals::get_arrow_model() {
  return NametagGlobals::_arrow_model;
}

INLINE void NametagGlobals::set_thought_balloon_3d(PT(ChatBalloon) value) {
  NametagGlobals::_thought_balloon_3d = value;
}

INLINE PT(ChatBalloon) NametagGlobals::get_thought_balloon_3d() {
  return NametagGlobals::_thought_balloon_3d;
}

INLINE void NametagGlobals::set_balloon_modulation_color(LColorf value) {
  NametagGlobals::_balloon_modulation_color = value;
}

INLINE LColorf NametagGlobals::get_balloon_modulation_color() {
  return NametagGlobals::_balloon_modulation_color;
}

INLINE float NametagGlobals::get_name_wordwrap() {
  return 7.5;
}

INLINE LVector4f NametagGlobals::get_card_pad() {
  return NametagGlobals::_card_pad;
}
