#include<stdio.h>
#include<conio.h>
int sum_row(int[]);
int sum_column(int[]);
int main()
{
    int mat[3][3],i,j,k,sumr,sumc;
    printf("\n  The program will calculate the sum of rows and columns\n  of the 3x3 matrix entered by the user.\n\n  ");
    printf("Enter the values in the matrix : \n");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            printf("  ");
            scanf("%d",&mat[i][j]);
        }

    printf("\n  Values entered by the user : ");
    for(i=0;i<3;i++)
    {
        printf("\n  ");
        for(j=0;j<3;j++)
            printf("[%d]. ",mat[i][j]);
    }

    printf("\n\n  Sum of Rows : ");
    for(i=0;i<3;i++)
    {
        for(sumr=0,j=0;j<3;j++)
                sumr=sumr+mat[i][j];
        printf("\n  Sum of Row %d == %d",i+1,sumr);
    }

    printf("\n\n  Sum of Columns : ");
    for(i=0;i<3;i++)
    {
        for(sumc=0,j=0;j<3;j++)
                sumc=sumc+mat[j][i];
        printf("\n  Sum of Column %d == %d",i+1,sumc);
    }

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
