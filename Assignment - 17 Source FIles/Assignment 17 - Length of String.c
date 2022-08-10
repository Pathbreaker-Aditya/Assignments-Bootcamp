#include<stdio.h>
#include<conio.h>
int main()
{
    int i;
    char str[20];
    printf("\n  The program will calculate the length of the given string\n  without resorting to predefined functions.\n\n  ");

    printf("Enter the String : ");
    scanf("%s",str);

    for(i=0;str[i];i++);
    printf("\n  Length of String == %d",i);
    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
