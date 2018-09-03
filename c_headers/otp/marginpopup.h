typedef struct {
  void* meth_dtor;
  void* meth_MarginPopup_get_type;
  void* meth_MarginPopup_force_init_type;
  void* meth_PandaNode_write_datagram;
  void* meth_PandaNode_update_bam_nested;
  void* meth_TypedWritable_complete_pointers;
  void* meth_TypedWritable_require_fully_complete;
  void* meth_PandaNode_fillin;
  void* meth_TypedWritable_finalize;
  void* meth_PandaNode_as_reference_count;
  void* meth_PandaNode_combine_with;
  void* meth_PandaNode_dupe_for_flatten;
  void* meth_PandaNode_safe_to_flatten;
  void* meth_PandaNode_safe_to_transform;
  void* meth_PandaNode_safe_to_modify_transform;
  void* meth_PandaNode_safe_to_combine;
  void* meth_PandaNode_safe_to_combine_children;
  void* meth_PandaNode_safe_to_flatten_below;
  void* meth_PandaNode_preserve_name;
  void* meth_PandaNode_get_unsafe_to_apply_attribs;
  void* meth_PandaNode_apply_attribs_to_vertices;
  void* meth_PandaNode_xform;
  void* meth_PandaNode_calc_tight_bounds;
  void* meth_PandaNode_cull_callback;
  void* meth_PandaNode_has_selective_visibility;
  void* meth_PandaNode_get_first_visible_child;
  void* meth_PandaNode_get_next_visible_child;
  void* meth_PandaNode_has_single_child_visibility;
  void* meth_PandaNode_get_visible_child;
  void* meth_PandaNode_is_renderable;
  void* meth_PandaNode_add_for_draw;
  void* meth_PandaNode_make_copy;
  void* meth_PandaNode_get_legal_collide_mask;
  void* meth_PandaNode_output;
  void* meth_PandaNode_write;
  void* meth_PandaNode_is_geom_node;
  void* meth_PandaNode_is_lod_node;
  void* meth_PandaNode_as_light;
  void* meth_PandaNode_is_ambient_light;
  void* meth_PandaNode_r_mark_geom_bounds_stale;
  void* meth_PandaNode_compute_internal_bounds;
  void* meth_PandaNode_parents_changed;
  void* meth_PandaNode_children_changed;
  void* meth_PandaNode_transform_changed;
  void* meth_PandaNode_state_changed;
  void* meth_PandaNode_draw_mask_changed;
  void* meth_PandaNode_r_copy_subgraph;
  void* meth_PandaNode_r_copy_children;
  void* meth_PandaNode_r_prepare_scene;
  void* meth_MarginPopup_get_score;
  void* meth_MarginPopup_get_object_code;
  void* meth_MarginPopup_update_contents;
  void* meth_MarginPopup_frame_callback;
  void* meth_MarginManager_is_renderable;
  void* meth_MarginPopup_consider_visible;
  void* meth_MarginPopup_set_managed;
  void* meth_MarginPopup_set_visible;
} vtable_generic_marginpopup;

typedef struct {
  vtable_generic_marginpopup* vtable_typed; // 0
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

  int m_seq; // 236
  NodePath m_np; // 240
  char m_managed; // 252
  char m_visible; // 253
  char __padding_2[2]; // 254
  float m_cell_width; // 256

  vtable_generic_refcount* vtable_refcount; // 260
  int refcount; // 264
  void* weak_ptr_list; // 268
} MarginPopup;
