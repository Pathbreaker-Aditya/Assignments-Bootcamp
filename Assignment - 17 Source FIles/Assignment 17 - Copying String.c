#include<stdio.h>
#include<conio.h>
int main()
{
    int i;
    char str_1[20],str_2[20];
    printf("\n  The program will copy one string into another without using predefined functions.\n\n  ");
    printf("Enter the First String : ");
    fgets(str_1,20,stdin);
    printf("  Enter the Second String : ");
    fgets(str_2,20,stdin);

    printf("\n\n  Strings before copying : \n  %s  %s",str_1,str_2);

    for(i=0;i<20;i++)
        str_2[i]=str_1[i];

    printf("\n\n  Strings after copying : \n  %s  %s",str_1,str_2);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
