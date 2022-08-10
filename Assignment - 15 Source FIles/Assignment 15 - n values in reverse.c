#include<stdio.h>
#include<conio.h>
void n_values_rev(int[],int);
int main()
{
    int arr[10],i,n=1;
    printf("\n  The program will scan 'n' number of values of an array as specified by the user\n  and print the same in reverse order.\n\n  ");
    printf("Enter 10 values of array : \n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("\n  How many values from the start do you wish to scan ? : ");
    scanf("%d",&n);

    if(n>10 || n<=0)
    {
        printf("\n  Invalid number of values requested by the user.\n  Restarting the program...\n\n  ");
        main();
    }
    n_values_rev(arr,n);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void n_values_rev(int arr[],int n)
{
    int i;
    printf("\n  The %d values from start requested by the user\n  printed in reverse order : ");
    for(i=n-1;i>=0;i--)
        printf("[%d]. ",arr[i]);
}
