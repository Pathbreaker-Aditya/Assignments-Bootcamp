#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,odd;
    printf("\n  Press any key to generate the pattern.\n  ");
    getch();

    for(odd=15,i=5;i>=1;i--)
    {
        printf("\n  ");
        for(j=1;j<=9;j++)
            if((i+j)<=5 || (i+j)>=odd)
                printf(" ");
            else
                printf("*");
        odd=odd-2;
    }
}

