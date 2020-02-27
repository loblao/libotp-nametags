/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file chatBalloon.I
 * @author loblao
 */

INLINE ChatBalloon::ChatBalloon(PT(PandaNode) node) : m_copy_node(nullptr),
    m_top_node(nullptr), m_middle_node(nullptr), m_bottom_node(nullptr) {
  scan(node);
}

INLINE ChatBalloon::ChatBalloon(const NodePath& np) : m_copy_node(nullptr),
    m_top_node(nullptr), m_middle_node(nullptr), m_bottom_node(nullptr) {
  scan(np.node());
}

INLINE ChatBalloon::~ChatBalloon() {
  m_copy_node = nullptr;
  m_top_node = nullptr;
  m_middle_node = nullptr;
  m_bottom_node = nullptr;
}

INLINE float ChatBalloon::get_hscale() {
  return m_hscale;
}

INLINE float ChatBalloon::get_text_height() {
  return m_text_height;
}

INLINE LVector4f ChatBalloon::get_text_frame() {
  return m_text_frame;
}
