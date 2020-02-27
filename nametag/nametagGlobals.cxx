/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametagGlobals.cxx
 * @author loblao
 */

#include "nametagGlobals.h"

PT(ChatBalloon) NametagGlobals::_speech_balloon_3d = nullptr;
float NametagGlobals::_global_nametag_scale = 1.0;
NodePath NametagGlobals::_camera = NodePath();
bool NametagGlobals::_master_nametags_active = true;
float NametagGlobals::_min_2d_alpha = 0.0;
PT(MouseWatcher) NametagGlobals::_mouse_watcher = nullptr;
bool NametagGlobals::_master_arrows_on = true;
NodePath NametagGlobals::_toon = NodePath();
bool NametagGlobals::_master_nametags_visible = true;
PT(ChatBalloon) NametagGlobals::_thought_balloon_2d = nullptr;
float NametagGlobals::_max_2d_alpha = 0.6;
bool NametagGlobals::_onscreen_chat_forced = false;
NodePath NametagGlobals::_nametag_card = NodePath();
LVector4f NametagGlobals::_nametag_card_frame = LVector4f(0, 0, 0, 0);
PT(AudioSound) NametagGlobals::_rollover_sound = nullptr;
PT(AudioSound) NametagGlobals::_click_sound = nullptr;
PT(ChatBalloon) NametagGlobals::_speech_balloon_2d = nullptr;
PT(TextNode) NametagGlobals::_text_node = nullptr;
NodePath NametagGlobals::_quit_button[4] = {NodePath()};
NodePath NametagGlobals::_page_button[4] = {NodePath()};
NodePath NametagGlobals::_arrow_model = NodePath();
PT(ChatBalloon) NametagGlobals::_thought_balloon_3d = nullptr;
LColor NametagGlobals::_balloon_modulation_color = LVector4f(1.0, 1.0, 1.0, 1.0);
LVector4f NametagGlobals::_card_pad = LVector4f(0.1, 0.1, 0.1, 0);
int NametagGlobals::_margin_prop_seq = 0;
LVector4f NametagGlobals::_default_qt_color = LVector4f(0.8, 0.8, 1, 1);
LPoint3f NametagGlobals::_balloon_text_origin = LPoint3f(1.0, 0, 2.0);

LColorf NametagGlobals::get_arrow_color(int color_code) {
  LColorf _colors[9] = {
    LColorf(1.0, 0.40000001, 0.2, 1.0),
    LColorf(1.0, 0.40000001, 0.2, 1.0),
    LColorf(1.0, 0.40000001, 0.2, 1.0),
    LColorf(1.0, 0.40000001, 0.2, 1.0),
    LColorf(0.30000001, 0.60000002, 1.0, 1.0),
    LColorf(0.55000001, 0.55000001, 0.55000001, 1.0),
    LColorf(0.30000001, 0.60000002, 1.0, 1.0),
    LColorf(0.30000001, 0.69999999, 0.30000001, 1.0),
    LColorf(0.30000001, 0.30000001, 0.69999999, 1.0)
  };
  return _colors[color_code];
}

LColorf NametagGlobals::get_name_bg(int color_code, PGButton::State state) {
  LColorf _colors[36] = {
    // CCNormal
    LColorf(0.8, 0.8, 0.8, 0.5),
    LColorf(0.2, 0.2, 0.2, 0.6),
    LColorf(1, 1, 1, 1),
    LColorf(0.8, 0.8, 0.8, 0.5),

    // CCNoChat
    LColorf(1, 1, 1, 0.5),
    LColorf(0.2, 0.2, 0.2, 0.6),
    LColorf(1, 1, 1, 1),
    LColorf(0.8, 0.8, 0.8, 0.5),

    // CCNonPlayer
    LColorf(1, 1, 1, 0.5),
    LColorf(0.2, 0.2, 0.2, 0.6),
    LColorf(1, 1, 1, 1),
    LColorf(0.8, 0.8, 0.8, 0.5),

    // CCSuit
    LColorf(0.8, 0.8, 0.8, 0.5),
    LColorf(0.2, 0.2, 0.2, 0.6),
    LColorf(1, 1, 1, 1),
    LColorf(0.8, 0.8, 0.8, 0.5),

    // CCToonBuilding
    LColorf(0.8, 0.8, 0.8, 0.5),
    LColorf(0.2, 0.2, 0.2, 0.6),
    LColorf(1, 1, 1, 1),
    LColorf(0.8, 0.8, 0.8, 0.5),

    // CCSuitBuilding
    LColorf(0.8, 0.8, 0.8, 0.5),
    LColorf(0.2, 0.2, 0.2, 0.6),
    LColorf(1, 1, 1, 1),
    LColorf(0.8, 0.8, 0.8, 0.5),

    // CCHouseBuilding
    LColorf(0.8, 0.8, 0.8, 0.5),
    LColorf(0.2, 0.2, 0.2, 0.6),
    LColorf(1, 1, 1, 1),
    LColorf(0.8, 0.8, 0.8, 0.5),

    // CCSpeedChat
    LColorf(1, 1, 1, 0.5),
    LColorf(0.2, 0.2, 0.2, 0.6),
    LColorf(1, 1, 1, 1),
    LColorf(0.8, 0.8, 0.8, 0.5),

    // CCFreeChat
    LColorf(0.8, 0.8, 0.8, 0.5),
    LColorf(0.2, 0.2, 0.2, 0.6),
    LColorf(1, 1, 1, 1),
    LColorf(0.8, 0.8, 0.8, 0.5)
  };
  return _colors[4 * color_code + state];
}

