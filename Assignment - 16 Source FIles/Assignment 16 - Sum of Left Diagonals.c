#include<stdio.h>
#include<conio.h>
int main()
{
    int mat[3][3],i,j,sum;
    printf("\n  The program will calculate the sum of left diagonals of the given 3x3 matrix.\n\n  ");
    printf("Enter the values in the matrix : \n");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            printf("  ");
            scanf("%d",&mat[i][j]);
        }

    printf("\n  Matrix created by the user : ");
    for(i=0;i<3;i++)
    {
        printf("\n  ");
        for(j=0;j<3;j++)
            printf("[%d]. ",mat[i][j]);
    }

    printf("\n\n  Left Diagonal Elements of the matrix : ");
    for(sum=0,i=0;i<=2;i++)
    {
        switch(i)
       {
            case 0:
            for(j=0;j<=1;j++)
            {
                printf("[%d]. ",mat[i][j]);
                sum=sum+mat[i][j];
            }

            break;
        case 1:
            for(j=0;j<=2;j++)
            {
                printf("[%d]. ",mat[i][j]);
                sum=sum+mat[i][j];
            }
            break;
        case 2:
            for(j=1;j<=2;j++)
            {
                printf("[%d]. ",mat[i][j]);
                sum=sum+mat[i][j];
            }
            break;
       }
    }

    printf("\n\n  The Sum of Left Diagonal Elements == %d",sum);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

