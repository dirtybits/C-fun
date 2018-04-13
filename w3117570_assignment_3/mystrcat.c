#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrcat(char *destination, const char *source);

int main(){

    char str1[50] = "this is a";
    char str2[50] = " concatenated text"; 
    char str3[50] = ", WOW!";

    mystrcat(str1, str2);  // appends str2 to str1
    mystrcat(str1, str3);  // appends str3 to the newly concatenated str1

    printf("%s",str1);

    return 0;
}
 
char *mystrcat(char *destination, const char *source){

    // set counters
    int i = 0;
    int j = 0;
    // iterate to the end of the destination string
    while (destination[i] != '\0'){ 
        i++;
    }
    while (source[j]){         // while source does not point to '\0'
        destination[i+j] = source[j];  // append it to end of destination
        j++;
    }
    destination[i+j] = '\0'; // set null terminator for resulting string

   return destination;       // return resulting string

}

