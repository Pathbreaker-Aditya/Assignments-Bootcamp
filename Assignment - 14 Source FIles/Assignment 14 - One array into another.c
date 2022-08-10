#include<stdio.h>
#include<conio.h>
int main()
{
    int a[5],b[5],i;
    printf("\n  The program will copy elements of one array named 'a' into another array named 'b'.\n\n  ");
    printf("Enter the elements in the array 'a' : \n");
    for(i=0;i<5;i++)
    {
        printf("  ");
        scanf("%d",&a[i]);
    }

    printf("  Enter the elements in the array 'b' : \n");
    for(i=0;i<5;i++)
    {
        printf("  ");
        scanf("%d",&b[i]);
    }

    printf("\n  The arrays before copying : ");
    printf("\n  Array 'a' : ");
    for(i=0;i<5;i++)
        printf("[%d]. ",a[i]);
    printf("\n  Array 'b' : ");
    for(i=0;i<5;i++)
        printf("[%d]. ",b[i]);

    for(i=0;i<5;i++)
        b[i]=a[i];

    printf("\n\n  Press any key to execute copying.  ");
    getch();

    printf("\n\n  The arrays after copying : ");
    printf("\n  Array 'a' : ");
    for(i=0;i<5;i++)
        printf("[%d]. ",a[i]);
    printf("\n  Array 'b' : ");
    for(i=0;i<5;i++)
        printf("[%d]. ",b[i]);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
