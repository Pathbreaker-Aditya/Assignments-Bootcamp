#include<stdio.h>
#include<conio.h>
int adj_duplicate(int[]);
int main()
{
    int arr[10],i,index;
    printf("\n  The program will find the first occurrence of adjacent duplicate values in the array\n  and also return the duplicate value.\n\n  ");
    printf("Enter 10 numbers : \n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    index=adj_duplicate(arr);
    if(index>=0)
        printf("\n  First iteration of adjacent duplicate value is found at (index == %d) of the array.\n  The value at that index is %d",index,arr[index]);
    else
        printf("\n  No iteration of duplicate values detected.");

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int adj_duplicate(int arr[])
{
    int i,index=-1;
    for(i=0;i<9;i++)
        if(arr[i]==arr[i+1])
        {
            index=i+1;
            return(index);
        }
    return(index);
}
