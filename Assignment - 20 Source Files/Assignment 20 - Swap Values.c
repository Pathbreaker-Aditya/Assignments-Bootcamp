#include<stdio.h>
#include<conio.h>
void swap(int*,int*);
int main()
{
    int a,b;
    printf("\n  The program will swap the values of two variables 'a' and 'b'.\n\n  ");

    printf("Enter an integer in 'a' : ");
    scanf("%d",&a);
    printf("  Enter an integer in 'b' : ");
    scanf("%d",&b);

    printf("\n  Values before swapping : 'a'==%d, 'b'==%d.",a,b);
    swap(&a,&b);
    printf("\n  Values after swapping : 'a'==%d, 'b'==%d.",a,b);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void swap(int *x,int *y)
{
    *x=*x+*y;
    *y=*x-*y;
    *x=*x-*y;
}
