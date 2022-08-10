#include<stdio.h>
#include<conio.h>
int main()
{
    int mat[4][4],i,j,zero,half;
    printf("\n  The program will check whether a given 4x4 matrix is a spare matrix.\n\n  ");
    printf("Enter the values in the matrix : \n");
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            printf("  ");
            scanf("%d",&mat[i][j]);
        }
    printf("\n  Matrix made by the user : ");
    for(i=0;i<4;i++)
    {
        printf("\n  ");
        for(j=0;j<4;j++)
        {
            if(mat[i][j]>=10)
                printf("[ %d]. ",mat[i][j]);
            else
                printf("[ %d ]. ",mat[i][j]);
        }
    }

    half=(4*4)/2;
    for(zero=0,i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            if(mat[i][j]==0)
                zero++;
        }
    if(zero>half)
        printf("\n\n  The above matrix is a SPARSE MATRIX.");
    else
        printf("\n\n  The above matrix is NOT A SPARSE MATRIX.");

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);


}
