#include<stdio.h>
#include<conio.h>
void palindrome(char[]);
int main()
{
    char str[31];
    printf("\n  The program will check whether a user-entered string is a palindrome.\n\n  ");
    printf("Enter the String : ");
    fgets(str,31,stdin);

    palindrome(str);

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}

void palindrome(char str[])
{
    int i,size,check;

    for(i=0;str[i];i++);
    size=--i;

    for(check=1,i=0;i<size;i++)
        if(str[i]-str[size-1-i]==0)
            continue;
        else
        {
            check--;
            break;
        }

    if(check)
        printf("\n  The String IS A PALINDROME.");
    else
        printf("\n  The String is NOT PALINDROMIC.");
}
