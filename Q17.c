#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fPtr;
    char ch;
    fPtr = fopen(__FILE__, "r");

    while ((ch = fgetc(fPtr)) != EOF)
    {
        printf("%c", ch);
    }
    
    fclose(fPtr);

    return 0;
}