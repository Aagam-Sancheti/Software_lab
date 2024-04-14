#include <stdio.h>

int main()
{
    FILE *sourceFile;
    FILE *destinationFile;
    char sourcePath[100];
    char destinationPath[100];

    char ch;

    printf("Enter source file path: ");
    scanf("%s", sourcePath);
    printf("Enter destination file path: ");
    scanf("%s", destinationPath);

    sourceFile= fopen(sourcePath,"r");
    destinationFile= fopen(destinationPath,"w");

    ch = fgetc(sourceFile);
    while (ch != EOF)
    {
        fputc(ch, destinationFile);
        ch = fgetc(sourceFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}