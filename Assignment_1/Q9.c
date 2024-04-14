#include <stdio.h>
#include <string.h>

int main()
{
    FILE * fPtr;
    FILE * fTemp;
    char path[100];
    
    char toRemove[100];
    char arr1[1000];

    printf("Enter path of source file: ");
    scanf("%s", path);

    printf("Enter word to remove: ");
    scanf("%s", toRemove);

    fPtr  = fopen(path, "r");
    fTemp = fopen("delete.temporary", "w"); 

    while ((fgets(arr1, 1000, fPtr)) != NULL)
    {
        removeword(arr1, toRemove);
        fputs(arr1, fTemp);
    }

    fclose(fPtr);
    fclose(fTemp);

    remove(path);
    rename("delete.tmp", path);

    return 0;
}

void removeword(char * str, const char * toRemove)
{
    int i, j, stringLen, toRemoveLen;
    int found;

    stringLen   = strlen(str);  
    toRemoveLen = strlen(toRemove);


    for(i=0; i<=stringLen - toRemoveLen; i++)
    {
        found = 1;
        for(j=0; j < toRemoveLen; j++)
        {
            if(str[i + j] != toRemove[j])
            {
                found = 0;
                break;
            }
        }

        if(str[i + j] != ' ' && str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0') 
        {
            found = 0;
        }

        if(found == 1)
        {
            for(j=i; j <= stringLen - toRemoveLen; j++)
            {
                str[j] = str[j + toRemoveLen];
            }

            stringLen = stringLen - toRemoveLen;

            i--;
        }
    }
}