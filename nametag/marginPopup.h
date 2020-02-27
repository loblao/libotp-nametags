/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file marginPopup.h
 * @author loblao
 */

#ifndef MARGINPOPUP_H
#define MARGINPOPUP_H

#include "pandabase.h"
#include "marginManager.h"

class EXPCL_NAMETAG MarginPopup : public PandaNode {
PUBLISHED:
  INLINE virtual ~MarginPopup();

  INLINE float get_cell_width();

  INLINE virtual void set_managed(bool managed);
  INLINE bool is_managed();

  INLINE virtual void set_visible(bool visible);
  INLINE bool is_visible();

public:
  INLINE virtual void frame_callback();
  virtual void update_contents() = 0;
  virtual float get_score() = 0;
  virtual int get_object_code() = 0;
  INLINE virtual bool consider_visible();
  INLINE virtual bool consider_manage();

protected:
  INLINE MarginPopup();

  bool m_managed;
  bool m_visible;
  NodePath m_np;
  float m_cell_width;
  int m_seq;

PUBLISHED:
  static TypeHandle get_class_type() {
    return _type_handle;
  }

public:
  static void init_type() {
    PandaNode::init_type();
    register_type(_type_handle, "MarginPopup",
                  PandaNode::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "marginPopup.I"

#endif // MARGINPOPUP_H
