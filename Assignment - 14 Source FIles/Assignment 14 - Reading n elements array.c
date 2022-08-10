#include<stdio.h>
#include<conio.h>
int main()
{
    int arr[10],n,i;
    printf("\n  The program will read 'n' elements of an array and display the result in reverse order.\n\n  ");
    printf("Enter the Numbers in the array : \n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("  Enter the Value of 'n' : ");
    scanf("%d",&n);

    print_nrev(arr,n);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void print_nrev(int arr[],int n)
{
    int i;
    printf("\n  The %d values requested by the user are printed in reverse order as follows : \n  ");
    for(i=(n-1);i>=0;i--)
        printf("[%d]. ",arr[i]);
}
