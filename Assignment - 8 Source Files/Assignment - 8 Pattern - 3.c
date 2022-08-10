#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j;
    printf("\n  Press any key to generate the pattern.\n  ");
    getch();
    for(i=5;i>=1;i--)
    {
        printf("\n  ");
        for(j=1;j<=i;j++)
            printf("*");
    }
    printf("\n\n  ");
    getch();
    return(0);
}

/*
    j=1;
        while(j<=5)
        {
            if(j<=i)
                printf("*");
            else
                printf(" ");
            j++;
        }
*/

