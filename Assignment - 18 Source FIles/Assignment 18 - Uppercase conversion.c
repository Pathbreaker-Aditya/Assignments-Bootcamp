#include<stdio.h>
#include<conio.h>
void uppercase(char[]);
int main()
{
    char str[31];
    printf("\n  The program will convert the user-entered string into uppercase.\n\n  ");
    printf("Enter the String : ");
    fgets(str,31,stdin);

    uppercase(str);

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}

void uppercase(char str[])
{
    int i;

    for(i=0;str[i];i++);
    str[i-1]='\0';

    printf("\n  \"%s\" <--uppercased--> ",str);
    for(i=0;str[i];i++)
        if(str[i]>=97 && str[i]<=122)
            str[i]-=32;
    printf("\"%s\"",str);
}
