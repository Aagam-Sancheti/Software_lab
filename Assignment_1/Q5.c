#include <stdio.h>
#include <stdlib.h>

int compareFile(FILE * fPtr1, FILE * fPtr2, int * line, int * column);

int main()
{
    FILE * fPtr1; 
    FILE * fPtr2;
    char arr1[100];
    char arr2[100];

    int diff;
    int line, column;


    printf("Enter path of first file: ");
    scanf("%s", arr1);
    printf("Enter path of second file: ");
    scanf("%s", arr2);

    fPtr1 = fopen(arr1, "w");
    fPtr2 = fopen(arr2, "w");

    diff = compareFile(fPtr1, fPtr2, &line, &column);

    if (diff == 0)
    {
        printf("\nBoth files are equal.");
    }
    else 
    {
        printf("\nFiles are not equal.\n");
        printf("Line: %d, col: %d\n", line, column);
    }

    fclose(fPtr1);
    fclose(fPtr2);

    return 0;
}

int compareFile(FILE * fPtr1, FILE * fPtr2, int * line, int * column)
{
    char ch1, ch2;

    *line = 1;
    *column  = 0;

    do
    {
        ch1 = fgetc(fPtr1);
        ch2 = fgetc(fPtr2);
    
        if (ch1 == '\n')
        {
            *line+=1;
            *column = 0;
        }

        if (ch1 != ch2)
            return -1;

        *column  += 1;

    } while (ch1 != EOF && ch2 != EOF);

    if (ch1 == EOF && ch2 == EOF)
        return 0;
    else
        return -1;
}