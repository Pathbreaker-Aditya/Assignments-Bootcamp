#include<stdio.h>
#include<conio.h>
int main()
{
    int num,rev=0,dgt,n;
    printf("\n  The Program will revert the number entered by the user.\n\n  ");
    printf("Enter the Number : ");
    scanf("%d",&num);

    n=num;
    while(num>0)
    {
        dgt=num%10;
        num=num/10;
        rev=(rev*10)+dgt;
    }

    printf("\n  Reversal of %d == %d",n,rev);
    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
