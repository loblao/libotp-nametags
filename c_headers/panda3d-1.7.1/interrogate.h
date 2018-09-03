typedef struct {
  const char *name;
  int index_offset;
} InterrogateUniqueNameDef;

typedef struct {
  int file_identifier;

  const char *library_name;
  const char *library_hash_name;
  const char *module_name;
  const char *database_filename;

  InterrogateUniqueNameDef *unique_names;
  int num_unique_names;

  void **fptrs;
  int num_fptrs;

  int first_index;
  int next_index;
} InterrogateModuleDef;

struct PyMethodDef {
    const char	*ml_name;	/* The name of the built-in function/method */
    void*  ml_meth;	/* The C function that implements it */
    int		 ml_flags;	/* Combination of METH_xxx flags, which mostly
				   describe the args expected by the C func */
    const char	*ml_doc;	/* The __doc__ attribute, or NULL */
};

struct LibrayDef
{
    PyMethodDef *           _methods;
    void*        _constants;
};
