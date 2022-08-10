#include<stdio.h>
#include<conio.h>
int main()
{
    int num_1,num_2,hcf,i=1;
    printf("\n  The program will calculate the HCF of two numbers entered by the user.\n\n  ");
    printf("Enter the First Number : ");
    scanf("%d",&num_1);
    printf("  Enter the Second Number : ");
    scanf("%d",&num_2);

    if(num_1>num_2)
    {
        num_2=num_1+num_2;
        num_1=num_2-num_1;
        num_2=num_2-num_1;
    }

    hcf=find_hcf(num_1,num_2,num_1,i);
    printf("\n  HCF of %d and %d == %d",num_1,num_2,hcf);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int find_hcf(int num_1,int num_2,int hcf,int i)
{
    if(num_1%hcf==0 && num_2%hcf==0)
        return(hcf);
    else
    {
        for(i+=1;i;i++)
            if(num_1%i==0)
            {
                hcf=find_hcf(num_1,num_2,num_1/i,i);
                break;
            }
        return(hcf);
    }
}
