#include<stdio.h>
#include<conio.h>
void print_prime(int);
int main()
{
    int num;
    printf("\n  The program will print all the prime factors of the number entered by the user.\n\n  ");

    printf("Enter the Number : ");
    scanf("%d",&num);

    print_prime(num);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void print_prime(int num)
{
    int i,j,numf;
    printf("\n  Prime Factorization of %d ==> ",num);

    for(i=2;i<=num;i++)
    {
        if(num%i==0)
        {
            for(j=2;j<=i;j++)
                if(i%j==0)
                    break;
            if(i==j)
            {
                printf("%d. ",i);
                numf=num/i;
                while(numf%i==0)
                {
                    printf("%d. ",i);
                    numf=numf/i;
                }
            }
        }
    }
}
