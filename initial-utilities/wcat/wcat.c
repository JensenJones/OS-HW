//
// Created by Jensen on 5/01/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        FILE *file = fopen(argv[i], "r");

        if (file == NULL) {
            printf("wcat: cannot open file\n");
            exit(EXIT_FAILURE);
        }

        char line[1000];

        while ((fgets(line, sizeof(line), file))) {
            printf("%s", line);
        }

        fclose(file);
    }

    exit(EXIT_SUCCESS);
}