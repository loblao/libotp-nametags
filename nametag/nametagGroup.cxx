/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametagGroup.cxx
 * @author loblao
 */

#include "nametagGroup.h"
#include "nametag.h"
#include "nametag2d.h"
#include "nametag3d.h"
#include "throw_event.h"

int NametagGroup::_unique_index = 0;

NametagGroup::NametagGroup() : m_name_font(nullptr), m_chat_font(nullptr),
  m_avatar(NodePath()), m_node(nullptr), m_region_seq(1),
  m_wordwrap(-1.0), m_color_code(CC_normal),
  m_qt_color(NametagGlobals::_default_qt_color),
  m_balloon_color(NametagGlobals::_balloon_modulation_color),
  m_has_shadow(false), m_is_flashing(false), m_chat_flags(0),
  m_stomp_time(0), m_stomp_delay(0.5), m_manager(nullptr),
  m_contents(CF_speech | CF_thought | CF_quicktalker),
  m_is_active(true), m_active(NametagGlobals::_master_nametags_active),
  m_visible(NametagGlobals::_master_nametags_visible) {
  m_name_icon = NodePath::any_path(new PandaNode("icon"));

  std::stringstream ss;
  ss << "nametag-" << NametagGroup::_unique_index++;
  m_unique_name = ss.str();

  m_tag2d = new Nametag2d();
  m_tag3d = new Nametag3d();
  add_nametag(m_tag2d);
  add_nametag(m_tag3d);
}

void NametagGroup::set_display_name(const std::string& name) {
  m_display_name = name;
  if (name.size() && m_name_font != nullptr) {
    PT(TextNode) text_node = NametagGlobals::get_text_node();
    text_node->set_font(m_name_font);
    text_node->set_wordwrap(get_name_wordwrap());
    text_node->set_align(TextNode::A_center);
    text_node->set_text(name);
    PT(PandaNode) gen = text_node->generate();
    m_node = gen;
    m_name_frame = text_node->get_card_actual();

    if (m_has_shadow) {
      m_node = new PandaNode("name");
      m_node->add_child(gen);

      NodePath attached = NodePath::any_path(m_node).attach_new_node(gen->copy_subgraph());
      attached.set_pos(m_shadow[0], 0, -m_shadow[1]);
      attached.set_color(0, 0, 0, 1);
    }
  }

  else
    m_node = nullptr;

  update_contents_all();
}

float NametagGroup::get_name_wordwrap() {
  if (m_wordwrap > 0.0)
    return m_wordwrap;

  switch (m_color_code) {
    case CC_no_chat:
      return 7.8;
    case CC_toon_building:
    case CC_suit_building:
      return 8.5;
    case CC_house_building:
      return 10.0;
    default:
      return NametagGlobals::get_name_wordwrap();
  }
}

void NametagGroup::add_nametag(PT(Nametag) nametag) {
  if (nametag->m_group != nullptr) {
    // XXX TODO warning('Attempt to add %s twice to %s.' % (nametag.__class__.__name__, self.m_name))
    return;
  }

  nametag->m_group = this;
  nametag->update_contents();
  m_nametags.push_back(nametag);

  if (m_manager)
    nametag->manage(m_manager);
}

void NametagGroup::remove_nametag(PT(Nametag) nametag) {
  if (nametag->m_group == nullptr) {
    // XXX TODO warning('Attempt to remove %s twice to %s.' % (nametag.__class__.__name__, self.m_name))
    return;
  }

  if (m_manager)
    nametag->unmanage(m_manager);

  nametag->m_group = nullptr;
  nametag->update_contents();
  m_nametags.erase(std::find(m_nametags.begin(), m_nametags.end(), nametag));
}

void NametagGroup::clear_aux_nametags() {
  pvector<PT(Nametag)> to_remove;
  for (auto nametag : m_nametags)
    if (nametag != m_tag2d && nametag != m_tag3d)
      to_remove.push_back(nametag);

  for (auto nametag : to_remove)
    remove_nametag(nametag);
}

void NametagGroup::set_page_number(int page) {
  if (m_page_number == page)
    return;

  m_page_number = page;
  if (will_have_button()) {
    m_flashing_end = ClockObject::get_global_clock()->get_frame_time() + 0.2;
    m_is_flashing = true;
  }

  update_contents_all();
}

void NametagGroup::manage(PT(MarginManager) manager) {
  if (m_manager == nullptr) {
    m_manager = manager;
    for (auto nametag : m_nametags)
      nametag->manage(manager);
  }
}

void NametagGroup::unmanage(PT(MarginManager) manager) {
  if (m_manager != nullptr) {
    m_manager = nullptr;
    for (auto nametag : m_nametags)
      nametag->unmanage(manager);
  }
}

void NametagGroup::update_contents_all() {
  for (auto nametag : m_nametags)
    nametag->update_contents();
}

void NametagGroup::update_regions() {
  for (auto nametag : m_nametags)
    nametag->update_region(m_region_seq);

  m_region_seq++;

  double now = ClockObject::get_global_clock()->get_frame_time();
  if (m_stomp_time < now && m_chat_stomp > 1) {
    m_chat_stomp = 0;
    set_chat(m_stomp_text, m_stomp_chat_flags, m_page_number);
  }

  if (m_chat_flags & CF_timeout && now >= m_timeout) {
    clear_chat();
    m_chat_stomp = 0;
  }

  bool v7 = false;
  if (m_is_flashing && now >= m_flashing_end) {
    m_is_flashing = false;
    v7 = true;
  }

  if (m_active != NametagGlobals::_master_nametags_active) {
    m_active = NametagGlobals::_master_nametags_active;
    v7 = true;
  }

  if (m_visible == NametagGlobals::_master_nametags_visible) {
    if (!v7)
      return;
  }

  else
    m_visible = NametagGlobals::_master_nametags_visible;

  update_contents_all();
}

void NametagGroup::set_chat(const std::string& chat, int chat_flags, int page_number) {
  m_chat_flags = chat_flags;
  m_page_number = page_number;

  double now = ClockObject::get_global_clock()->get_frame_time();
  bool must_split = true;
  if (chat_flags && chat.size()) {
    m_chat_stomp++;
    if (m_chat_stomp >= 2 && m_stomp_delay >= 0.05) {
      m_stomp_text = chat;
      m_stomp_chat_flags = m_chat_flags;
      m_stomp_time = now + m_stomp_delay;
      m_chat_flags = 0;
      must_split = false;
    }
  }

  else {
    m_chat_flags = 0;
    m_chat_stomp = 0;
    must_split = false;
  }

  m_chat_pages.clear();
  if (must_split) {
    std::stringstream ss;
    ss << chat;

    std::string part;
    while (getline(ss, part, '\x07'))
      m_chat_pages.push_back(part);
  }

  if (m_chat_flags & CF_timeout && m_stomp_time < now) {
    double timeout = chat.size() * 0.5;
    timeout = std::min(12.0, std::max(4.0, timeout));
    m_timeout = timeout + now;
  }

  if (will_have_button()) {
    m_is_flashing = true;
    m_flashing_end = now + 0.2;
  }

  else {
    m_is_flashing = false;
    m_flashing_end = 0.0;
  }

  update_contents_all();
}

void NametagGroup::click() {
  throw_event(m_unique_name);
}
