#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    int F,f1,f2,n,i;
    printf("\n  The program will find nth term of the Fibonacci series created by the user.");
    printf("\n\n  Enter the First Term : ");
    scanf("%d",&f1);
    printf("  Enter the Second Term : ");
    scanf("%d",&f2);
    printf("  How many terms do you wish to print ? : ");
    scanf("%d",&n);

    if(n==1)
    {
        printf("  The 1st term of the Fibonacci Series == %d",f1);
        printf("\n\n  Press any key to exit program.\n\n  ");
        getch();
        exit(0);
    }
    if(n==2)
    {
        printf("  The first 2 terms of the Fibonacci Series == %d, %d",f1,f2);
        printf("\n\n  Press any key to exit program.\n\n  ");
        getch();
        exit(0);
    }
    if(n<=0)
    {
        printf("  The number of terms cannot be less than or equal to 0");
        printf("\n\n  Press any key to exit program.\n\n  ");
        getch();
        exit(0);
    }

    printf("\n  The First %d terms of the Fibonacci Series are : \n  %d. %d. ",n,f1,f2);

    for(i=1;i<=(n-2);i++)
    {
        F=f1+f2;
        f1=f2;
        f2=F;
        printf("%d. ",F);
    }

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

