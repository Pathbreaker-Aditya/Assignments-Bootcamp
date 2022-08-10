#include<stdio.h>
#include<conio.h>
int main()
{
    int i,j,k;
    printf("\n  Press any key to generate the pattern.\n\n  ");
    getch();

    for(i=4;i>=1;i--)
    {
        printf("\n  ");
        for(j=4;j>=1;j--)
        {
            if(j<=i)
            {
                for(k=1;k<=i;k++)
                    printf("%d",k);
                break;
            }
            else
                printf(" ");
        }

        for(k=1;k<i;k++)
            printf("%d",i-k);
    }
    printf("\n\n  Press any key to exit.");
    getch();
    return(0);
}
