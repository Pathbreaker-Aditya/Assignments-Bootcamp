#include<stdio.h>
#include<conio.h>
int main()
{
    int i, occ[3]={0,0,0};
    char str[40],rev;
    printf("\n  The program will count the total number of alphabets, digits and special characters in the given string.\n\n  ");
    printf("Enter the String : ");
    fgets(str,40,stdin);

    for(i=0;str[i] && str[i]!='\n';i++)
    {
        if(str[i]>=0 && str[i]<=127)
        {
            if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
                occ[0]++;
            else if(str[i]>='0' && str[i]<='9')
                    occ[1]++;
                 else
                     occ[2]++;
        }

    }

    printf("\n  Occurrences of alphabets, digits and special characters in the string are listed as follows : \n");
    for(i=0;i<3;i++)
    {
        switch(i)
        {
        case 0:
            printf("\n  Alphabets   : %d times.",occ[i]);
            break;
        case 1:
            printf("\n  Digits      : %d times.",occ[i]);
            break;
        case 2:
            printf("\n  Special Ch. : %d times.",occ[i]);
            break;
        }
    }

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}
