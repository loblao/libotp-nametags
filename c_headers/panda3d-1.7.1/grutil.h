typedef struct {
    __string _name; // 0
    char _has_uvs; // 28
    char _has_3d_uvs; // 29
    char __padding[2]; // 30
    Vec3  _ul_tex; // 32
    Vec3 _ll_tex; // 44
    Vec3 _lr_tex; // 56
    Vec3 _ur_tex; // 68
    Vec3 _ul_pos; // 80
    Vec3 _ll_pos; // 92
    Vec3 _lr_pos; // 104
    Vec3 _ur_pos; // 116
    int _has_color; // 128
    Vec4 _color; // 132
    int _has_normals; // 148
    PandaNode* _source_geometry; // 152
    Vec4 _source_frame; // 156
} CardMaker;
