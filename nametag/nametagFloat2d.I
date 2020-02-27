/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametagFloat2d.I
 * @author loblao
 */

NametagFloat2d::NametagFloat2d() : Nametag3d() {
  m_is_3d = false;
  update_contents();
}

NametagFloat2d::~NametagFloat2d() {
}
