#include<stdio.h>
#include<conio.h>
void sum_evenodd(int[]);
int main()
{
    int arr[10],i;
    printf("\n  The program will print the sum of all even and all odd numbers seperately\n  entered in array by the user.\n\n  ");
    printf("Enter the Numbers : \n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    sum_evenodd(arr);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void sum_evenodd(int arr[])
{
    int i,s_even=0,s_odd=0;
    for(i=0;i<10;i++)
    {
        if(arr[i]%2)
            s_odd=s_odd+arr[i];
        else
            s_even=s_even+arr[i];
    }
    printf("\n  Sum of all even numbers == %d.\n  Sum of all odd numbers == %d",s_even,s_odd);
}
