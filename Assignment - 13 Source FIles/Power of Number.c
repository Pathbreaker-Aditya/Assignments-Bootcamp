#include<stdio.h>
#include<conio.h>
int num_power(int,int,int,int);
int main()
{
    int num,power,value=1,i=1;
    printf("\n  The program will calculate the value of a number carried to any exponent,\n  where both the number and the power are specified by the user.\n\n  ");
    printf("Enter the Number : ");
    scanf("%d",&num);
    printf("  Enter the Power : ");
    scanf("%d",&power);

    value=num_power(num,power,i,value);
    printf("\n  %d^%d == %d",num,power,value);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int num_power(int num,int power,int i,int value)
{
    if(i<=power)
    {
        value=value*num;
        i++;
        value=num_power(num,power,i,value);
    }
    return(value);
}
