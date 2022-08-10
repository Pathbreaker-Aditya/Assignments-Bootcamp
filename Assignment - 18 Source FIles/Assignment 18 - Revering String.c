#include<stdio.h>
#include<conio.h>
void reverse(char[]);
int main()
{
    char str[31];
    printf("\n  The program will reverse the string entered by the user.\n\n  ");
    printf("Enter the String : ");
    fgets(str,31,stdin);

    reverse(str);

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}

void reverse(char str[])
{
    int i,size;
    char ch;
    for(i=0;str[i];i++);


    str[i-1]='\0';
    size=--i;

    printf("\n  \"%s\"  <---after reversal--->  ",str);
    for(i=0;i<size/2;i++)
    {
        ch=str[i];
        str[i]=str[size-1-i];
        str[size-1-i]=ch;
    }
    printf("\"%s\"",str);
}
