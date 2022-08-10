#include<stdio.h>
#include<conio.h>
#include<string.h>
void count_repeats(char[]);
void display_repeats(char[],int,int);
int main()
{
    char str[31];
    printf("\n  The program will find which characters have repetitions in a given string.\n\n  ");
    printf("Enter the String : ");
    fgets(str,31,stdin);

    count_repeats(str);

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
    return(0);
}

void count_repeats(char str[])
{
    int i,j,k,reps=0,first=0;
    for(k=0;str[k];k++);
    str[k-1]=0;

    for(k=1;str[k];k++)
        if(str[0]==str[k])
        {
            first=1;
            reps++;
            break;
        }


    for(k=1;str[k];k++)
        for(i=0;i<k;i++)
            if(str[i]!=str[k])
            {
                if(i+1==k)
                    for(j=i+2;str[j];j++)
                        if(str[k]==str[j])
                        {
                            reps++;
                            break;
                        }
                if(str[k]==str[j])
                    break;
            }
            else
                break;

    display_repeats(str,reps,first);
}

void display_repeats(char str[],int reps,int first)
{
    int i,j,k=0,m;
    char rpt[reps];

    if(first)
    {
        rpt[0]=str[0];
        k=1;
    }

    for(j=0,k;k<reps;k++)
        for(j++;str[j];j++)
        {
            for(i=0;i<j;i++)
                if(str[i]!=str[j])
                {
                    if(i+1==j)
                        for(m=i+2;str[m];m++)
                            if(str[m]==str[j])
                            {
                                rpt[k]=str[j];
                                break;
                            }
                }
                else
                    break;

            if(rpt[k]==str[j])
                break;
        }

    if(reps)
    {
        printf("\n  Following character repeat in the string : \n  ");
        for(i=0;i<reps;i++)
            printf("%c. ",rpt[i]);
    }
    else
        printf("\n  No repetitions in the string.");
}
