#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc < 3 || strcmp(argv[1], "cat") != 0) {
        printf("Failed, syntax error/lack of parameter.");
        return 0;
    }
    const char *path = argv[2];

    int fd = open(path, O_RDONLY);

    if (fd == -1) {
        perror("Error openning file.");
        return 0;
    }

    char buffer[1024];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(1, buffer, bytes_read);
    }

    if (bytes_read == -1) {
        perror("Error reading file.");
    }

    close(fd);
    
    return 0;
}
