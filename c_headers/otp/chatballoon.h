typedef struct {
  vtable_generic_refcount* vtable; // 0
  int refcount; // 4
  void* weak_ptr_list; // 8
  PandaNode* m_copy_node; // 12
  PandaNode* m_top_node; // 16
  PandaNode* m_middle_node; // 20
  PandaNode* m_bottom_node; // 24
  Mat4 m_top_mat; // 28
  Mat4 m_middle_mat; // 92
  float m_hscale; // 156
  float m_text_height; // 160
  Vec4 m_text_frame; // 164
} ChatBalloon;
