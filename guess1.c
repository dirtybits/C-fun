/* generate a random number between 1-10000 called key
 ask user to guess number between 1-10000
 if user gets correct number 'you guessed magic number'
 otherwise say 'incorrect try again'
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	int key;
	int input;

	srand(time(NULL));
	key = (rand() % 10000);

	// printf("%d\n",key);
	printf("Guess the magic number between 1-10000:\n");

	do{
		scanf("%d",&input);
		if(input != key) printf("Incorrect, try again:\n");
	}
	while(input != key);

	printf("You guessed the magic number!\n");

	return 0;

}
