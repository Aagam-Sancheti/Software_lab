#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int indexOf(FILE *fptr, const char *word, int *line, int *column);

int main()
{
    FILE *fptr;
    char path[100];

    char word[50];

    int line, column;

    printf("Enter file path: ");
    scanf("%s", path);

    printf("Enter word to search in file: ");
    scanf("%s", word);

    fptr = fopen(path, "r");

    indexOf(fptr, word, &line, &column);

    if (line != -1)
        printf("'%s' found at line: %d, column: %d\n", word, line + 1, column + 1);
    else
        printf("'%s' does not exists.", word);
    
    fclose(fptr);

    return 0;
}

int indexOf(FILE *fptr, const char *word, int *line, int *column)
{
    char str[1000];
    char *pos;

    *line = -1;
    *column  = -1;

    while ((fgets(str, 1000, fptr)) != NULL)
    {
        *line += 1;

        pos = strstr(str, word);

        if (pos != NULL)
        {
            *column = (pos - str);
            break;
        }
    }

    if (*column == -1)
        *line = -1;

    return *column;
}