#include<stdio.h>
#include<conio.h>
int main ()
{
    int i,j;
    printf("\n  Press any key to generate pattern\n  ");
    getch();
    for(i=1;i<=5;i++)
    {
        printf("\n  ");
        for(j=1;j<=i;j++)
            printf("*");
    }
    printf("\n\n  ");
    getch();
    return(0);
}
