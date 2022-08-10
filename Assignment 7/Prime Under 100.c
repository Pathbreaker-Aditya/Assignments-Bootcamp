#include<stdio.h>
#include<conio.h>
int main()
{
    int i,num;
    printf("\n  The program will print all prime numbers under 100");
    printf("\n\n  Press any key to execute program.\n\n  ");
    getch();

    for(num=2;num<100;num++)
    {
        for(i=2;i<=num;i++)
            if(num%i==0)
                break;

        if(i==num)
            printf("%d. ",num);
    }

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
