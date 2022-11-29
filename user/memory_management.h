//Header file for xv6 memory management
//
//Brooklyn Mcswiney - ed20b3m

//Allocates memory on the heap and returns the start of the allocated memory
void* _malloc(int size);

//Frees memory space pointed to by a parameter(ptr)
//Parameter must have been returned by a previous call to _malloc().
void _free(void *ptr);