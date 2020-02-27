/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametagFloat2d.h
 * @author loblao
 */

#ifndef NAMETAGFLOAT2D_H
#define NAMETAGFLOAT2D_H

#include "nametag3d.h"

class EXPCL_NAMETAG NametagFloat2d : public Nametag3d {
PUBLISHED:
  INLINE NametagFloat2d();
  INLINE virtual ~NametagFloat2d();

PUBLISHED:
  static TypeHandle get_class_type() {
    return _type_handle;
  }

public:
  static void init_type() {
    Nametag3d::init_type();
    register_type(_type_handle, "NametagFloat2d",
                  Nametag3d::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "nametagFloat2d.I"

#endif // NAMETAGFLOAT2D_H
