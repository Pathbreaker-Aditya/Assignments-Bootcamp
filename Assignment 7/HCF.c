#include<stdio.h>
#include<conio.h>
int main()
{
    int num_1,num_2,hcf;
    printf("\n  The program will find the HCF of two numbers entered by the user.");
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
                printf("\n  HCF of %d and %d == %d",num_1,num_2,hcf);
                printf("\n\n  Press any key to exit program.\n\n  ");
                getch();
                return(0);
            }
    }
    else
    {
        hcf=num_1;
        printf("\n  HCF of %d and %d == %d",num_1,num_2,hcf);
        printf("\n\n  Press any key to exit program.\n\n  ");
        getch();
        return(0);
    }
}
