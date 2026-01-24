#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

/*****************************/
/** CORE UTILS REWRITE - cp **/
/*****************************/
int main (int argc, char* argv[])
{
    if (argc != 3)
    {
        perror("Error: Invalid argument(s), provide an existing file path, followed by a destination path");
        return -1;
    }

    int fd_src;                      // source file descriptor
    int fd_dest;                     // destination file descriptor

    char* file_src = argv[1];        // source file path
    char* file_dest = argv[2];       // destination file path

    size_t BUFFER_SIZE = 4096;       // 4kb
    char buffer[BUFFER_SIZE];        // 4kb buffer
    ssize_t bytes_read;              // bytes read from source file
    ssize_t bytes_written;           // bytes written to destination file

    // open source & destination files
    fd_src = open(file_src, O_RDONLY);
    fd_dest = open(file_dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd_src == -1) {
        perror("Error opening source file");
        return -1;
    }

    do {
        bytes_read = read(fd_src, buffer, BUFFER_SIZE);

        if (bytes_read == -1) {
            perror("Error reading from source file");
            return -1;
        }

        bytes_written = write(fd_dest, buffer, bytes_read);

        if (bytes_written == -1) {
            perror("Error writing to destination file");
            return -1;
        }
    }
    while(bytes_read > 0);

    if (close(fd_src) == -1) {
        perror("Error closing source file");
        return -1;
    }

    if (close(fd_dest) == -1) {
        perror("Error closing destination file");
        return -1;
    }

    return 0;
}