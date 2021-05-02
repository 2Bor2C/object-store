#include <stdio.h>
#include <string.h>

#include "object-store.h"
#include "stack.h"

#define MAX_STORE_SIZE 10
#define ERR_OUT_OF_MEMORY 1


static OBJ obj_str[MAX_STORE_SIZE];
static size_t str_sz = 0;


str_status str_create() {
    printf("info: %d : %s \n", __LINE__, __FUNCTION__);
    str_sz = 0;
    stack_create(MAX_STORE_SIZE);
    for(size_t i = 0; i < MAX_STORE_SIZE; i++) {
        stack_push(i);
    }
    return STR_SUCCESS;
}

str_status str_insert(OBJ o1, size_t* obj_handle) {
    printf("info: %d : %s \n", __LINE__, __FUNCTION__);
    if(str_sz >= MAX_STORE_SIZE) {
        return STR_ERR_OUT_OF_MEMORY;
    }
   
    
    obj_str[str_sz] = o1;
    *obj_handle = str_sz++;
    return STR_SUCCESS;
}

str_status str_view_obj(size_t obj_handle, OBJ* o1) {
    printf("info: %d : %s \n", __LINE__, __FUNCTION__);
    if(obj_handle < 0 || obj_handle >= MAX_STORE_SIZE) {
        return STR_ERR_OUT_OF_MEMORY;
    }

    *o1 = obj_str[obj_handle];
    return STR_SUCCESS;
}


str_status str_add(OBJ o1, OBJ o2, size_t* obj_handle) {
    printf("info: %d : %s \n", __LINE__, __FUNCTION__);
    if(str_sz >= MAX_STORE_SIZE) {
        return STR_ERR_OUT_OF_MEMORY;
    }
    OBJ o3;
    o3.value = o1.value + o2.value;
    return str_insert(o3, obj_handle);
     
}


str_status str_remove_last() {
    printf("info: %d : %s \n", __LINE__, __FUNCTION__);
    if(str_sz == 0) {
        return STR_ERR_EMPTY;
    }
    if(str_sz - 1 >= MAX_STORE_SIZE) {
        return STR_ERR_UNKNOWN;
    }
    obj_str[--str_sz];
    return STR_SUCCESS;    
}


str_status str_remove(size_t obj_handle) {
    printf("info: %d : %s \n", __LINE__, __FUNCTION__);
    if((obj_handle < 0) || obj_handle >= MAX_STORE_SIZE) {
        return STR_ERR_EMPTY;
    }
    memset(&obj_str[obj_handle], 0, sizeof(obj_str[obj_handle]));
    return STR_SUCCESS;    
}

str_status str_destroy() {
    printf("info: %d : %s \n", __LINE__, __FUNCTION__);
    stack_destroy();
    return STR_SUCCESS;    
}
