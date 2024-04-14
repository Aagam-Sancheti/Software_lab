#include <stdio.h>


int main()
{
    char oldName[100], newName[100];

    printf("Enter old file path: ");
    scanf("%s", oldName);

    printf("Enter new file path: ");
    scanf("%s", newName);

   rename(oldName, newName);
    
    return 0;
}