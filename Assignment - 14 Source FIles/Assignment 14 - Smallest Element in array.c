#include<stdio.h>
#include<conio.h>
int find_smallest(int[]);
int main()
{
    int arr[10],i;
    printf("\n  The program will find the smallest of the elements\n  stored in an array by the user.\n\n  ");
    printf("Enter the Numbers : \n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("\n  The smallest element of the array == %d",find_smallest(arr));

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int find_smallest(int arr[])
{
    int sml,i;
    sml=arr[0];
    for(i=1;i<10;i++)
        if(sml>arr[i])
            sml=arr[i];
    return(sml);
}

