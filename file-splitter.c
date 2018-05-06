#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv){

        if(argc > 3){
                printf("invalid number of arguments\n");
                exit (1);
        }

	const char *path = *(argv+1);         	// user's file
	int newsize = *(argv+2);	    	// new file sizes
	// char *buffer = malloc(newsize*(sizeof(*buffer)));
	int filedesc = open(path, O_RDWR | O_CREAT);
	struct stat status;
	stat(path,&status);
	long long actualsize = status.st_size;
	long long numofparts = (status.st_size/newsize);

	if(filedesc < 0){
		return -1;
	}

	int counter = 1;

	while(actualsize > 0){

        	unsigned int readsize = (unsigned int) (actualsize <= newsize ? actualsize : newsize);
        	char *c = (char *) calloc(readsize, sizeof(char));
        	int temp1 = read(filedesc, c, readsize);
        	actualsize -= newsize;

        	char *str = malloc(500*(sizeof(*str)));
        	sprintf(str, "%s%d", *(argv+1), counter);
        	printf("%s\t\t%d\n", str, readsize);

        	int output = open(str, O_WRONLY | O_CREAT, S_IREAD | S_IWRITE);
        	counter++;
        	int temp2 = write(output, c, readsize);
        	close(output);
    	}


	close(filedesc);

	return 0;
}
