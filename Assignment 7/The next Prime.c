#include<stdio.h>
#include<conio.h>
int main()
{
    int i,num;
    printf("\n  The program will print the prime number that comes just after the number entered by the user.\n\n  ");
    printf("Enter the Number : ");
    scanf("%d",&num);

    printf("\n  The Prime number after %d == ",num);
    num++;
    for(num;num;num++)
    {
        for(i=2;i<=num;i++)
            if(num%i==0)
                break;
        if(i==num)
        {
            printf("%d",num);
            break;
        }
    }

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}
