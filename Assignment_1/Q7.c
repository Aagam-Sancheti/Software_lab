#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *sourceFile1;
    FILE *sourceFile2;
    FILE *destinationFile;
    char sourcePath1[100];
    char sourcePath2[100];
    char destinationPath[100];

    char ch;

    printf("Enter first source file path: ");
    scanf("%s", sourcePath1);
    printf("Enter second source file path: ");
    scanf("%s", sourcePath2);
    printf("Enter destination file path: ");
    scanf("%s", destinationPath);

    sourceFile1 = fopen(sourcePath1, "r");
    sourceFile2 = fopen(sourcePath2, "r");
    destinationFile = fopen(destinationPath,"w");

    while ((ch = fgetc(sourceFile1)) != EOF)
        fputc(ch, destinationFile);

    while ((ch = fgetc(sourceFile2)) != EOF)
        fputc(ch, destinationFile);

    fclose(sourceFile1);
    fclose(sourceFile2);
    fclose(destinationFile);

    return 0;
}