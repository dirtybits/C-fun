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
		printf("Enter 2 for the file's type\n");
		printf("Enter 3 for the file's permissions\n");
		printf("Enter 4 to quit the program\n");
		scanf("%d", &input);

		if(stat(path, &status) == 0){
			printf("------------------------------------\n");
			if(input == 1){
				printf("Filename: %s\n", path);
			}else if(input == 2){

				if(S_ISREG(status.st_mode)){
					printf("This is a regular file\n");
				}
                        	else if(S_ISDIR(status.st_mode)){
					printf("This is a directory\n");
				}
				else if(S_ISCHR(status.st_mode)){
					printf("This is a character device\n");
				}
				else if(S_ISBLK(status.st_mode)){
					printf("This is a block device\n");
				}
 				else if(S_ISFIFO(status.st_mode)){
					printf("This is a FIFO (named pipe)\n");
                                }
				else if(S_ISLNK(status.st_mode)){
					printf("This is a symbolic link\n");
                                }
				else if(S_ISSOCK(status.st_mode)){
					printf("This is a socket\n");
                                }

			}else if(input == 3){
				printf("File permissions:\n");
				printf((S_ISDIR(status.st_mode)) ? "d" : "-");
				printf((status.st_mode & S_IRUSR) ? "r" : "-");
				printf((status.st_mode & S_IWUSR) ? "w" : "-");
				printf((status.st_mode & S_IXUSR) ? "x" : "-");
                 		printf((status.st_mode & S_IRGRP) ? "r" : "-");
				printf((status.st_mode & S_IWGRP) ? "w" : "-");
				printf((status.st_mode & S_IXGRP) ? "x" : "-");
  				printf((status.st_mode & S_IROTH) ? "r" : "-");
    				printf((status.st_mode & S_IWOTH) ? "w" : "-");
			        printf((status.st_mode & S_IXOTH) ? "x" : "-");
				printf("\n");
			}else if(input == 4){
				printf("The program is now exiting, goodbye.\n");
			}else{
				printf("Please enter a valid option\n");

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


