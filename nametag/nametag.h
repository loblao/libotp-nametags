/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametag.h
 * @author loblao
 */

#ifndef NAMETAG_H
#define NAMETAG_H

#include "clickablePopup.h"
#include "popupMouseWatcherRegion.h"
#include "marginManager.h"
#include "nametagGroup.h"

class EXPCL_NAMETAG Nametag : /*public ReferenceCount,*/ public ClickablePopup {
PUBLISHED:
  enum NametagContents {
    C_name = 1,
    C_speech = 2,
    C_thought = 4
  };

  INLINE virtual ~Nametag();

  INLINE void set_contents(int contents);
  INLINE void set_active(bool active);

  INLINE bool has_group();
  INLINE NametagGroup* get_group();

  INLINE void set_draw_order(int draw_order);
  INLINE void clear_draw_order();

  INLINE void set_chat_wordwrap(float wordwrap);
  INLINE float get_chat_wordwrap();

  INLINE void set_avatar(const NodePath& avatar);
  INLINE NodePath get_avatar();
  INLINE void clear_avatar();

  INLINE bool is_group_managed();

  INLINE virtual void manage(PT(MarginManager) manager);
  INLINE virtual void unmanage(PT(MarginManager) manager);

public:
  virtual PGButton::State get_state();

  void update_region(int seq);

  virtual int get_ref_count() const=0;
  virtual void ref() const=0;
  virtual bool unref() const=0;

protected:
  INLINE Nametag(float wordwrap);
  int determine_contents();
  void deactivate();
  bool display_as_active();
  void set_region(LVector4f& frame, int sort);

  INLINE virtual void click();

  void start_flash(NodePath np);
  void stop_flash();

  int m_chat_contents;
  int m_draw_order;
  bool m_has_draw_order;
  int m_contents;
  int m_active;
  NametagGroup* m_group;
  float m_wordwrap;
  NodePath m_avatar;
  std::string m_ival_name;
  void* m_ival; // XXX TODO
  PT(PopupMouseWatcherRegion) m_popup_region;
  bool m_has_region;
  int m_seq2d;
  PT(MouseWatcher) m_mouse_watcher;

private:
  INLINE void keep_region();

PUBLISHED:
  static TypeHandle get_class_type() {
    return _type_handle;
  }

public:
  static void init_type() {
    ReferenceCount::init_type();
    register_type(_type_handle, "Nametag",
                  ReferenceCount::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;

  friend class NametagGroup;
};

#include "nametag.I"

#endif // NAMETAG_H
