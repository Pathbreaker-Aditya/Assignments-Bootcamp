#include<stdio.h>
#include<conio.h>
int second_smallest(int[]);
int main()
{
    int arr[10],i;
    printf("\n  The program will find the second smallest of the elements entered in an array by the user.\n\n  ");
    printf("Enter the Numbers : \n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("\n  The Second Smallest element ==  %d",second_smallest(arr));

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int second_smallest(int arr[])
{
    int grt,sml,i,k,index,sort[2];

    grt=arr[0];
    for(i=1;i<10;i++)
        if(grt<arr[i])
            grt=arr[i];

    for(k=0;k<2;k++)
    {
        sml=arr[0];
        for(i=0;i<10;i++)
        if(sml>arr[i])
        {
            sml=arr[i];
            index=i;
        }

        sort[k]=sml;
        arr[index]=grt;
    }

    return(sort[1]);
}

