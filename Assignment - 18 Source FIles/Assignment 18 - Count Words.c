#include<stdio.h>
#include<conio.h>
void count_words(char[]);
int main()
{
    char str[31];
    printf("\n  The program will count the words in a user-entered multi-word string.\n\n  ");
    printf("Enter the String : ");
    fgets(str,31,stdin);

    count_words(str);

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}

void count_words(char str[])
{
    int i,words;

    for(words=0,i=0;str[i];i++)
        if((str[i]!=32 && str[i]!=10 && str[i]!=9) && (str[i+1]==32 || str[i+1]==10 || str[i+1]==9))
            words++;

    printf("\n  %d Words.",words);
}
