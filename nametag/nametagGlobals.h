/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametagGlobals.h
 * @author loblao
 */

#ifndef NAMETAGGLOBALS_H
#define NAMETAGGLOBALS_H

#include "config_nametag.h"
#include "chatBalloon.h"
#include "mouseWatcher.h"
#include "audioSound.h"
#include "textNode.h"
#include "pgButton.h"

class EXPCL_NAMETAG NametagGlobals {
PUBLISHED:
  INLINE static void set_speech_balloon_3d(PT(ChatBalloon) value);
  INLINE static PT(ChatBalloon) get_speech_balloon_3d();

  INLINE static void set_global_nametag_scale(float value);
  INLINE static float get_global_nametag_scale();

  INLINE static void set_camera(const NodePath& value);
  INLINE static NodePath get_camera();

  INLINE static void set_master_nametags_active(bool value);
  INLINE static bool get_master_nametags_active();

  INLINE static void set_min_2d_alpha(float value);
  INLINE static float get_min_2d_alpha();

  INLINE static void set_mouse_watcher(PT(MouseWatcher) value);
  INLINE static PT(MouseWatcher) get_mouse_watcher();

  INLINE static void set_master_arrows_on(bool value);
  INLINE static bool get_master_arrows_on();

  INLINE static void set_toon(const NodePath& value);
  INLINE static NodePath get_toon();

  INLINE static void set_master_nametags_visible(bool value);
  INLINE static bool get_master_nametags_visible();

  INLINE static void set_thought_balloon_2d(PT(ChatBalloon) value);
  INLINE static PT(ChatBalloon) get_thought_balloon_2d();

  INLINE static void set_max_2d_alpha(float value);
  INLINE static float get_max_2d_alpha();

  INLINE static void set_onscreen_chat_forced(bool value);
  INLINE static bool get_onscreen_chat_forced();

  INLINE static void set_nametag_card(const NodePath& value, LVector4f frame);
  INLINE static NodePath get_nametag_card();
  INLINE static LVector4f get_nametag_card_frame();

  INLINE static void set_rollover_sound(PT(AudioSound) value);
  INLINE static PT(AudioSound) get_rollover_sound();

  INLINE static void set_click_sound(PT(AudioSound) value);
  INLINE static PT(AudioSound) get_click_sound();

  INLINE static void set_speech_balloon_2d(PT(ChatBalloon) value);
  INLINE static PT(ChatBalloon) get_speech_balloon_2d();

  INLINE static PT(TextNode) get_text_node();

  INLINE static void set_quit_button(PGButton::State state, NodePath value);
  INLINE static NodePath get_quit_button(PGButton::State state);

  INLINE static void set_page_button(PGButton::State state, NodePath value);
  INLINE static NodePath get_page_button(PGButton::State state);

  INLINE static void set_arrow_model(const NodePath& value);
  INLINE static NodePath get_arrow_model();

  INLINE static void set_thought_balloon_3d(PT(ChatBalloon) value);
  INLINE static PT(ChatBalloon) get_thought_balloon_3d();

  INLINE static void set_balloon_modulation_color(LColorf value);
  INLINE static LColorf get_balloon_modulation_color();

  INLINE static float get_name_wordwrap();
  INLINE static LVector4f get_card_pad();

  static LColorf get_arrow_color(int color_code);
  static LColorf get_name_bg(int color_code, PGButton::State state);
  static LColorf get_name_fg(int color_code, PGButton::State state);
  static LColorf get_whisper_bg(int color_code, PGButton::State state);
  static LColorf get_whisper_fg(int color_code, PGButton::State state);
  static LColorf get_chat_bg(int color_code, PGButton::State state);
  static LColorf get_chat_fg(int color_code, PGButton::State state);

private:
  INLINE NametagGlobals();

public:
  static PT(ChatBalloon) _speech_balloon_3d;
  static float _global_nametag_scale;
  static NodePath _camera;
  static bool _master_nametags_active;
  static float _min_2d_alpha;
  static PT(MouseWatcher) _mouse_watcher;
  static bool _master_arrows_on;
  static NodePath _toon;
  static bool _master_nametags_visible;
  static PT(ChatBalloon) _thought_balloon_2d;
  static float _max_2d_alpha;
  static bool _onscreen_chat_forced;
  static NodePath _nametag_card;
  static LVector4f _nametag_card_frame;
  static PT(AudioSound) _rollover_sound;
  static PT(AudioSound) _click_sound;
  static PT(ChatBalloon) _speech_balloon_2d;
  static PT(TextNode) _text_node;
  static NodePath _quit_button[4];
  static NodePath _page_button[4];
  static NodePath _arrow_model;
  static PT(ChatBalloon) _thought_balloon_3d;
  static LColor _balloon_modulation_color;
  static LVector4f _card_pad;
  static int _margin_prop_seq;
  static LVector4f _default_qt_color;
  static LPoint3f _balloon_text_origin;
};

#include "nametagGlobals.I"

#endif // NAMETAGGLOBALS_H
