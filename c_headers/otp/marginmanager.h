typedef struct {
  Mat4 mat; // 0
  float cell_width; // 64
  MarginPopup* popup; // 68
  NodePath np; // 72
  int visible; // 84
  int objcode; // 88
  int field_92; // 92
  double time; // 96
} MarginCell;

typedef struct {
  int field_0;
  int field_4;
  int field_8;
  MarginPopup* m_popup; // 12
  int m_cell; // 16
  int m_wants_visible; // 20
  int m_score; // 24
  int m_objcode; // 28
} PopupHandle;

typedef struct {
  vtable_generic_typed* vtable_typed; // 0
  void* field_4; // 4
  void* field_8; // 8
  __string _name; // 12
  void* _prev; // 40
  void* _next; // 44
  void* vbtable; // 48
  char paths_and_mutex_junk[48]; // 52
  void* _state; // 100
  TransformState* _transform; // 104
  TransformState* _prev_transform; // 108
  void* _effects; // 112
  char tag_junk[48]; // 116
  int _draw_control_mask; // 164
  int _draw_show_mask; // 168
  int _into_collide_mask; // 172
  int _bounds_type; // 176
  void* _user_bounds; // 180
  int _final_bounds; // 184
  int _fancy_bits; // 188
  int _net_collide_mask; // 192
  int _net_draw_control_mask; // 196
  int _net_draw_show_mask; // 200
  void* _off_clip_planes; // 204
  int _nested_vertices; // 208
  void* _external_bounds; // 212
  int _last_update; // 216
  int _next_update; // 220
  void* _down; // 224
  void* _stashed; // 228
  void* _up; // 232

  void* m_popups[5]; // 236
  int field_256; // 256
  void* m_code_map[5]; // 260
  int field_280; // 280
  NodePath field_284; // 284
  MarginCell* m_cells[4]; // 296
  int m_num_available; // 312
  vtable_generic_refcount* vtable_refcount; // 316
  int refcount; // 320
  void* weak_ptr_list; // 324
} MarginManager;
