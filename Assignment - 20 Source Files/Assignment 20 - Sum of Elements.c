#include<stdio.h>
#include<conio.h>
void cal_sum(int*,int*);
int main()
{
    int arr[10],i,sum;
    printf("\n  The program will calculate the sum of all elements of an int array using pointer.");

    printf("\n\n  Enter the Values in the array : \n\n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    cal_sum(arr,&sum);

    printf("\n  Sum of elements == %d",sum);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void cal_sum(int *arr,int *sum)
{
    int i;
    for(*sum=0,i=0;i<10;i++)
        *sum=*sum+arr[i];
}
