#include<stdio.h>
#include<conio.h>
int main()
{
    int i,num;
    printf("\n  The program will check whether a number entered by the user is prime or not.\n\n  ");
    printf("Enter the Number : ");
    scanf("%d",&num);

    for(i=2;i<=num;i++)
        if(num%i==0)
            break;
    if(i==num)
        printf("\n  %d is a prime number.",num);
    else
        printf("\n  %d is NOT a prime number.",num);

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}
