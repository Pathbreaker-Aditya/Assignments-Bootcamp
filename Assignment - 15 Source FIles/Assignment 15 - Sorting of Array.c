#include<stdio.h>
#include<conio.h>
void array_maker(int);
void sort_ascend(int[],int);
int main()
{
    int arr[10],i,size,grt;
    printf("\n  The program will sort an array - whose size is defined by the user - in ascending order.\n\n  ");
    printf("Enter the size of the array : ");
    scanf("%d",&size);

    array_maker(size);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void array_maker(int size)
{
    int arr[size],i,grt;
    printf("\n  Enter the Numbers : \n");
    for(i=0;i<size;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("\n  Array created by the user : ");
    for(i=0;i<size;i++)
        printf("[%d]. ",arr[i]);

    sort_ascend(arr,size);

    printf("\n\n  The array after sorting : ");
    for(i=0;i<size;i++)
        printf("[%d]. ",arr[i]);
}

void sort_ascend(int arr[],int size)
{
    int i,k,grt,sml,index,sort[size];

    grt=arr[0];
    for(i=1;i<size;i++)
        if(grt<arr[i])
            grt=arr[i];

    for(k=0;k<size;k++)
    {
        sml=arr[0];
        index=0;
        for(i=0;i<size;i++)
            if(sml>arr[i])
             {
                 sml=arr[i];
                 index=i;
             }
        sort[k]=sml;
        arr[index]=grt;
    }

    for(i=0;i<size;i++)
        arr[i]=sort[i];
}
