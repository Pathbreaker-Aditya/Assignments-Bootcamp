#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,k,odd;
    printf("\n  Press any key generate the pattern.\n\n");
    getch();

    for(odd=7,i=1;i<=5;i++)
    {
        printf("\n\n  ");
        for(j=1;j<=9;j++)
        {
            if((i+j<=5) || (i+j>=odd))
                printf("  ");
            else
                printf("* ");
        }
        odd=odd+2;
    }

    for(odd=13,k=4;k>=1;k--)
    {
        printf("\n\n  ");
        for(j=1;j<=9;j++)
        {
            if((k+j<=5) || (k+j>=odd))
                printf("  ");
            else
                printf("* ");
        }
        odd=odd-2;
    }
    printf("\n\n  Press any key to exit program.\n\n");
    getch();
    return(0);
}


