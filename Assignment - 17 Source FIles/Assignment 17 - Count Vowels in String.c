#include<stdio.h>
#include<conio.h>
int main()
{
    int i,count;
    char str[20];
    printf("\n  The program will count the occurrences of vowels in the given string.\n\n  ");
    printf("Enter the String : ");
    fgets(str,20,stdin);

    for(count=0,i=0;str[i];i++)
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
            count++;

    printf("\n  Iterations of Vowels in the given string == %d",count);
    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
