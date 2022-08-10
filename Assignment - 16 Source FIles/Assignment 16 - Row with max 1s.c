#include<stdio.h>
#include<conio.h>
int main()
{
    int mat[4][4],c1[4],i,j,count,grt,row;
    printf("\n  The program will check which row of a given 4x4 matrix has maximum number of 1s in it.\n\n  ");
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

    for(i=0;i<4;i++)
    {
        for(count=0,j=0;j<4;j++)
            if(mat[i][j]==1)
                count++;
        c1[i]=count;
    }

    grt=c1[0];
    for(row=0,i=0;i<4;i++)
        if(grt<=c1[i])
        {
            grt=c1[i];
            row=i+1;
        }
    printf("\n\n  Row %d of the matrix has the greatest number of 1s (%d 1s).",row,grt);
    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
