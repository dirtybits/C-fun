/* generate a random number between 1-10000 called key
 ask user to guess number between 1-10000
 if user gets correct number 'you guessed magic number'
 otherwise say 'incorrect try again'
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

void sig_handler(int); // Catches SIGINT and produces message

int main(){

	int key;
	int input;

	srand(time(NULL));
	key = (rand() % 10000);

	// printf("%d\n",key);
	printf("Guess the magic number between 1-10000:\n");

	do{
		scanf("%d",&input);
		if(input != key)
			printf("Incorrect, try again:\n");
		if(signal(SIGINT, sig_handler) == SIG_ERR);
	}
	while(input != key);

	printf("You guessed the magic number!\n");

	return 0;

}

void sig_handler(int signo){
	if(signo == SIGINT)
		printf("\nreceived SIGINT, please guess again:\n");
}
