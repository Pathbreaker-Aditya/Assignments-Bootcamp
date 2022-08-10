#include<stdio.h>
#include<conio.h>
int main()
{
    int mat_1[3][3],mat_2[3][3],sum[3][3],i,j;
    printf("\n  The program will calculate the sum of two 3x3 matrices.\n\n  ");
    printf("Enter the values in Matrix 1 : \n");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&mat_1[i][j]);

    printf("\n  Enter the values in Matrix 2 : \n");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&mat_2[i][j]);

    printf("\n  First Matrix : ");
    for(i=0;i<3;i++)
    {
        printf("\n  ");
        for(j=0;j<3;j++)
            printf("[%d] ",mat_1[i][j]);
    }

    printf("\n\n  Second Matrix : ");
    for(i=0;i<3;i++)
    {
        printf("\n  ");
        for(j=0;j<3;j++)
            printf("[%d] ",mat_2[i][j]);
    }

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            sum[i][j]=mat_1[i][j]+mat_2[i][j];

    printf("\n\n  Sum of Matrix 1 and Matrix 2 : ");
    for(i=0;i<3;i++)
    {
        printf("\n  ");
        for(j=0;j<3;j++)
            printf("[%d] ",sum[i][j]);
    }

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
