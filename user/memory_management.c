#include "memory_management.h"
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h"
#include <stddef.h>

void* _malloc(int size) {
    void *allocated_mem;

    if (size == 0) {
        allocated_mem = 0;
    }
    else {
        char *memory = sbrk(size); //Grow the size of the heap
        allocated_mem = (void*)memory;
    }
    return allocated_mem;
}

void _free(void *ptr) {

}
