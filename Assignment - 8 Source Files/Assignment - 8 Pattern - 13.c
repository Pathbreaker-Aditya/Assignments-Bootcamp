#include<stdio.h>
#include<conio.h>
int main()
{
    char i,j,k;
    printf("\n  Press any key to generate pattern.\n\n");
    getch();

    for(i=71;i>=65;i--)
    {
        printf("\n  ");
        for(j=65;j<=71;j++)
            if(j<=i)
                printf("%c",j);
            else
                printf(" ");

        for(k=70;k>=65;k--)
        {
            if(k<=i)
                printf("%c",k);
            else
                printf(" ");
        }
    }
    printf("\n\n  Press any key to exit program.\n\n");
    getch();
    return(0);
}
