#include<stdio.h>
#include<conio.h>
int main()
{
    int dgts,sum,prod,num,n,i,dt;
    printf("\n  The program will check whether a number entered by the user\n  is an Armstrong Number or not.\n\n  ");
    printf("Press any key to execute the program.\n\n  ");
    getch();

    printf("\n  ");
    for(num=0;num<=1000;num++)
    {
        sum=dgts=0;
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
            printf("%d. ",num);
    }

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}

