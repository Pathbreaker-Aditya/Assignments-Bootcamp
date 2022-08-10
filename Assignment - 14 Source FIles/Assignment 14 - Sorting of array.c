#include<stdio.h>
#include<conio.h>
void sort_ascend(int[]);
int main()
{
    int arr[10],i,*p_arr;
    printf("\n  The program will sort the elements stored in the array by the user is ascending order.\n\n  ");
    printf("Enter the Numbers : \n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("\n  Arrangement of Array before sorting : ");
    for(i=0;i<10;i++)
        printf("[%d]. ",arr[i]);

    sort_ascend(arr);

    printf("\n  Arrangement of Array after sorting : ");
    for(i=0;i<10;i++)
        printf("[%d]. ",arr[i]);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void sort_ascend(int arr[])
{
    int grt,sml,i,k,index,sort[10];

    grt=arr[0];
    for(i=1;i<10;i++)
        if(grt<arr[i])
            grt=arr[i];

    for(k=0;k<10;k++)
    {
        sml=arr[0];
        index=0;
        for(i=0;i<10;i++)
            if(sml>arr[i])
            {
                sml=arr[i];
                index=i;
            }
        sort[k]=sml;
        arr[index]=grt;
    }

    for(i=0;i<10;i++)
        arr[i]=sort[i];
}
