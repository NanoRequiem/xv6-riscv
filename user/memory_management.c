#include "memory_management.h"
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h"
#include <stddef.h>


//Create a linked list that acts as a page table and data
//Linked list allocates pages and connects them to the pointer that begins that page
void* _malloc(int size) {
    void *allocated_mem;

    if (size == 0) {
        allocated_mem = 0;
    }
    else {
        char *memory = sbrk(size); //don't need this
        allocated_mem = (void*)memory;
    }
    return allocated_mem;
}

void _free(void *ptr) {

}
