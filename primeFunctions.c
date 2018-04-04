#include <stdio.h>
#include <stdlib.h>

int isprime(int);
int *createArray();

int main(){

    int flag = 0;
    int *ptr = createArray();
    printf("%p\n%d\n", ptr, *ptr);
    flag = isprime(78);
    printf("%d\n", flag);

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

int isprime(int n){
    int i;

    // corner case
    if(n == 1){
        return 0;
    }
    for(i = 2; i<n; i++){
        
        if(n % i == 0){
            return 0;
        }else{
            return 1;
        }
    }
    // will get a warning without this
    return 0;
}