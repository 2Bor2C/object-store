#include <stdio.h>

typedef struct OBJ {
    int value;
} OBJ;


typedef enum str_status {
    STR_SUCCESS = 0,
    STR_ERR_OUT_OF_MEMORY,
    STR_ERR_EMPTY,
    STR_ERR_UNKNOWN,
} str_status;

str_status str_create();

str_status str_view_obj(size_t obj_handle, OBJ* o1);

str_status str_insert(OBJ o1, size_t* obj_handle);

str_status str_add(OBJ o1, OBJ o2, size_t* obj_handle);

str_status str_remove_last();

str_status str_remove(size_t obj_handle);



