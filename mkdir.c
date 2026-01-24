#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/********************************/
/** CORE UTILS REWRITE - mkdir **/
/********************************/
int main(int argc, char* argv[])
{
    if (argc != 2) {
        perror("Error: Invalid argument(s), provide one directory path");
        return -1;
    }
    
    char* directory = argv[1]; // directory to create

    if (mkdir(directory, 0755) != 0) {
        perror("Directory creation failed. Directory may already exist");
        return -1;
    }

    return 0;
}