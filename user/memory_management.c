#include "memory_management.h"
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h"
#include <stddef.h>

//Struct to store page table and table values
struct page {
    void *data_ptr; //pointer to start of data value that has been allocated
    struct page *next; //Next pointer within the list
};

struct page *header = NULL;
struct page *current = NULL;
struct page *zero_size = NULL;

//Create a linked list that acts as a page table and data
//Linked list allocates pages and connects them to the pointer that begins that page
void* _malloc(int size) {

    //If size is less than or equal to 0 return a NULL struct
    if (size <= 0) {
        return zero_size;
    }
    
    //We know that the size is greater than 0 so now we can move onto allocating memory
    struct page *allocated = (struct page *) malloc(sizeof(struct page));

    //Grow memeory by what we need and save pointer to page table
    allocated->data_ptr = sbrk(size); 
    
    //Move header and next so that we can properly use the linked list
    allocated->next = header;
    header = allocated;

    //Return the saved pointer
    return allocated->data_ptr;
}

//search through linked list until NULL is seen
void _free(void *ptr) {
    
}
