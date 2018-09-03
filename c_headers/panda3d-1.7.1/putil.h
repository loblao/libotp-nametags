/*
BASE CLASSES FOR REFERENCE - DO NOT IMPORT

ReferenceCount(8) { // base DNI
  int refcount;
  void* weak_ptr_list;
}

TypedWritable(8) { // base DNI
  void*_bam_writers;
  int _bam_modified;
}

TypedWritableReferenceCount(16) { // base DNI
  // TypedWritable fields
  // ReferenceCount fields
}
*/

typedef struct {
  void *_table;
  void *_deleted_chain;
  int _table_size;
  int _num_entries;
  void* comp;
} SimpleHashMap;

typedef struct {
  void* meth_dtor;
  void* meth_unref;
} vtable_generic_refcount;

typedef struct {
  void* meth_dtor;
} vtable_generic_typed;
