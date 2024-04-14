#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr;
    char path[100];

    char word[50];

    int wordcount;

    printf("Enter file path: ");
    scanf("%s", path);

    printf("Enter word to search in file: ");
    scanf("%s", word);

    fptr = fopen(path, "r");

    wordcount = countOccurrences(fptr, word);

    printf("'%s' is found %d times in file.", word, wordcount);

    fclose(fptr);

    return 0;
}

int countOccurrences(FILE *fptr, const char *word)
{
    char str[1000];
    char *pos;

    int index, count;
    
    count = 0;

    while ((fgets(str, 1000, fptr)) != NULL)
    {
        index = 0;
        while ((pos = strstr(str + index, word)) != NULL)
        {
            index = (pos - str) + 1;

            count++;
        }
    }

    return count;
}