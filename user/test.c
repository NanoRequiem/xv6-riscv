#include "memory_management.h"
#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
    printf("-----STARTING TEST-----\n");
    
    printf("Testing NULL: ");
    int *bruh = _malloc(0);

    if(bruh == 0) {
        printf("passed \n");
    }

    return 0;
}