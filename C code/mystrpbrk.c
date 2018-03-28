/* mystrpbrk example */
#include <stdio.h>
#include <string.h>

char * mystrpbrk (const char *, const char *);

int main (){
  
  char str[] = "This is a sample string";
  char key[] = "aeiou";
  char * pch;
  printf ("Vowels in '%s': ",str);
  pch = mystrpbrk (str, key);
  while (pch != NULL)
  {
    printf ("%c " , *pch);
    pch = mystrpbrk (pch+1,key);
  }
  printf ("\n");
  return 0;
}

char * mystrpbrk (const char *str1, const char *str2){
  
  int i = 0;
  int j = 0;
  
  char *ptr1 = (char*) str1; 
  char *ptr2 = (char*) str2; 

  while(ptr1[i]){

    j = 0;
    while(ptr2[j]){

      if(ptr1[i] == ptr2[j]){
        return &ptr1[i];
      }
      j++;
    }
    i++;
  }
  return NULL;
}