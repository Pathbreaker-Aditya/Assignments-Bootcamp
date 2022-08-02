#include<stdio.h>
#include<conio.h>
int main()
{
    int i,N,sum;
    printf("\n  The program will calculate the sum of squares of first N natural numbers,\n  N being given by user.\n\n  ");
    printf("Enter the Value of N : ");
    scanf("%d",&N);

    for(sum=0,i=1;i<=N;i++)
    {
        sum=sum+i*i;
    }
    printf("\n  The Sum of squares of First %d natural numbers == %d",N,sum);
    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}


