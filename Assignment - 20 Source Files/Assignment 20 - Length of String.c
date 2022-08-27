#include<stdio.h>
#include<conio.h>
int string_length(char*);
int main()
{
    char str[51];
    int len;
    printf("\n  The program will calculate the length of a string using a pointer.");
    printf("\n  Enter the String : ");
    fgets(str,51,stdin);

    len=string_length(str);
    printf("\n  Length of String == %d characters",len);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

int string_length(char *p)
{
    int i;
    for(i=0;p[i];i++);
    i--;
    return(i);
}
