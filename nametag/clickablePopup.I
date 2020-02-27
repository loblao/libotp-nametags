/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file clickablePopup.I
 * @author loblao
 */

INLINE ClickablePopup::ClickablePopup() : m_state(PGButton::S_ready) {
}

INLINE ClickablePopup::~ClickablePopup() {
}

INLINE void ClickablePopup::enter_region(const MouseWatcherParameter& param) {
  if (NametagGlobals::_rollover_sound != nullptr)
    NametagGlobals::_rollover_sound->play();
  set_state(PGButton::S_rollover);
}

INLINE void ClickablePopup::exit_region(const MouseWatcherParameter& param) {
  set_state(PGButton::S_ready);
}

INLINE void ClickablePopup::press(const MouseWatcherParameter& param) {
  if (param.get_button() == MouseButton::one()) {
    if (NametagGlobals::_click_sound != nullptr)
      NametagGlobals::_click_sound->play();
    set_state(PGButton::S_depressed);
  }
}

INLINE void ClickablePopup::release(const MouseWatcherParameter& param) {
  if (param.get_button() == MouseButton::one()) {
    if (param.has_button()) {
      set_state(PGButton::S_ready);
    }
    else {
      set_state(PGButton::S_rollover);
      click();
    }
  }
}

INLINE void ClickablePopup::set_state(PGButton::State state) {
  if (m_state != state) {
    m_state = state;
    update_contents();
  }
}

INLINE PGButton::State ClickablePopup::get_state() {
  return m_state;
}
