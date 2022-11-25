#include "user/memory_management.h"
#include "kernel/types.h"
#include "user/user.h"
#include <stddef.h>

int main(int argc, char *argv[]) {
    printf("-----STARTING TEST-----\n");
    
    int x = 10, y = 8;

    printf("%d\n", x / y + (x % y !=0));

    printf("Testing NULL: ");
    void *bruh = _malloc(0);

    if(bruh == NULL) {
         printf("passed \n");
    }

    printf("Basic allocation: ");
    void *allocation = _malloc(4);
    void *allocatedeez = _malloc(12);
    void *ally = _malloc(9);

    if(allocation != NULL) {
        printf("passed \n");
    }

    printf("Free then allocate");

    _free(allocatedeez);
    void *freeallocate = _malloc(4);
    printf("free'd allocation = %x\n", allocatedeez);
    printf("new allocation = %x\n", freeallocate);
    printf("ally = %x\n", ally);
    

    return 0;
}
