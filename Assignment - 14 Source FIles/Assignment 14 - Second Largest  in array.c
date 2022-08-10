#include<stdio.h>
#include<conio.h>
int second_largest(int[]);
int main()
{
    int arr[10],i;
    printf("\n  The Program will find the second largest of the elements stored in an array by the user.\n\n  ");
    printf("Enter the Numbers : \n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("\n  The Second Largest element in array == %d",second_largest(arr));
    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int second_largest(int arr[])
{
    int sort[2],i,k,index,grt,sml;

    sml=arr[0];
    for(i=1;i<10;i++)
        if(sml>arr[i])
            sml=arr[i];

    for(k=0;k<2;k++)
    {
        grt=arr[i];
        for(i=0;i<10;i++)
            if(grt<arr[i])
            {
                grt=arr[i];
                index=i;
            }
        sort[k]=grt;
        arr[index]=sml;
    }

    return(sort[1]);
}
