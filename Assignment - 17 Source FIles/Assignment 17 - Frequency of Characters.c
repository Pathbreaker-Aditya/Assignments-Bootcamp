#include<stdio.h>
#include<conio.h>
void count_distinct(char[],int);
void dist_freq(char[],int,int);
int main()
{
    int i,size;
    char str[30];
    printf("\n  The Program will calculate the frequency of characters in the string.\n\n  ");

    printf("Enter the String : ");
    fgets(str,30,stdin);

    for(i=0;str[i];i++);
    size=--i;

    count_distinct(str,size);

    printf("\n\n  Press any key to exit the program.\n\n  ");
    getch();
    return(0);
}

void count_distinct(char str[],int size)
{
    int i,k,dist;
    for(dist=1,k=1;k<size;k++)
        for(i=0;i<k;i++)
            if(str[i]!=str[k])
            {
                if(i+1==k)
                    dist++;
            }
            else
                break;

    dist_freq(str,size,dist);
}

void dist_freq(char str[],int size,int dist)
{
    int i,j,k,count;
    char unq[dist];

    unq[0]=str[0];
    for(j=0,k=1;k<dist;k++)
        for(j++;j<size;j++)
        {
            for(i=0;i<j;i++)
                if(str[i]!=str[j])
                {
                    if(i+1==j)
                        unq[k]=str[j];
                }
                else
                    break;
            if(unq[k]==str[j])
                break;
        }

    printf("\n  The unique elements of the string : ");
    for(i=0;i<dist;i++)
        printf("[%c]. ",unq[i]);

    printf("\n\n  Press any key to proceed : ");
    getch();

    printf("\n\n  The frequency of the distinct characters in the string are as follows :\n");
    for(k=0;k<dist;k++)
    {
        for(count=0,i=0;i<size;i++)
            if(unq[k]==str[i])
                count++;
        printf("\n  {%c} == %d times.",unq[k],count);
    }
}
