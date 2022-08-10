#include<stdio.h>
#include<conio.h>
int main()
{
    int i;
    char str[20],ch;
    printf("\n  The program will check whether a given character occurs in the string user enters.\n\n  ");
    printf("Enter the string : ");
    fgets(str,20,stdin);
    printf("\n  Which character do you wish to find ? : ");
    scanf("%c",&ch);

    for(i=0;str[i];i++)
        if(str[i]==ch)
        {
            printf("\n  %c OCCURS in the given string.",ch);
            break;
        }
        else if(str[i]=='\n')
            printf("\n  %c DOES NOT OCCUR in the given string.",ch);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
