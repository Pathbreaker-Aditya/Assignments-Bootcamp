#include<stdio.h>
#include<conio.h>
int main()
{
    int dgts=0,sum=0,prod,num,n,i,dt;
    printf("\n  The program will check whether a number entered by the user\n  is an Armstrong Number or not.\n\n  ");
    printf("Enter the Number : ");
    scanf("%d",&num);

    n=num;
    while(n>0)
    {
        n=n/10;
        dgts++;
    }

    n=num;
    while(n>0)
    {
        dt=n%10;
        n=n/10;
        for(prod=1,i=1;i<=dgts;i++)
        {
            prod=prod*dt;
        }
        sum=sum+prod;
    }

    if(sum==num)
        printf("\n  %d is an Armstrong Number.",num);
    else
        printf("\n  %d is NOT an Armstrong Number.",num);

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}
