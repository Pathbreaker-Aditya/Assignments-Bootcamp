#include<stdio.h>
#include<conio.h>
void rotate_left(int[],int);
void rotate_right(int[],int);
int main()
{
    int arr[10],i,posit,dir;
    printf("\n  The program will rotate an array of 10 by elements by 'n' positions\n  in left or right direction as specified by the user.\n\n  ");
    printf("Enter the 10 elements in the array : \n");
    for(i=0;i<10;i++)
    {
        printf("  ");
        scanf("%d",&arr[i]);
    }

    printf("\n  Press any number to rotate the array in RIGHT,\n  Press 0 to rotate the array in LEFT. : ");
    scanf("%d",&dir);

    printf("\n  By how many positions should the array be rotated ? : ");
    scanf("%d",&posit);

    printf("\n  The array before rotation :   ");
    for(i=0;i<10;i++)
        printf("[%d]. ",arr[i]);

    if(dir)
    {
        rotate_right(arr,posit);
        printf("\n\n  The array after rotation by\n  %d positions in right :        ",posit);
        for(i=0;i<10;i++)
            printf("[%d]. ",arr[i]);
    }
    else
    {
        rotate_left(arr,posit);
        printf("\n\n  The array after rotation by\n  %d positions in left :        ",posit);
        for(i=0;i<10;i++)
            printf("[%d]. ",arr[i]);
    }


    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void rotate_left(int arr[10],int posit)
{
    int i,k,carrier;
    for(k=1;k<=posit;k++)
    {
        for(carrier=arr[0],i=0;i<9;i++)
            arr[i]=arr[i+1];
        arr[i]=carrier;
    }
}

void rotate_right(int arr[10],int posit)
{
    int i,k,carrier;
    for(k=1;k<=posit;k++)
    {
        for(carrier=arr[9],i=9;i>0;i--)
            arr[i]=arr[i-1];
        arr[i]=carrier;
    }
}
