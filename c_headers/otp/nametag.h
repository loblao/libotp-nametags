typedef struct {
  void* meth_dtor;
  void* meth_enter_region;
  void* meth_exit_region;
  void* meth_press;
  void* meth_release;
  void* meth_click;
  void* meth_set_state;
  void* meth_get_state;
  void* meth_update_contents;
  void* meth_get_type;
  void* meth_manage;
  void* meth_unmanage;
} vtable_nametag_clickablepopup;

typedef struct {
  vtable_nametag_clickablepopup* vtable_clickablepopup; // 0
  int m_state; // 4
  void* vbtable; // 8
  int m_chat_contents; // 12
  int m_draw_order; // 16
  int m_has_draw_order; // 20
  int m_contents; // 24
  int m_active; // 28
  NametagGroup* m_group; // 32
  float m_wordwrap; // 36
  NodePath m_avatar; // 40
  __string m_ival_name; // 52
  void* m_ival; // 80
  MouseWatcherRegion* m_popup_region; // 84 [PopupMouseWatcherRegion*]
  int m_has_region; // 88
  int m_seq; // 92
  void* m_mouse_watcher; // 96
  vtable_generic_refcount* vtable_refcount; // 100
  int refcount; // 104
  void* weak_ptr_list; // 108
} Nametag;
