#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100];
    int lineNumber;
    char newContent[1000];

    printf("Enter the file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    printf("Enter the line number to replace: ");
    scanf("%d", &lineNumber);

    getchar();

    printf("Enter the new content: ");
    fgets(newContent, sizeof(newContent), stdin);

    replaceLine(file, lineNumber, newContent);
    fclose(file);

    printf("Line %d replaced successfully.\n", lineNumber);

    return 0;
}

void replaceLine(FILE *file, int lineNumber, const char *newContent) {
    char arr[1000];
    FILE *tempFile = tmpfile(); 
 
    rewind(file);

    for (int currentLine = 1; fgets(arr, sizeof(arr), file) != NULL; ++currentLine) {
        if (currentLine == lineNumber) {
            fputs(newContent, tempFile);
        } else {
            fputs(arr, tempFile);
        }
    }

    rewind(file);
    rewind(tempFile);

    while (fgets(arr, sizeof(arr), tempFile) != NULL) {
        fputs(arr, file);
    }

    fclose(tempFile);
}
