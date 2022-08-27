#include<stdio.h>
#include<conio.h>
void sort_array(int*);
int main()
{
    int arr[10],i;
    printf("\n  The program will sort an int array of size 10.\n\n  ");
    printf("Enter 10 Numbers : \n\n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }
    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
