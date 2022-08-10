#include<stdio.h>
#include<conio.h>
void print_distinct(int[],int);
void count_distinct(int[]);
int main()
{
    int arr[10],i;
    printf("\n  The program will print all the distinct elements of the array.\n\n  ");
    printf("Enter 10 numbers of the array : \n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("\n  The elements entered by the user in the array : ");
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

    print_distinct(arr,dist);
}

void print_distinct(int arr[],int dist)
{
    int unq[dist],i,j,k;

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

    printf("\n\n  The unique elements of the array are : ");
    for(i=0;i<dist;i++)
        printf("[%d]. ",unq[i]);

}
