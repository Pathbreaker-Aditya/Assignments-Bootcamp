#include<stdio.h>
#include<conio.h>
int factorial(int,int);
int main()
{
    int num,fact=1;
    printf("\n  The program will calculate the factorial of a number entered by the user.\n\n  ");
    printf("Enter the Number : ");
    scanf("%d",&num);

    fact=factorial(num,fact);
    printf("\n  %d! == %d",num,fact);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int factorial(int num,int fact)
{
    if(num>=1)
    {
        fact=fact*num;
        fact=factorial(num-1,fact);
    }
    return(fact);
}
