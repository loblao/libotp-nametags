/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file marginManager.cxx
 * @author loblao
 */

#include "marginManager.h"
#include "marginPopup.h"
#include "omniBoundingVolume.h"

TypeHandle MarginManager::_type_handle;

MarginManager::MarginManager() : PandaNode("popups") {
  // XXX TODO: this is incomplete
  set_cull_callback();

  set_bounds(new OmniBoundingVolume());
}

bool MarginManager::cull_callback(CullTraverser* trav, CullTraverserData& data) {
  update();
  return true;
}

bool MarginManager::is_renderable() const {
  return true;
}

void MarginManager::manage_popup(PT(MarginPopup) popup) {
  // XXX TODO: objcode, handle
  popup->set_managed(true);
  m_popups.insert(popup);
}

void MarginManager::unmanage_popup(PT(MarginPopup) popup) {
  // XXX TODO: objcode, handle
  m_popups.erase(popup);
  popup->set_managed(false);
}

void MarginManager::update() {
  // XXX TODO: this is incomplete
  for (auto popup : m_popups) {
    popup->frame_callback();
  }
}
