#include<stdio.h>
#include<conio.h>
int main()
{
    int i;
    char str[30];
    printf("\n  The program will convert the given string into lowercase without using predefined functions.\n\n  ");
    printf("Enter the String : ");
    fgets(str,30,stdin);

    for(i=0;str[i];i++)
        if(str[i]>='A' && str[i]<='Z')
            str[i]+=32;

    printf("\n  lowercase Conversion of the String : %s",str);

    printf("\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

