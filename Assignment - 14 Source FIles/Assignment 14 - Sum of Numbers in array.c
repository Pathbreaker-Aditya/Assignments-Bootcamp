#include<stdio.h>
#include<conio.h>
#include<string.h>
int sum_array (int[]);
int main()
{
    int arr[10],i;
    printf("\n  The program will calculate the sum of numbers entered in an array by the user.\n\n  ");
    printf("Enter the Numbers : \n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("\n  The Sum of numbers in array == %d",sum_array(arr));

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int sum_array(int arr[])
{
    int i,sum=0;
    for(i=0;i<10;i++)
        sum=sum+arr[i];
    return(sum);
}
