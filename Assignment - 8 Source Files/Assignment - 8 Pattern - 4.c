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
        j=5;
        while(j)
        {
            if(j<=i)
                printf("*"); // If you give a space before or after the star in this printf() (like this ("* ") or (" *"),
                             // it will result in the inverted pyramid pattern.
            else
                printf(" ");
            j--;
        }
    }
}


