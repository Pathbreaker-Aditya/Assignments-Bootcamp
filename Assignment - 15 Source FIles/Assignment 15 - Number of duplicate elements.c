#include<stdio.h>
#include<conio.h>
int count_distinct(int[]);
int count_duplicate(int[],int);
int main()
{
    int arr[10],i;
    printf("\n  The program will count the number of duplicate elements in the array.\n\n  ");
    printf("Enter 10 numbers in the array : \n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("\n  Values entered by the user : ");
    for(i=0;i<10;i++)
        printf("[%d]. ",arr[i]);

    printf("\n  Number of duplicate elements in the array == %d",count_distinct(arr));

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int count_distinct(int arr[])
{
    int dist,reap,i,k;

    for(dist=1,k=1;k<10;k++)
        for(i=0;i<k;i++)
            if(arr[i]!=arr[k])
            {
                if(i+1==k)
                    dist++;
            }
            else
                break;

    return(count_duplicate(arr,dist));
}

int count_duplicate(int arr[],int dist)
{
    int unq[dist],i,j,k,count=0,uno;

    unq[0]=arr[0];
    for(j=0,k=1;k<dist;k++)
    {
        for(j++;j<10;j++)
        {
            for(i=0;i<j;i++)
            {
                if(arr[i]!=arr[j])
                {
                    if(i+1==j)
                        unq[k]=arr[j];
                }
                else
                    break;
            }
            if(unq[k]==arr[j])
                break;
        }
    }

    printf("\n  The distinct elements in the array : ");
    for(i=0;i<dist;i++)
        printf("[%d]. ",unq[i]);

    printf("\n\n  The elements having duplicates int the array : ");


    for(count=0,k=0;k<dist;k++)
    {
        for(uno=0,i=0;i<10;i++)
        {
            if(unq[k]==arr[i])
                uno++;
            if(uno>1 && unq[k]==arr[i])
                count++;
        }
        if(uno>1)
            printf("[%d]. ",unq[k]);
    }

    return(count);

    /*
    for(k=0;k<dist;k++)
        for(i=0;i<10;i++)
            if(unq[k]==arr[i])
                count++;

    */

    /*
        for(count=0,k=0;k<dist;k++)
    {
        for(uno=0,i=0;i<10;i++)
            if(unq[k]==arr[i])
                uno++;
        if(uno>1)
        {
            count++;
            printf("[%d]. ",unq[k]);
        }
    }
    */
}
