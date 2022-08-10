#include<stdio.h>
#include<conio.h>
int compare_strings(char[],char[]);
int main()
{
    char str1[31],str2[31];
    int comp;
    printf("\n  The program will compare two strings without.\n\n  ");

    printf("Enter First String : ");
    fgets(str1,31,stdin);
    printf("  Enter Second String : ");
    fgets(str2,31,stdin);

    comp=compare_strings(str1,str2);
    if(comp==0)
        printf("\n  IDENTICAL STRINGS.");
    else if(comp>0)
        printf("\n  The Strings are entered in REVERSE OF DICTIONARY ORDER.");
    else
        printf("\n  The Strings are entered in DICTIONARY ORDER.");

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}

int compare_strings(char str1[],char str2[])
{
    int i,diff,smlr,len1,len2;

    for(i=0;str1[i];i++);
    len1=--i;
    for(i=0;str2[i];i++);
    len2=--i;

    smlr = len1<len2?len1:len2;

    for(diff=0,i=0;i<smlr;i++)
    {
        diff=str1[i]-str2[i];
        if(diff!=0)
            break;
    }

    return (diff);
}
