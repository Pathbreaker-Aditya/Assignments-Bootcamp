#include<stdio.h>
#include<conio.h>
int main()
{
    int i,num_1,num_2;
    printf("\n  The program will print all the prime numbers between two numbers entered by the user.\n\n  ");
    printf("Enter the First Number : ");
    scanf("%d",&num_1);
    printf("  Enter the Second Number : ");
    scanf("%d",&num_2);

    printf("\n  All the prime numbers between %d and %d are as follows : \n  ",num_1,num_2);
    num_1++;
    num_2--;

    for(num_1;num_1<=num_2;num_1++)
    {
        for(i=2;i<=num_1;i++)
            if(num_1%i==0)
                break;
        if(i==num_1)
            printf("%d. ",num_1);
    }

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}
