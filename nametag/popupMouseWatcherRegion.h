/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file popupMouseWatcherRegion.h
 * @author loblao
 */

#ifndef POPUPMOUSEWATCHERREGION_H
#define POPUPMOUSEWATCHERREGION_H

#include "mouseWatcherRegion.h"

class EXPCL_NAMETAG PopupMouseWatcherRegion : public MouseWatcherRegion {
PUBLISHED:
  INLINE virtual ~PopupMouseWatcherRegion();

public:
  INLINE PopupMouseWatcherRegion(ClickablePopup* popup,
                                 const std::string& name,
                                 LVector4f& frame);
  INLINE virtual void enter_region(const MouseWatcherParameter& param);
  INLINE virtual void exit_region(const MouseWatcherParameter& param);
  INLINE virtual void press(const MouseWatcherParameter& param);
  INLINE virtual void release(const MouseWatcherParameter& param);

private:
  ClickablePopup* m_popup;

PUBLISHED:
  static TypeHandle get_class_type() {
    return _type_handle;
  }

public:
  static void init_type() {
    MouseWatcherRegion::init_type();
    register_type(_type_handle, "PopupMouseWatcherRegion",
                  MouseWatcherRegion::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "popupMouseWatcherRegion.I"

#endif // POPUPMOUSEWATCHERREGION_H
