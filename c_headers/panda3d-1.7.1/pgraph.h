/* 
BASE CLASSES FOR REFERENCE - DO NOT IMPORT

CachedTypedWritableReferenceCount(20) { // base DNI
  // TypedWritableReferenceCount fields
  int _cache_ref_count;
}

NodeCachedReferenceCount(24) { // base DNI
  // CachedTypedWritableReferenceCount fields
  int _node_ref_count;
}
*/

typedef struct {
  void* vtable_typed; // 0
  void* _bam_writers; // 4
  int _bam_modified; // 8
  vtable_generic_refcount* vtable_refcount; // 12

  int refcount; // 16
  void* weak_ptr_list; // 20
  int _cache_ref_count; // 24
  int _node_ref_count; // 28

  void* _saved_entry; // 32
  SimpleHashMap _composition_cache; // 36
  SimpleHashMap _invert_composition_cache; // 56
  int _cycle_detect; // 76
  Vec3 _pos; // 80
  Vec3 _hpr; // 92
  Vec3 _scale; // 104
  Vec3 _shear; // 116
  Vec4 _quat; // 128
  Vec4 _norm_quat; // 144
  Mat4 _mat; // 160
  Mat4 *_inv_mat; // 224
  int _hash; // 228
  unsigned int _flags; // 232
} TransformState;

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
  vtable_generic_refcount* vtable_refcount; // 236
  int refcount; // 240
  void* weak_ptr_list; // 244
} PandaNode;

typedef struct {
  vtable_generic_refcount* vtable_refcount;
  int refcount;
  void* weak_ptr_list;
  PandaNode* _node;
  int _key;
} NodePathComponent;

typedef struct {
  NodePathComponent* _head;
  int _backup_key;
  int _error_type;
} NodePath;
