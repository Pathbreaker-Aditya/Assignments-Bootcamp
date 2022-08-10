#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,k,odd;
    printf("\n  Press any key to generate the pattern.\n\n");
    getch();

    for(odd=9,i=1;i<=3;i++)
    {
        printf("\n  ");
        for(k=1;k<=2;k++)
        {
            for(j=1;j<=9;j++)
                if((i+j<4) || (i+j>=odd))
                    printf(" ");
                else
                    printf("*");
            printf(" ");
        }
        odd=odd+2;
    }

    for(odd=29,k=10;k>=1;k--)
    {
        if(odd==29)
        {
            printf("\n  ");
            for(j=1;j<=19;j++)
            {
                if(j<=6 || j>=13)
                    printf("*");
                else
                {
                    printf("MySirG");
                    j=12;
                }
            }
            odd=odd-2;
            continue; // This continue is the stabilizer of the pattern starting from MySirG row
                      // and going upto the last star.
        }
        printf("\n   ");
        for(j=1;j<=19;j++)
            if((k+j<=9) || (k+j>=odd))
                printf(" ");
            else
                printf("*");
        odd=odd-2;
    }
}
