#include<stdio.h>
#include<conio.h>
void str_rev(char*,int);
int main()
{
    char str[52];
    printf("\n  The program will reverse a string entered by the user.");
    printf("\n\n  Enter the String : ");
    fgets(str,52,stdin);
    str[strlen(str)-1]=0;

    printf("\n  Original Array : %s",str);
    str_rev(str,strlen(str));
    printf("\n  Reversed Array : %s",str);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void str_rev(char *str,int size)
{
    int i;
    char ch;
    for(i=0;i<size/2;i++)
    {
        ch=str[size-1-i];
        str[size-1-i]=str[i];
        str[i]=ch;
    }
}

