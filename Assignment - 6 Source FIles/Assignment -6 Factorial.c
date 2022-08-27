#include<stdio.h>
#include<conio.h>
int main()
{
    int i,N,fact;
    printf("\n  The program will calculate the factorial of a number entered by the user.\n\n  ");
    printf("Enter the Number : ");
    scanf("%d",&N);

    for(fact=1,i=1;i<=N;i++)
        fact=fact*i;
    printf("\n  %d! == %d",N,fact);
    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

