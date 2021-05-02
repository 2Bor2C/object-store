#include "stack.h"
#include <stdlib.h>

#define MAX_STACK_SIZE 10
#define ERR_OUT_OF_MEMORY 1


static size_t StackTop = -1;
static size_t StackSize = 0;
static size_t* StackPtr = NULL;

stack_status stack_create(size_t stack_size_in) {
    printf("info: %d : %s \n", __LINE__, __FUNCTION__); 
    
    if(stack_size_in == 0) {
        return STACK_ERR_UNKNOWN;
    }
    if(stack_size_in > 100){
        return STACK_ERR_OUT_OF_MEMORY;
    }
    StackPtr = (size_t*)malloc(stack_size_in * sizeof(size_t));
    if(StackPtr == NULL){
        return STACK_ERR_OUT_OF_MEMORY;
    }
    StackTop = -1;
    StackSize = stack_size_in;
    return STACK_SUCCESS;
}

stack_status stack_push(size_t value) {
    printf("info: %d : %s \n", __LINE__, __FUNCTION__); 
    if(StackTop >= StackSize) {
        return STACK_ERR_OUT_OF_MEMORY;
    }
    
    StackPtr[++StackTop] = value;
    
    return STACK_SUCCESS;
}

stack_status stack_pop() {
    printf("info: %d : %s \n", __LINE__, __FUNCTION__); 
    if(StackTop == 0) {
        return STACK_ERR_UNINITIALIZED;
    }
    StackPtr[StackTop--] = 0;
    return STACK_SUCCESS;
}

stack_status stack_top(size_t* handle) {
    printf("info: %d : %s \n", __LINE__, __FUNCTION__); 
    if(StackTop == 0){
        return STACK_ERR_EMPTY;
    }
    if(handle == NULL) {
        return STACK_ERR_INVALID_INPUT;
    }
    *handle = StackPtr[StackTop-1];
    return STACK_SUCCESS;
}

stack_status stack_destroy() {
    printf("info: %d : %s \n", __LINE__, __FUNCTION__); 
    if(StackPtr) {
        free(StackPtr);
        StackPtr = NULL;
    }
}
