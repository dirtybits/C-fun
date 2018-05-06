#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){

	int input;
	char *path = malloc(128*(sizeof(*path)));
	struct stat status;

	printf("Hello, please enter the file name:\n");
	scanf("%s", path);
	printf("Now please enter one of the following commands:\n");
	do{
		printf("Enter 1 for the file's name\n");
		printf("Enter 2 for the file's inode number\n");
		printf("Enter 3 for the file's size (in bytes)\n");
		printf("Enter 4 to quit the program\n");
		scanf("%d", &input);

		if(stat(path, &status) == 0){
			printf("------------------------------------\n");
			if(input == 1){
				printf("filename: %s\n", path);
			}else if(input == 2){
				int inode = status.st_ino;
                        	printf("inode: %d\n", inode);
			}else if(input == 3){
				int size = status.st_size;
				printf("size: %d (bytes)\n", size);
			}else if(input == 4){
				printf("the program is now exiting, goodbye.\n");
			}else{
				printf("please enter a valid option\n");

			}
			printf("------------------------------------\n");
		}
		else{
			printf("File does not exist or cannot be located\n");
		}
	}while(input != 4);

	free(path);

	return 0;
}


