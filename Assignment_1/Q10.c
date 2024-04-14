#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *source;
    FILE *tempFile;

    char path[100];
    int Linenumber;

    printf("Enter file path: ");
    scanf("%s", path);

    printf("Enter Linenumber number to remove: ");
    scanf("%d", &Linenumber);

    source  = fopen(path, "r");
    tempFile = fopen("delete-Linenumber.tmp", "w");

    deleteLinenumber(source, tempFile, Linenumber);

    fclose(source);
    fclose(tempFile);

    remove(path);
    rename("delete-Linenumber.tmp", path);

    source = fopen(path, "r");
    printFile(source);
    fclose(source);

    return 0;
}

void deleteLinenumber(FILE *source, FILE *tempFile, const int Linenumber)
{
    char arr[1000];
    int count = 1;

    while ((fgets(arr, 1000, source)) != NULL)
    {
        if (Linenumber != count)
            fputs(arr, tempFile);
            
        count++;
    }
}