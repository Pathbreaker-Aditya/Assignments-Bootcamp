#include<stdio.h>
#include<conio.h>
int main()
{
    int num_1,num_2,hcf;
    printf("\n  The program will check whether two numbers entered by the user are co-prime or not.");
    printf("\n\n  Enter the First Number : ");
    scanf("%d",&num_1);
    printf("  Enter the Second Number : ");
    scanf("%d",&num_2);

    if(num_1>num_2)
    {
        num_1=num_1+num_2;
        num_2=num_1-num_2;
        num_1=num_1-num_2;
    }

    if(num_2%num_1)
    {
        for(hcf=num_1/2;hcf>=1;hcf--)
            if(num_1%hcf==0 && num_2%hcf==0)
            {
                if(hcf>1)
                    printf("\n  HCF of %d and %d == %d, which is not equal to 1 and therefore\n  %d and %d are NOT CO-PRIME.",num_1,num_2,hcf,num_1,num_2);
                else
                    printf("\n  HCF of %d and %d == %d, and therefore\n  %d and %d ARE CO-PRIME.",num_1,num_2,hcf,num_1,num_2);

                printf("\n\n  Press any key to exit program.\n\n  ");
                getch();
                return(0);
            }
    }
    else
    {
        hcf=num_1;
        printf("\n  HCF of %d and %d == %d, which is not equal to 1 and therefore\n  %d and %d are NOT CO-PRIME.",num_1,num_2,hcf,num_1,num_2);
        printf("\n\n  Press any key to exit program.\n\n  ");
        getch();
        return(0);
    }
}
