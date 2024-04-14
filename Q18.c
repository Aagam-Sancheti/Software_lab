#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100];

    printf("Enter the file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r+");

    uppercase_to_lowercase(file);

    fclose(file);
    return 0;
}

void uppercase_to_lowercase(FILE *file) {
    int ch;
    while ((ch = fgetc(file)) != EOF) {

        if ('A' <= ch && ch <= 'Z') {

            fputc(ch + ('a' - 'A'), file);
        }

        else if ('a' <= ch && ch <= 'z') {

            fputc(ch - ('a' - 'A'), file);
        }

        else {
            fputc(ch, file);
        }
    }
}
