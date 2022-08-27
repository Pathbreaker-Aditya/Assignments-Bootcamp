#include<stdio.h>
#include<conio.h>
void greatest(int*,int*);
int main()
{
    int a,b;
    printf("\n The program will find the greatest between two numbers with the help of pointers.");
    printf("\n\n  Enter First Number : ");
    scanf("%d",&a);
    printf("\n  Enter Second Number : ");
    scanf("%d",&b);

    greatest(&a,&b);

    printf("\n\n  Press any key to exit program.");
    getch();
    return(0);
}

void greatest(int *a,int *b)
{
    if(*a==*b)
        printf("\n  Numbers are equal,*a,*b);
    else if(*a>*b)
        printf("\n  %d is greater.",*a);
    else
        printf("\n  %d is greater.",*b);
}
