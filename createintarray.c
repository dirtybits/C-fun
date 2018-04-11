#include "createintarray.h"

// create int array
int *createintarray(int size){

    int i;
    int *ptr = malloc(size*sizeof(*ptr));
    
    for(i = 0; i < size; i++){
        *(ptr+i) = (i+1);
    }
    return ptr;
}