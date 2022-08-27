#include<stdio.h>
#include<conio.h>
#include<string.h>
void swap_string(char*,char*);
int main()
{
    char str[21],arr[21];
    printf("\n  The program will swap strings stored in two char type arrays named 'str' and 'arr'.\n\n  ");

    printf("Enter String in 'str' : ");
    fgets(str,21,stdin);
    printf("  Enter String in 'arr' : ");
    fgets(arr,21,stdin);

    str[strlen(str)-1]=0;
    arr[strlen(arr)-1]=0;

    printf("\n  Strings before swapping : 'str' = %s, 'arr' = %s",str,arr);
    swap_string(str,arr);
    printf("\n  Strings after swapping : 'str' = %s, 'arr' = %s",str,arr);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void swap_string(char *str,char *arr)
{
    char temp[21];
    strcpy(temp,arr);
    strcpy(arr,str);
    strcpy(str,temp);
}
