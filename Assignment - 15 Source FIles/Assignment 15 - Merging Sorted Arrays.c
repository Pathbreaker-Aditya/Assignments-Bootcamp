#include<stdio.h>
#include<conio.h>
void sort_descend(int[]);
int main()
{
    int a[2][7],merge[14],i,j,k;
    printf("\n  The program will merge two arrays of same size (size=7)\n  after sorting them in descending order.\n\n  ");
    printf("Enter 7 elements in First Array : \n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<7;j++)
        {
            printf("  ");
            scanf("%d",&a[i][j]);
        }
        printf("\n  Enter 7 elements in Second Array : \n");
    }

    sort_descend(a[0]);
    printf("\n  First Array after sorting :  ");
    for(j=0;j<7;j++)
        printf("[%d]. ",a[0][j]);

    sort_descend(a[1]);
    printf("\n\n  Second Array after sorting: ");
    for(j=0;j<7;j++)
        printf("[%d]. ",a[1][j]);

    printf("\n\n  First and Second Array after merger : \n  ");
    for(k=14,i=0;i<2;i++)
    {
        if(i==0)
            for(j=0;j<7;j++)
                merge[j]=a[i][j];
        if(i==1)
            for(j=7;j<14;j++)
            {
                merge[j]=a[i][14-k];
                k--;
            }
    }
    for(i=0;i<14;i++)
        printf("[%d]. ",merge[i]);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void sort_descend(int arr[])
{
    int sort[7],i,k,grt,sml,index;

    sml=arr[0];
    for(i=1;i<7;i++)
        if(sml>arr[i])
            sml=arr[i];

    for(k=0;k<7;k++)
    {
        grt=arr[0];
        index=0;
        for(i=0;i<7;i++)
            if(grt<arr[i])
            {
                grt=arr[i];
                index=i;
            }
        sort[k]=grt;
        arr[index]=sml;
    }

    for(i=0;i<7;i++)
        arr[i]=sort[i];
}
