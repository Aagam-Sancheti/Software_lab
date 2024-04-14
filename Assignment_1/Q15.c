#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE * fPtr;
    FILE * fTemp;
    char path[100];
    
    char arr[1000];
    char oldWord[100], newWord[100];


    printf("Enter path of source file: ");
    scanf("%s", path);

    printf("Enter word to replace: ");
    scanf("%s", oldWord);

    printf("Replace '%s' with: ");
    scanf("%s", newWord);

    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.tmp", "w"); 

    while ((fgets(arr, 1000, fPtr)) != NULL)
    {
        replaceAll(arr, oldWord, newWord);
        fputs(arr, fTemp);
    }

    fclose(fPtr);
    fclose(fTemp);

    remove(path);

    rename("replace.tmp", path);

    printf("\nSuccessfully replaced all occurrences of '%s' with '%s'.", oldWord, newWord);

    return 0;
}

void replaceAll(char *str, const char *oldWord, const char *newWord)
{
    char *pos, temp[1000];
    int index = 0;
    int owlen;

    owlen = strlen(oldWord);

    if (!strcmp(oldWord, newWord)) {
        return;
    }

    while ((pos = strstr(str, oldWord)) != NULL)
    {
        strcpy(temp, str);

        index = pos - str;

        str[index] = '\0';

        strcat(str, newWord);
        
        strcat(str, temp + index + owlen);
    }
}