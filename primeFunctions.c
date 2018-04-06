#include <stdio.h>
#include <stdlib.h>

int isprime(int);
int *createintarray(int);

int main(){

    int i = 0;
    int flag = 0;
    int size = 100;
    int *ptr = createintarray(size);
    
    flag = isprime(75);
    printf("%p\n%d\n", ptr, *ptr);
    printf("%d\n", flag);

    while(*(ptr+i)<=size){

        if(isprime(*(ptr+i))){
            printf("%d is prime\n", *(ptr+i));
        }else{
            printf("%d is not prime\n", *(ptr+i));
        }
        i++;
    }
    return 0;
}

int *createintarray(int size){

    int i;
    int *ptr = malloc(size*sizeof(*ptr));
    
    for(i = 0; i < size; i++){
        *(ptr+i) = (i+1);
    }
    return ptr;
}


int isprime(int n){
    
    int i;
    int count = 0;

    // corner case
    if(n == 1)
        return 0;
    
    for(i = 1; i<n; i++){
        
        if(n % i == 0){
            count++;
        }
        if(count == 2){
            return 0;
        }
    }
    if(count == 1){
        return 1;
    }
    // will get a warning without this:
    return 0;
}
