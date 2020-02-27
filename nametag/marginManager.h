/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file marginManager.h
 * @author loblao
 */

#ifndef MARGINMANAGER_H
#define MARGINMANAGER_H

#include "config_nametag.h"

class MarginPopup; // TODO

// XXX TODO: this class is incomplete
class EXPCL_NAMETAG MarginManager : public PandaNode {
PUBLISHED:
  MarginManager();
  INLINE virtual ~MarginManager();

  INLINE void add_grid_cell(float x, float y,
                            float screen_left,
                            float screen_right,
                            float screen_bottom,
                            float screen_top);

public:
  virtual bool cull_callback(CullTraverser* trav, CullTraverserData& data);
  virtual bool is_renderable() const;

  void manage_popup(PT(MarginPopup) popup);
  void unmanage_popup(PT(MarginPopup) popup);

private:
  void update();

  pset<PT(MarginPopup)> m_popups;

PUBLISHED:
  static TypeHandle get_class_type() {
    return _type_handle;
  }

public:
  static void init_type() {
    PandaNode::init_type();
    register_type(_type_handle, "MarginManager",
                  PandaNode::get_class_type());
  }
  virtual TypeHandle get_type() const {
    return get_class_type();
  }
  virtual TypeHandle force_init_type() {init_type(); return get_class_type();}

private:
  static TypeHandle _type_handle;
};

#include "marginManager.I"

#endif // MARGINMANAGER_H
