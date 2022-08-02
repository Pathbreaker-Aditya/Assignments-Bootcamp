#include<stdio.h>
#include<conio.h>
int main()
{
    int num_1,num_2,hcf,lcm,product=num_1*num_2,i;
    printf("\n  The program will find the LCM of two numbers entered by the user.");
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

    for(i=2;i<=num_1;i++)
        if(num_1%i==0)
            break;

    if(i==num_1)
    {
        if(num_2%num_1)
        {
            hcf=1;
            lcm=product;
        }
        else
        {
            hcf=num_1;
            lcm=product/hcf;
        }
    }
    else
    {
        if(num_2%num_1)
        {
            for(i=2;1;i++)
            {
                if(num_1%i==0)
                    hcf=num_1/i;
                else
                    continue;

                if(num_1%hcf==0 && num_2%hcf==0)
                    break;
            }
            lcm=product/hcf;
        }
        else
        {
            hcf=num_1;
            lcm=product/hcf;

        }
    }

    printf("\n\n  LCM of %d and %d == %d",num_1,num_2,lcm);
    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);

}

