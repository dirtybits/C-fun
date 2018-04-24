#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


int main(void)
{


	do{

		system("clear");

		srand(time(NULL));
		int r = rand();
		time_t mytime = time(NULL);
		char * time_str = ctime(&mytime);
		time_str[strlen(time_str)-1] = '\0';

		printf("Current Time : %s\n\n", time_str);
		system("cal");
		printf("Random Number: %d\n\n", r);

		fflush(stdout);

		sleep(1);


	}while(1);

        return 0;
}

