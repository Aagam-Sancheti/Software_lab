#include<stdio.h>

int main()
{
    FILE *file= fopen("basic_file","a");

    char ch = 'A';
    fprintf(file,"\n %c", ch);
    fclose(file);
    return 0;
}