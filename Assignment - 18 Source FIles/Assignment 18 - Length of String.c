#include<stdio.h>
#include<conio.h>
int text_length(char[]);
int main()
{
    char str[31];
    printf("\n  The program will calculate the length of the string without using predefined functions.\n\n  ");
    printf("Enter the String : ");
    fgets(str,31,stdin);

    printf("\n  The length of the string == %d characters.",text_length(str));

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}

int text_length(char str[])
{
    int i;
    for(i=0;str[i];i++);
    i--;
    return(i);
}
