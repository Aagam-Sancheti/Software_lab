#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    FILE *fptr;
    char path[100];
    int i, len, index, isUnique;

    char words[1000][50];
    char word[50];

    int  count[1000];

    printf("Enter file path: ");
    scanf("%s", path);

    fptr = fopen(path, "r");

    for (i=0; i<1000; i++)
        count[i] = 0;

    index = 0;
    
    while (fscanf(fptr, "%s", word) != EOF)
    {
        strlwr(word);
        len = strlen(word);

        if (ispunct(word[len - 1]))
            word[len - 1] = '\0';

        isUnique = 1;
        for (i=0; i<index && isUnique; i++)
        {
            if (strcmp(words[i], word) == 0)
                isUnique = 0;
        }

        if (isUnique) 
        {
            strcpy(words[index], word);
            count[index]++;

            index++;
        }
        else
        {
            count[i - 1]++;
        }
    }

    fclose(fptr);

    for (i=0; i<index; i++)
    {
        printf("%-15s => %d\n", words[i], count[i]);
    }    
    return 0;
}