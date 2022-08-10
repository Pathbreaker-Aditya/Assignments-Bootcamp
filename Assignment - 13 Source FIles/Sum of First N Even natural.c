#include<stdio.h>
#include<conio.h>
int sum_even_natural(int,int);
int main()
{
    int n,sum=0;
    printf("\n  The program will print the sum of First N Even natural numbers requested by the user.\n\n  ");
    printf("Enter the value of N : ");
    scanf("%d",&n);

    sum=sum_even_natural(n,sum);
    printf("\n  Sum of First %d Even natural numbers == %d",n,sum);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int sum_even_natural(int n,int sum)
{
    if(n>=1)
    {
        sum=sum+(2*n);
        sum=sum_even_natural(n-1,sum);
    }
    return(sum);
}

