#include "memory_management.h"
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h"
#include <stddef.h>

//Struct to store page table and table values
struct page {
    void *data_ptr; //pointer to start of data value that has been allocated
    bool allocation; //boolean to check if a page is currently in use
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
    
    //Search through the current page table to see if we have a page that is currently free
    struct page *search = header;
    while(search != NULL) {
        //If we have a page that is currently free then return that
        if(search->allocation) {
            return search->data_ptr
        }

        search = search->next;
    }

    //We know that the size is greater than 0 so now we can move onto allocating memory
    struct page *newAllocate = (struct page *) malloc(sizeof(struct page));

    //Grow memeory by what we need and save pointer to page table
    newallocate->data_ptr = sbrk(size);
    //Since we have allocated memory set allocation as true 
    newAllocate->allocation = true;

    //Move header and next so that we can properly use the linked list
    newAllocate->next = header;
    header = newAllocate;

    //Return the saved pointer
    return newAllocate->data_ptr;
}

//search through linked list until NULL is seen
void _free(void *ptr) {
    struct page *search = header;

    while(search != NULL) {
        if(search->data_ptr == ptr) {
            
        }
    }
}
