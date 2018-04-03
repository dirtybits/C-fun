#include <stdio.h>
#include <stdlib.h>

int main(){

    int i, j, count = 0;
    int *ptr = malloc(100*sizeof(*ptr));

    for(i = 0; i<=99; i++)
        *(ptr+i) = (i+1);

    i = 1;

    while(*(ptr+i) <= 100){

        j = 0;
        count = 0;
        while (*(ptr+j) <= *(ptr+i)){

            if (*(ptr+i) % *(ptr+j) == 0){
                count++;
            }
            if (count == 3){
                printf("%d is not prime\n", *(ptr+i));
                break;
            }
            j++;
        }
        if (count == 2){
            printf("%d is prime\n", *(ptr+i));
        }
        i++;
    }
    
    free(ptr);
    return 0;
}
