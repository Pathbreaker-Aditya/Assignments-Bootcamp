#include<stdio.h>
#include<conio.h>
int main()
{
    int i,k,size,prior,later,index;
    char str[20],sort[20];
    printf("\n  The program will sort the string in alphabetical order.\n\n  ");
    printf("Enter the String : ");
    fgets(str,20,stdin);

    for(size=0,i=0;str[i];i++);
    size=--i;

    printf("\n  Size of string : %d",size);

    later=str[0];
    for(i=1;i<size;i++)
        if(later<str[i])
            later=str[i];

    for(k=0;k<size;k++)
    {
        prior=str[0];
        index=0;
        for(i=0;i<size;i++)
            if(prior>str[i])
            {
                prior=str[i];
                index=i;
            }
        sort[k]=prior;
        str[index]=later;
    }

    for(i=0;i<size;i++)
        str[i]=sort[i];

    printf("\n  The String sorted in alphabetical order : %s",str);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
