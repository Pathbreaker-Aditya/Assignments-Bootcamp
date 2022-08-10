#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j;
    printf("\n  Press any key to generate the pattern.\n\n");
    getch();

    for(i=1;i<=5;i++)
    {
        printf("\n  ");
        for(j=1;j<=i;j++)
            if(i*j==6 || i*j==8 || i*j==12)
                printf("  ");
            else
                printf(" *");
    }
    printf("\n\n  Press any key to exit program.\n\n");
    getch();
    return(0);
}
