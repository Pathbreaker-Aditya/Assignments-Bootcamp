#include<stdio.h>
#include<conio.h>
void lowercase(char[]);
int main()
{
    char str[31];
    printf("\n  The program will convert the user-entered string into lowercase.\n\n  ");
    printf("Enter the String : ");
    fgets(str,31,stdin);

    lowercase(str);

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}

void lowercase(char str[])
{
    int i;

    for(i=0;str[i];i++);
    str[i-1]='\0';

    printf("\n  \"%s\" <--lowercased--> ",str);
    for(i=0;str[i];i++)
        if(str[i]>=65 && str[i]<=90)
            str[i]+=32;
    printf("\"%s\"",str);
}
