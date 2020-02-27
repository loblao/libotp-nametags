/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametag3d.I
 * @author loblao
 */

INLINE Nametag3d::~Nametag3d() {
  if (!m_np_top.is_empty())
    m_np_top.remove_node();

  if (!m_np_360.is_empty())
    m_np_360.remove_node();

  if (!m_np_372.is_empty())
    m_np_372.remove_node();

  if (!m_np_balloon.is_empty())
    m_np_balloon.remove_node();
}

INLINE void Nametag3d::set_billboard_offset(float offset) {
  m_billboard_offset = offset;
}

INLINE float Nametag3d::get_billboard_offset() {
  return m_billboard_offset;
}

INLINE bool Nametag3d::safe_to_flatten_below() const {
  return false;
}

INLINE void Nametag3d::release(const MouseWatcherParameter& param) {
  if (param.get_button() == MouseButton::one()) {
    this->Nametag::set_state(PGButton::S_rollover);
    click();
  }
}

INLINE void Nametag3d::manage(PT(MarginManager) manager) {
  m_np_top.reparent_to(NodePath::any_path(this));
  Nametag::manage(manager);
}

INLINE void Nametag3d::unmanage(PT(MarginManager) manager) {
  m_np_top.detach_node();
  Nametag::unmanage(manager);
}
