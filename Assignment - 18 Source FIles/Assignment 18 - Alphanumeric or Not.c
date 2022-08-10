#include<stdio.h>
#include<conio.h>
void alphanum(char[]);
int main()
{
    char str[31];
    printf("\n  The program will check whether a string entered by the user is alphanumeric or not.\n\n  ");
    printf("Enter the String : ");
    fgets(str,31,stdin);

    alphanum(str);

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}

void alphanum(char str[])
{
    int i,alpha,num;
    for(i=0;str[i];i++);
    str[i-1]='\0';

    for(alpha=0,num=0,i=0;str[i];i++)
    {
        if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))
            alpha++;
        if(str[i]>='0' && str[i]<='9')
            num++;
    }

    if(alpha*num)
        printf("\n  The String is ALPHANUMERIC.");
    else
        printf("\n  The String is NOT ALPHANUMERIC.");
}