LColorf NametagGlobals::get_name_fg(int color_code, PGButton::State state) {
  LColorf _colors[36] = {
    // CCNormal
    LColorf(0, 0, 1, 1),
    LColorf(0.5, 0.5, 1, 1),
    LColorf(0.5, 0.5, 1, 1),
    LColorf(0.3, 0.3, 0.7, 1),

    // CCNoChat
    LColorf(0.8, 0.4, 0, 1),
    LColorf(1, 0.5, 0.5, 1),
    LColorf(1, 0.5, 0, 1),
    LColorf(0.6, 0.4, 0.2, 1),

    // CCNonPlayer
    LColorf(0.8, 0.4, 0, 1),
    LColorf(1, 0.5, 0.5, 1),
    LColorf(1, 0.5, 0, 1),
    LColorf(0.6, 0.4, 0.2, 1),

    // CCSuit
    LColorf(0, 0, 0, 1),
    LColorf(1, 1, 1, 1),
    LColorf(0.5, 0.5, 0.5, 1),
    LColorf(0.2, 0.2, 0.2, 1),

    // CCToonBuilding
    LColorf(0, 0, 0, 1),
    LColorf(1, 1, 1, 1),
    LColorf(0.5, 0.5, 0.5, 1),
    LColorf(0.3, 0.6, 1, 1),

    // CCSuitBuilding
    LColorf(0, 0, 0, 1),
    LColorf(1, 1, 1, 1),
    LColorf(0.5, 0.5, 0.5, 1),
    LColorf(0.55, 0.55, 0.55, 1),

    // CCHouseBuilding
    LColorf(0, 0, 0, 1),
    LColorf(1, 1, 1, 1),
    LColorf(0.5, 0.5, 0.5, 1),
    LColorf(0.3, 0.6, 1, 1),

    // CCSpeedChat
    LColorf(0, 0.6, 0.2, 1),
    LColorf(0, 0.6, 0.2, 1),
    LColorf(0, 1, 0.5, 1),
    LColorf(0.1, 0.4, 0.2, 1),

    // CCFreeChat
    LColorf(0.3, 0.3, 0.7, 1),
    LColorf(0.2, 0.2, 0.5, 1),
    LColorf(0.5, 0.5, 1, 1),
    LColorf(0.3, 0.3, 0.7, 1)
  };
  return _colors[4 * color_code + state];
}

typedef LColorf color_pair_t[2];
typedef color_pair_t color_set_t[4];

color_set_t _whisper_colors[9] = {
  {
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.3, 0.6, 0.8, 0.6)},
    {LColorf(1.0, 0.5, 0.5, 1.0), LColorf(1.0, 1.0, 1.0, 1.0)},
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.4, 0.8, 1.0, 1.0)},
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.3, 0.6, 0.8, 0.6)}
  },
  {
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.3, 0.6, 0.8, 0.6)},
    {LColorf(1.0, 0.5, 0.5, 1.0), LColorf(1.0, 1.0, 1.0, 1.0)},
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.4, 0.8, 1.0, 1.0)},
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.3, 0.6, 0.8, 0.6)}
  },
  {
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.8, 0.3, 0.6, 0.6)},
    {LColorf(1.0, 0.5, 0.5, 1.0), LColorf(1.0, 1.0, 1.0, 1.0)},
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.8, 0.4, 1.0, 1.0)},
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.8, 0.3, 0.6, 0.6)}
  },
  {
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.8, 0.3, 0.6, 0.6)},
    {LColorf(1.0, 0.5, 0.5, 1.0), LColorf(1.0, 1.0, 1.0, 1.0)},
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.8, 0.4, 1.0, 1.0)},
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.8, 0.3, 0.6, 0.6)}
  },
  {
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.3, 0.6, 0.8, 0.6)},
    {LColorf(1.0, 0.5, 0.5, 1.0), LColorf(1.0, 1.0, 1.0, 1.0)},
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.4, 1.0, 1.0, 0.4)},
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.3, 0.8, 0.3, 0.6)}
  },
  {
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.97, 0.43, 0.1, 0.6)},
    {LColorf(1.0, 0.5, 0.5, 1.0), LColorf(1.0, 1.0, 1.0, 1.0)},
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.98, 0.6, 0.38, 0.6)},
    {LColorf(0.0, 0.0, 0.0, 1.0), LColorf(0.97, 0.43, 0.1, 0.6)}
  }
};

LColorf NametagGlobals::get_whisper_bg(int color_code, PGButton::State state) {
  return _whisper_colors[color_code][state][1];
}

LColorf NametagGlobals::get_whisper_fg(int color_code, PGButton::State state) {
  return _whisper_colors[color_code][state][0];
}

LColorf NametagGlobals::get_chat_fg(int color_code, PGButton::State state) {
  LColorf _colors[4] = {
    LColorf(0.0, 0.0, 0.0, 1.0),
    LColorf(1.0, 0.5, 0.5, 1.0),
    LColorf(0.0, 0.6, 0.6, 1.0),
    LColorf(0.0, 0.0, 0.0, 1.0)
  };
  return _colors[state];
}

LColorf NametagGlobals::get_chat_bg(int color_code, PGButton::State state) {
  return LColorf(1.0, 1.0, 1.0, 1.0);
}
