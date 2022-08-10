#include<stdio.h>
#include<conio.h>
#include<string.h>
void wordwise_rev(int);
int main()
{
    int words;
    printf("\n  The program will reverse a user-entered multi-word string word wise.\n\n  ");
    printf("How many words does your string have ? : ");
    scanf("%d",&words);
    fflush(stdin);

    wordwise_rev(words);

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}

void wordwise_rev(int words)
{
    char str[words][21],ch;
    int i,j,longer,len1,len2;

    printf("\n  Enter the String, (hit ENTER after each word) : \n  ");
    for(i=0;i<words;i++)
    {
        fflush(stdin);
        fgets(str[i],21,stdin);
        for(j=0;str[i][j];j++);
        str[i][j-1]=0;
        printf("  ");
    }

    printf("\n  The string entered by the user : ");
    for(i=0;i<words;i++)
        printf("%s ",str[i]);

    printf("\n  The String after reversal : ");
    for(i=0;i<words/2;i++)
    {
        for(j=0;str[i][j];j++);
        len1=j;

        for(j=0;str[words-1-i][j];j++);
        len2=j;

        longer=len1>len2?len1:len2;

        for(j=0;j<longer;j++)
        {
            ch=str[i][j];
            str[i][j]=str[words-1-i][j];
            str[words-1-i][j]=ch;
        }
    }
    for(i=0;i<words;i++)
        printf("%s ",str[i]);
}
