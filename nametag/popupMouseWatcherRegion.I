/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file popupMouseWatcherRegion.I
 * @author loblao
 */

INLINE PopupMouseWatcherRegion::PopupMouseWatcherRegion(ClickablePopup* popup,
                                                        const std::string& name,
                                                        LVector4f& frame) : MouseWatcherRegion(name, frame),
    m_popup(popup) {
}


INLINE PopupMouseWatcherRegion::~PopupMouseWatcherRegion() {
  m_popup = nullptr;
}

INLINE void PopupMouseWatcherRegion::enter_region(const MouseWatcherParameter& param) {
  if (m_popup != nullptr)
    m_popup->enter_region(param);
}

INLINE void PopupMouseWatcherRegion::exit_region(const MouseWatcherParameter& param) {
  if (m_popup != nullptr)
    m_popup->exit_region(param);
}

INLINE void PopupMouseWatcherRegion::press(const MouseWatcherParameter& param) {
  if (m_popup != nullptr)
    m_popup->press(param);
}

INLINE void PopupMouseWatcherRegion::release(const MouseWatcherParameter& param) {
  if (m_popup != nullptr)
    m_popup->release(param);
}
