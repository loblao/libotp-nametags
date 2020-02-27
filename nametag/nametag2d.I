/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametag2d.I
 * @author loblao
 */

INLINE Nametag2d::~Nametag2d() {
  stop_flash();

  if (!m_copied_np.is_empty())
      m_copied_np.remove_node();

  if (!m_attached_np.is_empty())
      m_attached_np.remove_node();

  if (!m_arrow.is_empty())
      m_arrow.remove_node();

  if (!m_unknown_np.is_empty())
      m_unknown_np.remove_node();
}

INLINE void Nametag2d::set_visible(bool visible) {
  MarginPopup::set_visible(visible);
  update_contents();
}

INLINE void Nametag2d::frame_callback() {
  if (m_visible && m_popup_region != nullptr)
    m_seq2d = m_group->get_region_seq();

  if (has_group())
    m_group->update_regions();
}

INLINE float Nametag2d::get_score() {
  if (m_group != nullptr)
      return 1000.0 - get_distance2();

  return 0.0;
}

INLINE int Nametag2d::get_object_code() {
  return has_group() ? m_group->get_object_code() : 0;
}

INLINE void Nametag2d::manage(PT(MarginManager) manager) {
  Nametag::manage(manager);
  manager->manage_popup(this);
}

INLINE void Nametag2d::unmanage(PT(MarginManager) manager) {
  Nametag::unmanage(manager);
  manager->unmanage_popup(this);
}

INLINE float Nametag2d::get_distance2() {
  NodePath np = m_avatar.is_empty() ? m_group->get_avatar() : m_avatar;
  if (np.is_empty())
    return 0;

  return np.get_pos(NametagGlobals::_toon).length_squared();
}
