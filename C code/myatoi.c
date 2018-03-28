/* atoi example */
#include <stdio.h>      /* printf, fgets */
// #include <stdlib.h>     /* atoi */
#include <string.h>

int myatoi(const char * str);

int main ()
{
  int i;
  char buffer[256];
  printf ("Enter a number: ");
  fgets (buffer, 256, stdin);
  i = myatoi (buffer);
  printf ("The value entered is %d. Its double is %d.\n",i,i*2);
//  i = atoi (buffer);
//  printf ("The value entered is %d. Its double is %d.\n",i,i*2);
  return 0;

}

int myatoi(const char* str){

    int i = 0;       // initilize counter variable
    int num = 0;     // initilize resulting number
    int sign = 1;    // sign of result     

    if (str == NULL)           // if string is null return 0;
        return 0;
    if (str[0] == '-'){         // if initial char is '-'
        sign = -1;              // set sign to negative
        i++;                    // update so we don't get stuck in loop
    }
    else if (str[0] == '+'){    // if initial char is '+' skip to next element
        i++;                    
    }
    while(isdigit(str[i])){      // iterate through string      
        num = (num*10) + (str[i] - '0');
        i++;
    }
    return sign*num;
}

/* btw you never have to do  != '\0' 
https://repl.it/repls/GregariousClientsideProgrammingtool
*/
