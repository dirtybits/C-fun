--- Assignment 3 ---


***mystrcat.c***

mystrcat takes two strings and concatanates them to each other.
For example:

char str1[30] = "this is";
char str2[30] = " one string";
mystrcat(str1, str2);
printf("%s",str1);

"this is one string"

***mystrchr.c***

mystrchr finds the first instance of the target char in the given string and returns the index it was found at.
For example:

char str[] = "Search for char";
ptr = mystrchr(str,'c');
 while (ptr != NULL){
        printf ("found at %d\n",ptr-str+1);
        ptr = mystrchr(ptr+1,'f');
 }


***myatoi.c***

myatoi turns a char array into an int
For example:
i = myatoi (buffer);
  printf ("The value entered is %d. Its double is %d.\n",i,i*2);

***mystrpbrk.c***

finds the first occurance of any char in a target string using an input string

  char str[] = "This is a sample string";
  char key[] = "aeiou";
  char * pch;
  printf ("Vowels in '%s': ",str);
  pch = mystrpbrk (str, key);
  printf ("%c " , *pch);

***mycd.c***
prints current directory, changes you to target directory, and prints the
directory of the directory moved to
Current directory: /Documents
Current directory: ~/








