#include<stdio.h>
#include<conio.h>
int main()
{
    int mat[4][4],i,j;
    printf("\n  The program will create the Upper triangular matrix for a given 4x4 matrix.\n\n  ");
    printf("Enter the values in the matrix : \n");
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
        {
            printf("  ");
            scanf("%d",&mat[i][j]);
        }

    printf("\n  Values entered by the user : ");
    for(i=0;i<4;i++)
    {
        printf("\n  ");
        for(j=0;j<4;j++)
            if(mat[i][j]>=10)
                printf("[%d]. ",mat[i][j]);
            else
                printf("[ %d]. ",mat[i][j]);
    }

    for(i=1;i<=3;i++)
    {
        switch(i)
        {
        case 1:
            mat[i][0]=0;
            break;
        case 2:
            for(j=0;j<=1;j++)
                mat[i][j]=0;
            break;
        case 3:
            for(j=0;j<=2;j++)
                mat[i][j]=0;
        }
    }

    printf("\n\n  Upper Triangular Matrix corresponding to the above matrix : ");
    for(i=0;i<4;i++)
    {
        printf("\n  ");
        for(j=0;j<4;j++)
            if(mat[i][j]>=10)
                printf("[%d]. ",mat[i][j]);
            else
                printf("[ %d]. ",mat[i][j]);
    }

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

