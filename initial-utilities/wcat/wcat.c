//
// Created by Jensen on 5/01/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char c;
    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }

    return 0;
}