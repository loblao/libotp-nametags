/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file whisperPopup.I
 * @author loblao
 */


INLINE WhisperPopup::~WhisperPopup() {
}

INLINE void WhisperPopup::set_clickable(const std::string& avatar_name,
                                        int avatar_id,
                                        int is_player_id) {
  m_clickable = true;
  m_avname = avatar_name;
  m_avid = avatar_id;
  m_is_player_id = is_player_id;
  m_state = PGButton::S_ready;
}

INLINE void WhisperPopup::manage(PT(MarginManager) manager) {
  manager->manage_popup(this);
}

INLINE void WhisperPopup::unmanage(PT(MarginManager) manager) {
  manager->unmanage_popup(this);
}
