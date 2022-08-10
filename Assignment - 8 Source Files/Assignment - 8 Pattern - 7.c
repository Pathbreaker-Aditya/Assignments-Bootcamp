#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,k;
    printf("\n  Press any key to generate the pattern.\n\n");
    getch();

    for(i=1;i<=5;i++)
    {
        printf("\n  ");
        for(j=5;j>=1;j--)
            if(j>=i)
                printf("*");
            else
                printf(" ");

        for(k=1;k<=5;k++)
            if(k>=i)
                printf("*");
            else
                printf(" ");
    }

    printf("\n\n  ");
    getch();
    return(0);
}
