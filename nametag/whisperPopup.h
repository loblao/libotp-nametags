/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file whisperPopup.h
 * @author loblao
 */

#ifndef WHISPERPOPUP_H
#define WHISPERPOPUP_H

#include "marginPopup.h"
#include "clickablePopup.h"
#include "marginPopup.h"
#include "popupMouseWatcherRegion.h"

class EXPCL_NAMETAG WhisperPopup : public ClickablePopup, public MarginPopup {
PUBLISHED:
  enum WhisperType {
    WT_normal = 0,
    WT_quick_talker,
    WT_system,
    WT_battle_SOS,
    WT_emote,
    WT_toontown_boarding_group
  };

  WhisperPopup(const std::string& text, PT(TextFont) font, WhisperPopup::WhisperType type);
  INLINE virtual ~WhisperPopup();

  virtual void set_visible(bool visible);
  INLINE void set_clickable(const std::string& avatar_name,
                            int avatar_id,
                            int is_player_id);

  INLINE void manage(PT(MarginManager) manager);
  INLINE void unmanage(PT(MarginManager) manager);

public:
  virtual bool cull_callback(CullTraverser* trav, CullTraverserData& data);

  virtual void update_contents();
  virtual float get_score();
  virtual bool consider_visible();
  virtual bool consider_manage();

protected:
  virtual void click();

private:
  void generate_text(PT(ChatBalloon) balloon,
                     const std::string& text,
                     PT(TextFont) font);
  void set_region(LVector4f& frame, int sort);

  bool m_culled;
  double m_time;
  std::string m_text;
  PT(TextFont) m_font;
  WhisperType m_type;
  NodePath m_np_balloon;
  bool m_clickable;
  std::string m_avname;
  int m_avid;
  int m_is_player_id;
  PT(PopupMouseWatcherRegion) m_region;
  PT(MouseWatcher) m_mouse_watcher;

PUBLISHED:
  static TypeHandle get_class_type() {
    return _type_handle;
  }

public:
  static void init_type() {
    MarginPopup::init_type();
    register_type(_type_handle, "WhisperPopup",
                  MarginPopup::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "whisperPopup.I"

#endif // WHISPERPOPUP_H
