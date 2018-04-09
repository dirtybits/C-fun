#include "isprime.h"

// check for primality
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
