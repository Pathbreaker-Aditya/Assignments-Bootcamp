#include<stdio.h>
#include<conio.h>
int main()
{
    int F,f1,f2,n,i;
    printf("\n  The program will find nth term of the Fibonacci series created by the user.");
    printf("\n\n  Enter the First Term : ");
    scanf("%d",&f1);
    printf("  Enter the Second Term : ");
    scanf("%d",&f2);
    printf("  Which term do you wish to find : ");
    scanf("%d",&n);

    if(n==1)
    {
        printf("  The 1st term of the Fibonacci Series will be %d",f1);
        printf("\n\n  Press any key to exit program.\n\n  ");
        getch();
        exit(0);
    }
    if(n==2)
    {
        printf("  The 2nd term of the Fibonacci Series will be %d",f2);
        printf("\n\n  Press any key to exit program.\n\n  ");
        getch();
        exit(0);
    }
    if(n<=0)
    {
        printf("  The number of term cannot be less than or equal to 0");
        printf("\n\n  Press any key to exit program.\n\n  ");
        getch();
        exit(0);
    }

    for(i=1;i<=(n-2);i++)
    {
        F=f1+f2;
        f1=f2;
        f2=F;
    }

    if(n==3)
        printf("\n  The 3rd term of the Fibonacci == %d",F);
    else
        printf("\n  The %dth term of the Fibonacci == %d",n,F);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
