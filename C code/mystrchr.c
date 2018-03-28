#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mystrchr(const char *str, int character);

int main(){

    char str[] = "Search for a character in this text!";
    char *ptr;

    /* using cppreference example
    printf ("Looking for the 'a' character in \"%s\"...\n",str);
    ptr = strchr(str,'a');
    printf("%p\n", ptr);

    while (ptr != NULL){
        printf ("found at %d\n",ptr-str+1);
        ptr = strchr(ptr+1,'a');
    }
    */

    // using mystrchr fucntion    
    printf ("Looking for the 'f' character in \"%s\"...\n",str);
    ptr = mystrchr(str,'f');

    while (ptr != NULL){
        printf ("found at %d\n",ptr-str+1);
        ptr = mystrchr(ptr+1,'f');
    }


    return 0;
}

char *mystrchr (const char *str, int character){

    char *ptr = (char*) str;       // cast away constness of str pointer
    int i = 0;

    while (ptr[i] != '\0'){
        if (ptr[i] == character){ // if the char is found
            return &ptr[i];       // return the address it was found at
        }                         // and exit function
        i++;                    
    }
    return NULL;                    
}