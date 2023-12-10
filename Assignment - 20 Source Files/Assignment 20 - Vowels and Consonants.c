#include<stdio.h>
#include<conio.h>
void vow_cons(char*,int*,int*);
int main()
{
    char str[41];
    int vow,cons;
    printf("\n  The program will count the number of vowels and consonants in the given string.");

    printf("\n\n  Enter the String : ");
    fgets(str,41,stdin);

    vow_cons(str,&vow,&cons);

    printf("\n  Vowels in the string == %d",vow);
    printf("\n  Consonants in the string == %d",cons);

    printf("\n\n  Press any key to exit the program.\n\n  ");
    
    printf("\n\n  This line is being added to this file to understand the working of git commit stages. <ignore>");
    
    getch();
    return(0);
}

void vow_cons(char *str,int *vow, int *cons)
{
    int i;
    for(*vow=0,*cons=0,i=0;str[i];i++)
    {
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z'))
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
                (*vow)++;
            else
                (*cons)++;
    }
}
