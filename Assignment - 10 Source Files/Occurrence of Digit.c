#include<stdio.h>
#include<conio.h>
int find_digit(int, int);
int main()
{
    int num,dgt,occur;
    printf("\n  The program will check whether a certain digit occurs in the number entered by the user.");

    printf("\n\n  Enter the Digit you wish to find : ");
    scanf("%d",&dgt);
    printf("  Enter the Number you wish scan : ");
    scanf("%d",&num);

    occur=find_digit(num,dgt);
    if(occur==1)
        printf("\n  The DIGIT OCCURS in the number.");
    else
        printf("\n  The DIGIT DOES NOT OCCUR in the number.");

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int find_digit(int num, int dgt)
{
    int dt;

    while(num>0)
    {
        dt=num%10;
        if(dt==dgt)
            return (1);
        num=num/10;
    }

    return (0);
}
