#include <stdio.h>

typedef struct STACK_ENTRY {
    int a;
} STACK_ENTRY;


typedef enum stack_status {
    STACK_SUCCESS = 0,
    STACK_ERR_OUT_OF_MEMORY,
    STACK_ERR_UNKNOWN,
    STACK_ERR_UNINITIALIZED,
    STACK_ERR_INVALID_INPUT,
    STACK_ERR_EMPTY,
} stack_status;

stack_status stack_create(size_t stack_count);

stack_status stack_push(size_t index);

stack_status stack_pop();

stack_status stack_top(size_t *handle);

stack_status stack_destroy();




