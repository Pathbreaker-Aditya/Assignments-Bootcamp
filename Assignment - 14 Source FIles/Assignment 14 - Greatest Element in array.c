#include<stdio.h>
#include<conio.h>
int find_greatest(int[]);
int main()
{
    int arr[10],i;
    printf("\n  The program will find the greatest of the elements\n  stored in an array by the user.\n\n  ");
    printf("Enter the Numbers : \n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("\n  The greatest element of the array == %d",find_greatest(arr));

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int find_greatest(int arr[])
{
    int grt,i;
    grt=arr[0];
    for(i=1;i<10;i++)
        if(grt<arr[i])
            grt=arr[i];
    return(grt);
}
