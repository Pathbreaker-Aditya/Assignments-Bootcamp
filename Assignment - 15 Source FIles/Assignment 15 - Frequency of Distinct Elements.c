#include<stdio.h>
#include<conio.h>
void count_distinct(int[]);
void count_frequency(int[],int);
int main()
{
    int arr[10],i;
    printf("\n  The program will count the frequency of each distinct element of the array.\n\n  ");
    printf("Enter 10 numbers in the array : \n");

    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("\n  Values entered by the user : ");
    for(i=0;i<10;i++)
        printf("[%d]. ",arr[i]);

    count_distinct(arr);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void count_distinct(int arr[])
{
    int i,k,dist;
    for(dist=1,k=1;k<10;k++)
        for(i=0;i<k;i++)
            if(arr[i]!=arr[k])
            {
                if(i+1==k)
                    dist++;
            }
            else
                break;

    count_frequency(arr,dist);
}

void count_frequency(int arr[],int dist)
{
    int i,j,k,unq[dist],freq[dist],count;

    unq[0]=arr[0];
    for(j=0,k=1;k<dist;k++)
        for(j++;j<10;j++)
        {
            for(i=0;i<j;i++)
                if(arr[i]!=arr[j])
                {
                    if(i+1==j)
                        unq[k]=arr[j];
                }
                else
                    break;
            if(unq[k]==arr[j])
                break;
        }

    printf("\n\n  The distinct elements of the array : ");
    for(i=0;i<dist;i++)
        printf("[%d]. ",unq[i]);

    printf("\n\n  The frequency of each of the distinct elements are as follows : ");
    for(k=0;k<dist;k++)
    {
        for(count=0,i=0;i<10;i++)
            if(unq[k]==arr[i])
                count++;
        printf("\n  Frequency of [%d] == %d times",unq[k],count);

    }
}


