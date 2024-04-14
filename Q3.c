#include<stdio.h>

int main()
{
    FILE *readfile = fopen("basic_file","r");

    int ch;
    int totalcount=0;
    int arr[1000];
   for(int i=0; ch!=EOF; i++)
    {
        ch= fgetc(readfile);
        arr[i]=ch;
        totalcount++;
    }

    int evenarr[1000];
    int evencount=0;
    for(int i=0 ; arr[i]==0; i++)
    {
        if(arr[i]%2==0)
        {
            evenarr[evencount]=arr[i];
            evencount++;
        }
    }

    int oddarr[1000];
    int oddcount=0;
    for(int i=0 ; arr[i]==0; i++)
    {
        if(arr[i]%2!=0)
        {
            oddarr[oddcount]=arr[i];
            oddcount++;
        }
    }

    int primearr[1000];
    int primecount=0;
    for (int i=0; i<totalcount; i++)
    {
        if(arr[i]<0)
        {
            continue;
        }
        else
        {
            for(int k=2; k<=arr[i]; k++)
            {
                if(arr[i]%k!=0)
                {
                    primearr[k]=arr[i];
                    primecount++;
                }
                else 
                continue;
            }
        }
    }
    FILE *fptr1 = fopen("odd numbers","w");
    
    for(int i=0; i<evencount; i++)
    {
        fputs(("%d",evenarr[i]),fptr1);
    }

    FILE *fptr2 = fopen("even numbers","w");
    
    for(int i=0; i<oddcount; i++)
    {
        fputs(("%d", oddarr[i]), fptr2);
    }

    FILE *fptr3 = fopen("prime numbers","w");

    for(int i=0; i<primecount; i++)
    {
        fputs(("%d",primearr[i]), fptr3);
    }

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    
    return 0;
}