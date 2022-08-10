#include<stdio.h>
#include<conio.h>
int main()
{
    int mat_1[3][3],mat_2[3][3],prod[3][3],i,j,k;
    printf("\n  The program will calculate the product of two 3x3 matrices.\n\n  ");
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

    printf("\n\n  The product of the Matrix 1 and Matrix 2 : ");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            prod[i][j]=0;
            for(k=0;k<3;k++)
                prod[i][j]=prod[i][j]+(mat_1[i][k]*mat_2[k][j]);
        }
    for(i=0;i<3;i++)
    {
        printf("\n  ");
        for(j=0;j<3;j++)
            printf("[%d]. ",prod[i][j]);
    }

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
