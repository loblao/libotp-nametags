/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file clickablePopup.h
 * @author loblao
 */

#ifndef CLICKABLEPOPUP_H
#define CLICKABLEPOPUP_H

#include "config_nametag.h"
#include "nametagGlobals.h"
#include "mouseWatcherParameter.h"
#include "mouseButton.h"
#include "pgButton.h"

class EXPCL_NAMETAG ClickablePopup {
PUBLISHED:
  INLINE ClickablePopup();
  INLINE virtual ~ClickablePopup();

public:
  INLINE virtual void enter_region(const MouseWatcherParameter& param);
  INLINE virtual void exit_region(const MouseWatcherParameter& param);
  INLINE virtual void press(const MouseWatcherParameter& param);
  INLINE virtual void release(const MouseWatcherParameter& param);

  INLINE virtual void set_state(PGButton::State state);
  INLINE virtual PGButton::State get_state();

  virtual void update_contents() = 0;

protected:
  virtual void click() = 0;

  PGButton::State m_state;

PUBLISHED:
  static TypeHandle get_class_type() {
    return _type_handle;
  }

public:
  static void init_type() {
    register_type(_type_handle, "ClickablePopup");
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "clickablePopup.I"

#endif // CLICKABLEPOPUP_H
