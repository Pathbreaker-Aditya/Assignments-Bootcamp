#include<stdio.h>
#include<conio.h>
int main()
{
    int F,f1,f_1,f2,f_2,num,i,index=0;
    printf("\n  The program will check whether a number entered by the user\n  occurs in the Fibonacci Series created by the user or not.\n\n  ");
    printf("Enter the First Term : ");
    scanf("%d",&f1);
    f_1=f1;

    printf("  Enter the Second Term : ");
    scanf("%d",&f2);
    f_2=f2;

    printf("  Enter the number whose occurrence you wish to check : ");
    scanf("%d",&num);

    do
    {
        F=f1+f2;
        f1=f2;
        f2=F;
        if(num==F)
        {
            printf("\n  %d OCCURS in the Fibonacci Series having first two terms as %d and %d.",num,f_1,f_2);
            f1=f_1;
            f2=f_2;

            printf("\n  The Position of %d in Series ==> %d. %d. ",num,f1,f2);
            while(index<=2)
            {
                F=f1+f2;
                f1=f2;
                f2=F;
                if(F>=num)
                {
                    if(F==num)
                        printf("[%d]. ",F);
                    else
                        printf("%d. ",F);
                    index++;
                }
                else
                    printf("%d. ",F);
            }
            break;
        }
        else if(num<F)
        {
            printf("\n  %d DOES NOT OCCUR in the Fibonacci Series having first two terms as %d and %d.",num,f_1,f_2);
            break;
        }
    }while(1);

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}
