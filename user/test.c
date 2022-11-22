#include "user/memory_management.h"
#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    printf("-----STARTING TEST-----\n");
    
    int x = 10, y = 8;

    printf("%d\n", x / y + (x % y !=0));

    // printf("Testing NULL: ");
    // int *bruh = _malloc(0);

    // if(bruh == 0) {
    //     printf("passed \n");
    // }

    return 0;
}