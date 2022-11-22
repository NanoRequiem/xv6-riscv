#include "memory_management.h"
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h"
#include <stddef.h>

//Struct to store page table and table values
struct page {
    void *data_ptr; //pointer to start of data value that has been allocated
    int blocks; //Amount of blocks left in contiguous data
    int allocation; //int to check if a page is currently in use (1=in use, 0=free)
    struct page *next; //Next pointer within the list
};

struct page *header = NULL;
struct page *zero_size = NULL;

//Page size of 8 bytes 
const int page_size = 8;

//Create a linked list that acts as a page table and data
//Linked list allocates pages and connects them to the pointer that begins that page
void* _malloc(int size) {

    //If size is less than or equal to 0 return a NULL struct
    if (size <= 0) {
        return zero_size;
    }
    
    //Now that we know the size is greater than 0 we must see how many pages need to be allocated
    int needed = size / page_size + (size % page_size !=0);

    //Search through the current page table to see if we have a page that is currently free
    struct page *search = header;
    struct page *found = NULL; //store the free page if we find one
    int foundInt = 0; // value to check how many contiguous pages we have found
    while(search != NULL) {
        //If we have a page that is currently free then count that
        if(search->allocation == 0) {
            if(foundInt == 0){
                found = search;
            }
            foundInt = foundInt + 1;
            
            if(foundInt == needed) {
                void *return_value = found->data_ptr;
                //Loops from where first spare block was found to the last and allocates them
                while(foundInt > 0){
                    found->blocks = foundInt;
                    found->allocation = 1;
                    found = found->next;
                    foundInt=foundInt-1;
                }
                return return_value;
            }
        }
        search = search->next;
    }


    int blocksLeft = needed;
    void *return_value = NULL;
    while(blocksLeft > 0) {
        //We know that the size is greater than 0 so now we can move onto allocating memory
        struct page *newAllocate = (struct page *) malloc(sizeof(struct page));

        //Grow memeory by what we need and save pointer to page table
        newAllocate->data_ptr = sbrk(page_size);
        //Since we have allocated memory set allocation as true 
        newAllocate->allocation = 1;
        newAllocate->blocks = blocksLeft;
        //Move header and next so that we can properly use the linked list
        newAllocate->next = header;
        header = newAllocate;

        if(blocksLeft == needed) {
            return_value = newAllocate->data_ptr;
        }

        blocksLeft = blocksLeft - 1;
    }
    
    //Return the saved pointer
    return return_value;
}

//search through linked list until NULL is seen
void _free(void *ptr) {
    struct page *search = header;
    int endFreed = 0;

    while(search != NULL) {
        if(search->data_ptr == ptr) {
            int blocks = search->blocks;
            while(blocks > 0) {
                search->allocation = 0;
                blocks = blocks - 1;
                endFreed = endFreed + 1;
            }

            if(search->next ==  NULL) {
                sbrk(-1 * endFreed * page_size);
            }
        }

        search = search->next;
    }
}
