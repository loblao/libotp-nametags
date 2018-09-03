typedef struct {
  vtable_generic_typed* vtable_typed; // 0
  void* _bam_writers; // 4
  int _bam_modified; // 8
  vtable_generic_refcount* vtable_refcount; // 12
  int refcount; // 16
  void* weak_ptr_list; // 20
  __string _name; // 24
  Vec4 _frame; // 52
  float _area; // 68
  int _sort; // 72
  int _flags; // 76
} MouseWatcherRegion;

typedef struct {
  int _button; // 0
  int _keycode; // 4
  __string _candidate_string; // 8
  int _highlight_start; // 36
  int _highlight_end; // 40
  int _cursor_pos; // 44
  char _mods_junk[12]; // 48
  float _mouse[2]; // 56
  int _flags; // 64
} MouseWatcherParameter;
