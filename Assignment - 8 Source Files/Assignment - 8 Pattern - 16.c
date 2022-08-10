#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,odd;
    printf("\n  Press any key generate the pattern.\n\n");
    getch();

    for(odd=7,i=1;i<=5;i++)
    {
        printf("\n\n  ");
        for(j=1;j<=9;j++)
        {
            if((i+j<=5) || (i+j>=odd) || ((i>=2 && i<=4) && (i+j>=7 && i+j<=(odd-2))))
                printf("  ");
            else
                printf("* ");
        }
        odd=odd+2;
    }
    printf("\n\n  Press any key to exit program.\n\n");
    getch();
    return(0);
}

