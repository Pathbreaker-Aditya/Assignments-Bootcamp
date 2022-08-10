#include<stdio.h>
#include<conio.h>
int digital_sum(int);
int main()
{
    int num,d_sum;
    printf("\n  The program will calculate the sum of digits of a number entered by the user.\n\n  ");
    printf("Enter the Number : ");
    scanf("%d",&num);

    d_sum=digital_sum(num);
    printf("\n  The sum of digits of %d == %d",num,d_sum);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int digital_sum(int num)
{
    int dgt,d_sum=0;
    if(num>0)
    {
        dgt=num%10;
        num/=10;
        d_sum=digital_sum(num)+dgt;
    }
    return(d_sum);
}
