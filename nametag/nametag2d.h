/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametag2d.h
 * @author loblao
 */

#ifndef NAMETAG2D_H
#define NAMETAG2D_H

#include "nametag.h"
#include "marginPopup.h"

class EXPCL_NAMETAG Nametag2d : public Nametag, public MarginPopup {
PUBLISHED:
  Nametag2d();
  INLINE virtual ~Nametag2d();

  INLINE virtual void set_visible(bool visible);

public:
  virtual bool cull_callback(CullTraverser* trav, CullTraverserData& data);

  INLINE virtual void frame_callback();
  virtual void update_contents();
  INLINE virtual float get_score();
  INLINE virtual int get_object_code();
  virtual bool consider_visible();

  INLINE virtual void manage(PT(MarginManager) manager);
  INLINE virtual void unmanage(PT(MarginManager) manager);

  NAMETAG_REFCOUNT_HACK

protected:
  void rotate_arrow();
  void generate_chat(PT(ChatBalloon) balloon);
  void generate_name();
  INLINE float get_distance2();

  NodePath m_copied_np;
  NodePath m_attached_np;
  NodePath m_arrow;
  NodePath m_unknown_np;
  LVector3f m_trans_vec;
  char m_on;

PUBLISHED:
  static TypeHandle get_class_type() {
    return _type_handle;
  }

public:
  static void init_type() {
    Nametag::init_type();
    MarginPopup::init_type();
    register_type(_type_handle, "Nametag2d",
                  Nametag::get_class_type(),
                  MarginPopup::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "nametag2d.I"

#endif // NAMETAG2D_H
