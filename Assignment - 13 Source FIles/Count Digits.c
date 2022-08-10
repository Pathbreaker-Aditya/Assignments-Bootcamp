#include<stdio.h>
#include<conio.h>
int count_digits(int);
int main()
{
    int num,count;
    printf("\n  The program will count the number of digits in the number entered by the user.\n\n  ");
    printf("Enter the Number : ");
    scanf("%d",&num);

    count=count_digits(num);
    printf("\n  The number of digits in %d == %d",num,count);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int count_digits(int num)
{
    int count=0;
    if(num>0)
    {
        num/=10;
        count++;
        count=count_digits(num)+count;
    }
    return(count);
}
