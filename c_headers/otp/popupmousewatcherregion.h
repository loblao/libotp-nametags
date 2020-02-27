typedef struct {
  void* meth_dtor;
  void* meth_get_type;
  void* meth_force_init_type;
  void* meth_write_datagram;
  void* meth_update_bam_nested;
  void* meth_complete_pointers;
  void* meth_require_fully_complete;
  void* meth_fillin;
  void* meth_finalize;
  void* meth_as_reference_count;
  void* meth_enter_region;
  void* meth_exit_region;
  void* meth_within_region;
  void* meth_without_region;
  void* meth_press;
  void* meth_release;
  void* meth_keystroke;
  void* meth_candidate;
  void* meth_move;
} vtable_popupmousewatcherregion;

typedef struct {
  vtable_popupmousewatcherregion* vtable_pmwr; // 0
  void* _bam_writers; // 4
  int _bam_modified; // 8
  vtable_popupmousewatcherregion* vtable_refcount; // 12
  int refcount; // 16
  void* weak_ptr_list; // 20
  __string m_name; // 24
  Vec4 _frame; // 52
  float _area; // 68
  int _sort; // 72
  int _flags; // 76
  ClickablePopup* m_popup; // 80
} PopupMouseWatcherRegion;
