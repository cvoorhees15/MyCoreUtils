#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

/******************************/
/** CORE UTILS REWRITE - cat **/
/******************************/
int main (int argc, char* argv[])
{
    // validate input
    if (argc != 2) {        
        perror("Error: Invalid argument(s), provide one file path.");
        return -1;
    }

    struct stat file_stat;      // file info
    char*  file_path = argv[1]; // file path
    size_t buffer_size;         // buffer for file data
    int    fd;                  // file descriptor

    // get input file info
    if (stat(argv[1], &file_stat) == 0) {
        buffer_size = file_stat.st_size;
    }
    else {
        printf("File %s not found.", file_path);
        return -1;
    }

    // open input file
    fd = open(file_path, O_RDONLY, 0644);
        
    if (fd == -1) {
        perror("Error opening file");
        return -1;
    }

    // read input file
    char* read_buffer = malloc(buffer_size + 1);
    ssize_t bytes_read = read(fd, read_buffer, buffer_size);
    read_buffer[bytes_read] = '\0';

    if (bytes_read == -1) {
        perror("Error reading from file");
        free(read_buffer);
        close(fd);
        return -1;
    }

    printf("%s", read_buffer);

    // close input file
    if (close(fd) == -1) {
        perror("Error closing file");
        free(read_buffer);
        return -1;
    }

    free(read_buffer);
    return 0;
}