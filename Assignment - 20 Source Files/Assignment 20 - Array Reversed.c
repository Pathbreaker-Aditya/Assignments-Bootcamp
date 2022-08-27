#include<stdio.h>
#include<conio.h>
void arr_rev(int*,int);
int main()
{
    int arr[10],i;
    printf("\n  The program will reverse an array entered by the user.");
    printf("\n\n  Enter values in the array : \n\n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("\n  Original Array : ");
    for(i=0;i<10;i++)
        printf(" %d ",arr[i]);
    arr_rev(arr,10);
    printf("\n  Reversed Array : ");
    for(i=0;i<10;i++)
        printf(" %d ",arr[i]);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void arr_rev(int *arr,int size)
{
    int i,num;
    for(i=0;i<size/2;i++)
    {
        num=arr[size-1-i];
        arr[size-1-i]=arr[i];
        arr[i]=num;
    }
}
