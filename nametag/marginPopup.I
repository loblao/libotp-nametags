/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file marginPopup.I
 * @author loblao
 */

#include "marginPopup.h"

INLINE MarginPopup::MarginPopup() : PandaNode("MarginPopup"),
    m_managed(false), m_visible(false), m_np(NodePath()),
    m_cell_width(1.0), m_seq(NametagGlobals::_margin_prop_seq) {
}

INLINE MarginPopup::~MarginPopup() {
}

INLINE float MarginPopup::get_cell_width() {
  return m_cell_width;
}

INLINE void MarginPopup::set_managed(bool managed) {
  m_managed = managed;
  m_np = managed ? NodePath::any_path(this) : NodePath();
}

INLINE bool MarginPopup::is_managed() {
  return m_managed;
}

INLINE void MarginPopup::set_visible(bool visible) {
  m_visible = visible;
}

INLINE bool MarginPopup::is_visible() {
  return m_visible;
}

INLINE void MarginPopup::frame_callback() {
  update_contents();
}

INLINE bool MarginPopup::consider_visible() {
  if (m_seq != NametagGlobals::_margin_prop_seq) {
    m_seq = NametagGlobals::_margin_prop_seq;
    update_contents();
  }

  return true;
}

INLINE bool MarginPopup::consider_manage() {
  return true;
}
