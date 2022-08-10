#include<stdio.h>
#include<conio.h>
float avg_array(int[]);
int main()
{
    int arr[10],i;
    printf("\n  The program will calculate the average of numbers stored in an array by the user.\n\n  ");
    printf("Enter the Numbers : \n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("\n  The average of the numbers in the array == %f",avg_array(arr));
    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

float avg_array(int arr[])
{
    int i,sum=0;
    float avg;
    for(i=0;i<10;i++)
        sum=sum+arr[i];
    avg=sum/10.0;
    return(avg);
}
