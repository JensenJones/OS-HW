//
// Created by Jensen on 6/01/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("wgrep: searchterm [file ...]\n");
        exit(EXIT_FAILURE);
    }

    regex_t regex;
    char *line = NULL;
    size_t lineLength;

    if (regcomp(&regex, argv[1], REG_EXTENDED)) {
        printf("Could not compile regex\n");
        regfree(&regex);
        exit(EXIT_FAILURE);
    }

    if (argc == 2) {
        while (getline(&line, &lineLength, stdin) != -1) {
            if (!regexec(&regex, line, 0, NULL, 0)) {
                printf("%s", line);
            }
        }
        regfree(&regex);
        exit(EXIT_SUCCESS);
    }

    for (int i = 2; i < argc; ++i) {
        FILE *file = fopen(argv[i], "r");

        if (file == NULL) {
            printf("wgrep: cannot open file\n");
            regfree(&regex);
            exit(EXIT_FAILURE);
        }

        while ((getline(&line, &lineLength, file)) != -1) {
            if (!regexec(&regex, line, 0, NULL, 0)) {
                printf("%s", line);
            }
        }

        fclose(file);
    }

    free(line);
    regfree(&regex);
    exit(EXIT_SUCCESS);
}