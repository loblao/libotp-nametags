typedef struct {
  Nametag2d* m_tag2d; // 0
  Nametag3d* m_tag3d; // 4
  char m_nametags[16]; // 8 (pvector<Nametag*>)
  TextFont* m_name_font; // 24
  TextFont* m_chat_font; // 28
  NodePath m_avatar; // 32
  PandaNode* m_node; // 44
  Vec4 m_name_frame; // 48
  NodePath m_name_icon; // 64
  float m_wordwrap; // 76
  int m_color_code; // 80
  Vec4 m_qt_color; // 84
  Vec4 m_balloon_color; // 100
  float m_shadow[2]; // 116
  int m_has_shadow; // 124
  __string m_name; // 128
  __string m_display_name; // 156
  char m_chat_pages[16]; // 184 (pvector<string>)
  int m_chat_flags; // 200
  int field_204; // 204
  double m_timeout; // 208
  double m_flashing_end; // 216
  __string m_stomp_text; // 224
  int m_stomp_chat_flags; // 252
  float m_stomp_delay; // 256
  int field_260; // 260
  float m_stomp_time; // 264
  int field_268; // 268
  int m_chat_stomp; // 272
  int m_page_number; // 276
  int m_is_flashing; // 280
  __string m_unique_name; // 284
  int m_object_code; // 312
  int m_nametag3d_flag; // 316
  MarginManager* m_manager; // 320
  int m_region_seq; // 324
  int m_contents; // 328
  char m_is_active; // 332
  char m_active; // 333
  char m_visible; // 334
} NametagGroup;
