typedef struct {
  vtable_generic_typed* vtable_typed;
  vtable_generic_refcount* vtable_refcount;
  int refcount;
  void* weak_ptr_list;
  int _flags;
  Vec3 _center;
  float _radius;
} BoundingSphere;
