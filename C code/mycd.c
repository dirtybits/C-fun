#include <stdio.h>
#include <unistd.h>

main() {
    
    char buf[1024];
    char *directory = "";

    getcwd(buf,sizeof(buf));
    printf("Current directory: %s\n", buf);
    chdir("..");
    getcwd(buf,sizeof(buf));
    printf("Current directory: %s\n", buf);

    return 0;

}