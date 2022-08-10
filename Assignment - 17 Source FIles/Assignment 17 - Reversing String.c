#include<stdio.h>
#include<conio.h>
int main()
{
    int i,size;
    char str[30],rev;
    printf("\n  The program will reverse the given string without using predefined functions.\n\n  ");
    printf("Enter the String : ");
    fgets(str,30,stdin);

    for(size=0;str[size];size++);
    size--;

    for(i=0;i<size/2;i++)
    {
        rev=str[i];
        str[i]=str[size-1-i];
        str[size-1-i]=rev;
    }

    printf("\n  Reverse of given string : %s",str);

    printf("\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
