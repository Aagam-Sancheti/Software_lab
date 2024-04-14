#include<stdio.h>

int main()
{
    FILE* fpointer;

    fpointer= fopen("basic_file","w");

    fprintf(fpointer,"1 3 4 5 6 7 8 9 10 11");
    fclose(fpointer);
    return 0; 
}