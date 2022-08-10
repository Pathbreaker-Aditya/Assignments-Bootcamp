#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,k;
    printf("\n  Press any key to generate the pattern...\n\n");
    getch();

    for(i=4;i>=1;i--)
    {
        printf("\n  ");
        for(j=1;j<=4;j++)
        {
            if(j<=i)
                printf("%d",j);
            else
                printf(" ");
        }

        for(k=3;k>=1;k--)
            if(k<=i)
                printf("%d",k);
            else
                printf(" ");
    }

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
