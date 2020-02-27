/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametagFloat3d.h
 * @author loblao
 */

#ifndef NAMETAGFLOAT3D_H
#define NAMETAGFLOAT3D_H

#include "nametag3d.h"

class EXPCL_NAMETAG NametagFloat3d : public Nametag3d {
PUBLISHED:
  INLINE NametagFloat3d();
  INLINE virtual ~NametagFloat3d();

PUBLISHED:
  static TypeHandle get_class_type() {
    return _type_handle;
  }

public:
  static void init_type() {
    Nametag3d::init_type();
    register_type(_type_handle, "NametagFloat3d",
                  Nametag3d::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "nametagFloat3d.I"

#endif // NAMETAGFLOAT3D_H
