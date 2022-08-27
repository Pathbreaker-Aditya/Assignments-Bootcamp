#include<stdio.h>
#include<conio.h>
int main()
{
    int num,dgts=0;
    printf("\n  The program will count the number of digits\n  in the number entered by the user.\n\n  ");
    printf("Enter the Number : ");
    scanf("%d",&num);

    printf("\n  Number of digits in %d == ",num);
    while(num>0)
    {
        num=num/10;
        dgts++;
    }
    printf("%d",dgts);
    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
