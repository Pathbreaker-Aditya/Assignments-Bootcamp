#include<stdio.h>
#include<conio.h>
int permutations(int,int);
int main()
{
    int n,r,perm;
    printf("\n  The program will calculate the number of permutations possible\n  from \"n\" items taken \"r\" at a time, i.e. p(n,r)");

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

    perm=permutations(n,r);
    printf("\n  Number of permutations possible from \"%d\" items, taken \"%d\" at a time == %d",n,r,perm);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int permutations(int n,int r)
{
    int i,perm=1;
    for(i=0;i<r;i++)
        perm=perm*(n-i);
    return (perm);
}
