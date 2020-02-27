/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametag.cxx
 * @author mfwass
 * @author loblao
 */

#include "nametag.h"

TypeHandle Nametag::_type_handle;

void Nametag::start_flash(NodePath np) {
  // XXX TODO
}

void Nametag::stop_flash() {
  // XXX TODO
}

PGButton::State Nametag::get_state() {
  if (has_group()) {
    if (!(m_active && m_group->display_as_active()))
      return PGButton::S_inactive;
  }

  else if (!(m_active && NametagGlobals::_master_nametags_active))
    return PGButton::S_inactive;

  return m_state;
}

void Nametag::deactivate() {
  if (m_has_region) {
    if (m_mouse_watcher != nullptr) {
      m_mouse_watcher->remove_region(m_popup_region);
      m_mouse_watcher = nullptr;
    }

    m_has_region = false;
  }

  m_seq2d = 0;
}

bool Nametag::display_as_active() {
  if (!m_active)
    return false;

  if (has_group())
    return m_group->display_as_active();

  return NametagGlobals::_master_nametags_active;
}

int Nametag::determine_contents() {
  if (is_group_managed()) {
    int v3 = m_contents & m_group->get_contents();
    int v4 = m_group->get_chat_flags();

    if (v4 & CF_speech) {
      if (v3 & Nametag::C_speech)
        return Nametag::C_speech;
    }

    else if ((v4 & CF_thought) && (v3 & Nametag::C_thought))
      return Nametag::C_thought;

    if (v3 & Nametag::C_name && m_group->get_name().size() && NametagGlobals::_master_nametags_visible)
      return Nametag::C_name;
  }

  return 0;
}

void Nametag::set_region(LVector4f& frame, int sort) {
  if (m_popup_region != nullptr)
    m_popup_region->set_frame(frame);

  else {
    std::string v7 = get_type().get_name() + "-" + m_group->get_name();
    m_popup_region = new PopupMouseWatcherRegion(this, v7, frame);
  }

  m_popup_region->set_sort(sort);
  m_seq2d = m_group->get_region_seq();
}

void Nametag::update_region(int seq) {
  bool is_active = (seq == m_seq2d) && display_as_active();

  if (m_has_region) {
    if (m_mouse_watcher != NametagGlobals::_mouse_watcher) {
      if (m_mouse_watcher != nullptr)
        m_mouse_watcher->remove_region(m_popup_region);

      m_has_region = false;
      set_state(PGButton::S_ready);
    }
  }

  if (is_active) {
    if (!m_has_region && m_popup_region != nullptr) {
      if (m_mouse_watcher != NametagGlobals::_mouse_watcher)
        m_mouse_watcher = NametagGlobals::_mouse_watcher;

      if (m_mouse_watcher != nullptr)
        m_mouse_watcher->add_region(m_popup_region);

      m_has_region = true;
    }
  }

  else if (m_has_region) {
    if (m_mouse_watcher != nullptr && m_popup_region != nullptr)
      m_mouse_watcher->remove_region(m_popup_region);

    m_has_region = false;
    m_mouse_watcher = nullptr;
    set_state(PGButton::S_ready);
  }
}
