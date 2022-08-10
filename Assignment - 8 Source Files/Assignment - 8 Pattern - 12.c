#include<stdio.h>
#include<conio.h>
int main()
{
    char i,j,k;
    printf("\n Press any key to generate the pattern.\n\n");
    getch();

    for(i=68;i>=65;i--)
    {
        printf("\n  ");
        for(j=68;j>=65;j--)
        {
            if(i==j)
            {
                for(k=65;k<=i;k++)
                    printf("%c",k);
                break;
            }
            else
                printf(" ");
        }

        for(j=1,k=65;k<i;k++)
        {
            printf("%c",i-j);
            j++;
        }
    }
    printf("\n\n  Press any key to exit program.\n\n");
    getch();
    return(0);
}
