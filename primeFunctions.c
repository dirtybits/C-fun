#include <stdio.h>
#include <stdlib.h>

int isprime(int);
int *createArray();

int main(){

    int i = 0;
    int flag = 0;
    int *ptr = createArray();
    printf("%p\n%d\n", ptr, *ptr);
    flag = isprime(75);
    printf("%d\n", flag);

    while(*(ptr+i)<=100){

        if(isprime(*(ptr+i))){
            printf("%d is prime\n", *(ptr+i));
        }else{
        printf("%d is not prime\n", *(ptr+i));
        }
        i++;
    }
    return 0;
}

int *createArray(){

    int i;
    int *ptr = malloc(100*sizeof(*ptr));
    
    for(i = 0; i < 100; i++){
        *(ptr+i) = (i+1);
    }
    return ptr;
}

// need to fix this
int isprime(int n){
    
    int i;

    // corner case
    if(n == 1)
        return 0;

    for(i = 2; i<n; i++){
        
        if(n % i == 0){
            return 0;
        }else{
            return 1;
        }
    }
    // will get a warning without this:
    return 0;
}
