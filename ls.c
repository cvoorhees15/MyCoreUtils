#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <dirent.h>

/*****************************/
/** CORE UTILS REWRITE - ls **/
/*****************************/
int main (int argc, char* argv[])
{
    char path[PATH_MAX]; 

    if (argc > 2) {
        perror("Error: Invalid argument(s), provide one path");
        return -1;
    }
    else if (argc < 2) {
        if (getcwd(path, sizeof(path)) == NULL) { // use current working directory
            perror("Error: Could not list current working directory");
            return -1;
        }
    }
    else {
        strcpy(path, argv[1]); // copy provided directory into path var
    }

    // open provided directory 
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("Error: Directory cannot be accessed");
        return -1;
    }

    // print all dir entries within the provided dir
    struct dirent* dir_entry;
    while ((dir_entry = readdir(dir)) != NULL) {
        printf("%s\n", dir_entry->d_name);
    }

    // close provided directory
    if (closedir(dir) == -1) {
        perror("Error closing directory");
        return -1;
    }

    return 0;
}