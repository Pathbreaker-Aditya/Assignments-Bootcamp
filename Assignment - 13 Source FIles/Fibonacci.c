#include<stdio.h>
#include<conio.h>
void fibonacci(int,int,int,int);
int main()
{
    int f1,f2,n,i=1;
    printf("\n  The program will print the first N terms of the Fibonacci Series\n  whose first 2 terms are given by the user.\n\n  ");
    printf("Enter the First Term : ");
    scanf("%d",&f1);
    printf("  Enter the Second Term : ");
    scanf("%d",&f2);
    printf("  How many terms of the series do you wish to print? : ");
    scanf("%d",&n);

    switch(n)
    {
    case 0:
        printf("\n  No terms to be printed.");
        printf("\n\n  Press any key to exit program.\n\n  ");
        getch();
        return(0);

    case 1:
        printf("\n  1st term == %d",f1);
        printf("\n\n  Press any key to exit program.\n\n  ");
        getch();
        return(0);

    case 2:
        printf("\n  1st two terms of the series == %d. %d. ",f1,f2);
        printf("\n\n  Press any key to exit program.\n\n  ");
        getch();
        return(0);

    default:
        printf("\n  The first %d terms of the Fibonacci Series : \n  %d. %d. ",n,f1,f2);
        fibonacci(f1,f2,n-2,i);
    }

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void fibonacci(int f1,int f2,int n,int i)
{
    int F;
    if(i<=n)
    {
        F=f1+f2;
        f1=f2;
        f2=F;
        i++;
        printf("%d. ",F);
        fibonacci(f1,f2,n,i);
    }
}
