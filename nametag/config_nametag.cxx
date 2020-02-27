/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file config_nametag.cxx
 * @author loblao
 */

#include "config_nametag.h"
#include "clickablePopup.h"
#include "marginPopup.h"
#include "nametag2d.h"
#include "nametag3d.h"
#include "nametag.h"
#include "popupMouseWatcherRegion.h"
#include "whisperPopup.h"
#include "marginManager.h"

#if !defined(CPPPARSER) && !defined(LINK_ALL_STATIC) && !defined(BUILDING_PANDA)
  #error Buildsystem error: BUILDING_PANDA not defined
#endif

Configure(config_nametag);
NotifyCategoryDef(nametag, "");

ConfigVariableString nametag_fixed_bin
("nametag-fixed-bin", "fixed");

ConfigureFn(config_nametag) {
  init_libnametag();
}

/**
 * Initializes the library.  This must be called at least once before any of
 * the functions or classes in this library can be used.  Normally it will be
 * called by the static initializers and need not be called explicitly, but
 * special cases exist.
 */
void
init_libnametag() {
  static bool initialized = false;
  if (initialized) {
    return;
  }
  initialized = true;

  ClickablePopup::init_type();
  MarginPopup::init_type();
  Nametag3d::init_type();
  Nametag2d::init_type();
  Nametag::init_type();
  PopupMouseWatcherRegion::init_type();
  WhisperPopup::init_type();
  MarginManager::init_type();
}
