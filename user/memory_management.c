#include "memory_management.h"
#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h"
#include <stddef.h>

//Struct to store page table and table values
struct page {
    int data; //Size of the data being stored
    struct page *next;
};

struct page *header = NULL;
struct page *current = NULL;

//Create a linked list that acts as a page table and data
//Linked list allocates pages and connects them to the pointer that begins that page
void* _malloc(int size) {

    if (size <= 0) {
        return header;
    }
    
    //We know that the size is greater than 0 so now we can move onto allocating memory


    return current;
}

//search through linked list until NULL is seen
void _free(void *ptr) {

}
