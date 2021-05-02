#include <stdio.h>

#include "object-store.h"


int main() {
    str_create();

    OBJ o1 = {5};
    OBJ o2 = {0};
    size_t key;
    str_insert(o1, &key); 
    str_view_obj(key, &o2);
    printf("Value retrieved = %d", o2.value);
    return 0;     
}
