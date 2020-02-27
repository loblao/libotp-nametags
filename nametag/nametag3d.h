/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametag3d.h
 * @author loblao
 */

#ifndef NAMETAG3D_H
#define NAMETAG3D_H

#include "nametag.h"

class EXPCL_NAMETAG Nametag3d : public Nametag, public PandaNode {
PUBLISHED:
  Nametag3d();
  INLINE virtual ~Nametag3d();

  INLINE void set_billboard_offset(float offset);
  INLINE float get_billboard_offset();

public:
  INLINE virtual bool safe_to_flatten_below() const;
  virtual bool cull_callback(CullTraverser* trav, CullTraverserData& data);

  INLINE virtual void release(const MouseWatcherParameter& param);
  virtual void update_contents();

  INLINE virtual void manage(PT(MarginManager) manager);
  INLINE virtual void unmanage(PT(MarginManager) manager);

  NAMETAG_REFCOUNT_HACK

protected:
  void adjust_to_camera(NodePath np, int sort);
  void generate_chat(PT(ChatBalloon) balloon);
  void generate_name();

  bool m_is_3d;
  float m_billboard_offset;
  NodePath m_np_top;
  NodePath m_np_360;
  NodePath m_np_372;
  NodePath m_np_balloon;
  int m_field_396;
  LVector4f m_name_frame;

PUBLISHED:
  static TypeHandle get_class_type() {
    return _type_handle;
  }

public:
  static void init_type() {
    Nametag::init_type();
    PandaNode::init_type();
    register_type(_type_handle, "Nametag3d",
                  Nametag::get_class_type(),
                  PandaNode::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "nametag3d.I"

#endif // NAMETAG3D_H
