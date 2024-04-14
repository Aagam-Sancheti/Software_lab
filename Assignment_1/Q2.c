#include<stdio.h>

int main()
{
    FILE *fptr = fopen("basic_file","r");
    char ch;

    while(ch != EOF)
    {
        ch= fgetc(fptr);
        printf("%c", ch);
    }
    fclose(fptr);
    return 0;
}