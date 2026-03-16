#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

    if (argc < 3 || strcmp(argv[1], "cat") != 0) {
        printf("Failed, syntax error/lack of parameter.");
        return 0;
    }
    FILE *file_ptr;

    const char* path = argv[2];

    // open file 
    file_ptr = fopen(path, "r");

    if (file_ptr == NULL) {
        perror("Error openning file.");
        exit(1);
    }

    // get data from file and print out.
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
        printf("%s", buffer);
    } 

    // close file
    fclose(file_ptr);
    return 0;
}