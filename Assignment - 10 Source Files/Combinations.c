#include<stdio.h>
#include<conio.h>
int combinations(int,int);
int main()
{
    int n,r,comb;
    printf("\n  The program will calculate the number of combinations possible\n  from \"n\" items taken \"r\" at a time, i.e. c(n,r)");

    while(1)
    {
        printf("\n\n  Enter the value of \"n\" : ");
        scanf("%d",&n);
        printf("  Enter the value of \"r\" : ");
        scanf("%d",&r);

        if(n<r)
            printf("\n\n  Value of \"n\" cannot be less than that of \"r\".\n  Enter the values for the same again.");
        else
            break;
    }

    comb=combinations(n,r);
    printf("\n  Number of combinations possible from \"%d\" items, taken \"%d\" at a time == %d",n,r,comb);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int combinations(int n,int r)
{
    int i,perm,facr,comb;
    for(perm=facr=1,i=0;i<r;i++)
    {
        perm=perm*(n-i);
        facr=facr*(r-i);
    }
    comb=perm/facr;
    return (comb);
}

