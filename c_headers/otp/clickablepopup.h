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
} vtable_generic_clickablepopup;

typedef struct {
  vtable_generic_clickablepopup* vtable_clickablepopup;
  int m_state;
} ClickablePopup;
