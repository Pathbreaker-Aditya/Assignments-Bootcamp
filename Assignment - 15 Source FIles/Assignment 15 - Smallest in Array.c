#include<stdio.h>
#include<conio.h>
int find_smallest(int[],int);
int array_maker(int);
int main()
{
    int arr[10],i,size,grt;
    printf("\n  The program will find the smallest of the elements\n  stored in an array whose size is defined by the user.\n\n  ");
    printf("Enter the size of the array : ");
    scanf("%d",&size);

    grt=array_maker(size);
    printf("\n  The smallest element of the array == %d",grt);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int array_maker(int size)
{
    int arr[size],i,grt;
    printf("\n  Enter the Numbers : \n");
    for(i=0;i<size;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    grt=find_smallest(arr,size);
    return(grt);
}

int find_smallest(int arr[],int size)
{
    int sml,i;
    sml=arr[0];
    for(i=1;i<size;i++)
        if(sml>arr[i])
            sml=arr[i];
    return(sml);
}


