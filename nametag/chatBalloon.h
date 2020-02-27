/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file chatBalloon.h
 * @author loblao
 */

#ifndef CHATBALLOON_H
#define CHATBALLOON_H

#include "config_nametag.h"
#include "pandaNode.h"
#include "textFont.h"
#include "nodePath.h"

class EXPCL_NAMETAG ChatBalloon : public ReferenceCount {
PUBLISHED:
  INLINE virtual ~ChatBalloon();
  INLINE ChatBalloon(PT(PandaNode) node);
  INLINE ChatBalloon(const NodePath& np);

public:
  INLINE float get_hscale();
  INLINE float get_text_height();
  INLINE LVector4f get_text_frame();

  PT(PandaNode) generate(const std::string& text, PT(TextFont) font, float wordwrap,
                         LColorf text_color, LColorf balloon_color, bool for_3d,
                         bool has_draw_order, int draw_order, const NodePath& page_button,
                         bool space_for_button, bool reversed, NodePath& new_button);

private:
  static PT(PandaNode) find_geom_node(PT(PandaNode) node);
  static PT(PandaNode) find_middle_geom(PT(PandaNode) node);
  bool scan(PT(PandaNode) node);
  bool scan_balloon(PT(PandaNode) node);

  PT(PandaNode) m_copy_node;
  PT(PandaNode) m_top_node;
  PT(PandaNode) m_middle_node;
  PT(PandaNode) m_bottom_node;

  LMatrix4f m_top_mat;
  LMatrix4f m_middle_mat;
  LMatrix4f m_bottom_mat;

  float m_hscale;
  float m_text_height;
  LVector4f m_text_frame;
};

#include "chatBalloon.I"

#endif // CHATBALLOON_H
