/**
 * LIBOTP-NAMETAGS SOFTWARE
 * Copyright (c) loblao.  All rights reserved.
 *
 * All use of this software is subject to the terms of the MIT
 * license.  You should have received a copy of this license along
 * with this source code in a file named "LICENSE."
 *
 * @file nametagGroup.h
 * @author loblao
 */

#ifndef NAMETAGGROUP_H
#define NAMETAGGROUP_H

#include "config_nametag.h"

class Nametag; // fwd decl
class Nametag2d; // fwd decl
class Nametag3d; // fwd decl

class EXPCL_NAMETAG NametagGroup {
PUBLISHED:
  enum ColorCode {
    CC_normal = 0,
    CC_no_chat,
    CC_non_player,
    CC_suit,
    CC_toon_building,
    CC_suit_building,
    CC_house_building,
    CC_speed_chat,
    CC_free_chat
  };

  NametagGroup();
  INLINE ~NametagGroup();

  INLINE void set_font(PT(TextFont) font);
  INLINE void set_name_font(PT(TextFont) font);
  INLINE PT(TextFont) get_name_font();
  INLINE void set_chat_font(PT(TextFont) font);
  INLINE PT(TextFont) get_chat_font();

  INLINE void set_avatar(const NodePath& avatar);
  INLINE NodePath get_avatar();

  INLINE void set_name_icon(const NodePath& icon);
  INLINE NodePath get_name_icon();

  INLINE void set_color_code(NametagGroup::ColorCode code);
  INLINE NametagGroup::ColorCode get_color_code();

  INLINE void set_contents(int contents);
  INLINE int get_contents();

  void set_display_name(const std::string& name);
  INLINE std::string get_display_name();

  INLINE void set_name(const std::string& name);
  INLINE std::string get_name();
  INLINE LVector4f get_name_frame();

  INLINE void set_name_wordwrap(float wordwrap);
  float get_name_wordwrap();

  void add_nametag(PT(Nametag) nametag);
  void remove_nametag(PT(Nametag) nametag);
  void clear_aux_nametags();
  INLINE Nametag* get_nametag(int index);
  INLINE Nametag2d* get_nametag2d();
  INLINE Nametag3d* get_nametag3d();
  INLINE int get_num_nametags();

  void set_page_number(int page);
  INLINE int get_page_number();
  INLINE int get_num_chat_pages();

  INLINE void set_object_code(int code);
  INLINE int get_object_code();

  INLINE void set_qt_color(LColorf color);
  INLINE LColorf get_qt_color();
  INLINE LColorf get_balloon_modulation_color();

  INLINE void set_shadow(LVector2f shadow);
  INLINE LVector2f get_shadow();
  INLINE bool has_shadow();
  INLINE void clear_shadow();

  INLINE float get_stomp_delay();
  INLINE std::string get_stomp_text();

  INLINE void set_unique_id(const std::string& name);
  INLINE std::string get_unique_id();

  INLINE bool has_button();
  INLINE bool has_no_quit_button();
  INLINE bool has_quit_button();
  INLINE bool has_page_button();
  INLINE bool will_have_button();

  void manage(PT(MarginManager) manager);
  void unmanage(PT(MarginManager) manager);
  INLINE bool is_managed();

  INLINE void set_active(bool active);
  INLINE bool is_active();

  void update_contents_all();
  void update_regions();

  void set_chat(const std::string& chat, int chat_flags, int page_number = 0);
  INLINE std::string get_chat();
  INLINE void clear_chat();
  INLINE int get_chat_stomp();
  INLINE int get_chat_flags();

public:
  INLINE void set_nametag3d_flag(int flag);
  INLINE void increment_nametag3d_flag(int flag);
  INLINE int get_nametag3d_flag();

  INLINE int get_region_seq();

  void click();
  INLINE NodePath copy_name_to(const NodePath& to);
  INLINE bool display_as_active();

private:
  static int _unique_index;

  PT(Nametag2d) m_tag2d;
  PT(Nametag3d) m_tag3d;
  pvector<PT(Nametag)> m_nametags;
  PT(TextFont) m_name_font;
  PT(TextFont) m_chat_font;
  NodePath m_avatar;
  PT(PandaNode) m_node;
  LVector4f m_name_frame;
  NodePath m_name_icon;
  float m_wordwrap;
  ColorCode m_color_code;
  LVector4f m_qt_color;
  LVector4f m_balloon_color;
  LVector2f m_shadow;
  bool m_has_shadow;
  std::string m_name;
  std::string m_display_name;
  pvector<std::string> m_chat_pages;
  int m_chat_flags;
  int field_204;
  double m_timeout;
  double m_flashing_end;
  std::string m_stomp_text;
  int m_stomp_chat_flags;
  float m_stomp_delay;
  int field_260;
  float m_stomp_time;
  int field_268;
  int m_chat_stomp;
  int m_page_number;
  int m_is_flashing;
  std::string m_unique_name;
  int m_object_code;
  int m_nametag3d_flag;
  PT(MarginManager) m_manager;
  int m_region_seq;
  int m_contents;
  bool m_is_active;
  bool m_active;
  bool m_visible;

  friend class Nametag2d;
  friend class Nametag3d;
};

#include "nametagGroup.I"

#endif // NAMETAGGROUP_H
