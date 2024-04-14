#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *sourcefile;
    FILE *tempFile;

    char path[100];

    printf("Enter file path: ");
    scanf("%s", path);

    sourcefile  = fopen(path, "r");
    tempFile = fopen("remove-blanks.temp", "w");

    removeEmptyLines(sourcefile, tempFile);

    fclose(sourcefile);
    fclose(tempFile);

    remove(path);
    rename("remove-blanks.tmp", path);

    printf("\n\n\nFile contents after removing all empty line.\n\n");

    sourcefile = fopen(path, "r");
    printFile(sourcefile);
    fclose(sourcefile);

    return 0;
}

void printFile(FILE *fptr)
{
    char ch;

    while((ch = fgetc(fptr)) != EOF)
        putchar(ch);
}

int isEmpty(const char *str)
{
    char ch;

    do
    {
        ch = *(str++);
        if(ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r' && ch != '\0')
            return 0;

    } while (ch != '\0');

    return 1;
}
void removeEmptyLines(FILE *sourcefile, FILE *tempFile)
{
    char arr[1000];

    while ((fgets(arr,1000, sourcefile)) != NULL)
    {
        if(!isEmpty(arr))
            fputs(arr, tempFile);
    }
}