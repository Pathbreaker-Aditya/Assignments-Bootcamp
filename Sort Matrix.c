#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

void swap(char*,char*);
int print_matrix(char[],int);
char arrows(int*,int,char[]);
int difficulty(int);
void print_rules(char[]);
void gameplay(char[],char[],char[]);
void font_color(int Forgc);

int main()
{
    char    mat[10][16]={{2,3,5,6,4,8,32,9,7,1,10,15,13,12,11,14},{5,15,14,2,3,4,7,11,9,10,32,13,12,1,6,8},{4,5,6,7,10,11,12,13,1,2,3,32,8,9,15,14},{3,15,1,14,2,13,4,12,5,11,6,10,7,8,9,32},{6,7,8,9,10,11,32,1,2,3,4,5,12,13,14,15},{32,15,1,3,5,9,11,2,4,6,8,10,12,14,7,13},{1,2,3,4,5,6,7,8,32,9,10,11,12,13,14,15},{8,3,1,9,7,5,4,6,2,10,11,32,12,13,14,15},{9,8,2,7,5,3,6,1,15,10,32,11,12,13,14,4},{10,11,12,13,14,15,32,1,9,8,2,3,7,6,5,4}};
    char solved[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,32};
    char name[21];
    int random;

    font_color(6);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n  Welcome to the Matrix Sorter, Maximize the console screen for proper view of the game.\n               Enter Your Name : ");

    font_color(11);
    fgets(name,21,stdin);

    name[strlen(name)-1]=0;
    strupr(name);
    random=strlen(name)%10;
    gameplay(mat[random],solved,name);// An attempt to call a matrix randomly from the 2-D char array mat[][].
}

int difficulty(int choice)
//  This function decides the difficulty level and returns number of turns to function gameplay().
{
    switch(choice)
    {
    case 1:
        printf("\n  Difficulty == EASY(200 turns)");
        return(200);
    case 2:
        printf("\n  Difficulty == MEDIUM(150 turns)");
        return(150);
    case 3:
        printf("\n  Difficulty == HARD(100 turns)");
        return(100);
    default:
        printf("  Invalid Choice, choose again....");
        return(0);
    }
}

void swap(char *blank,char *swapee)
//  This function swaps the blank space with the number determined by the function arrows().
{
    char ch;
    ch=*swapee;
    *swapee=*blank;
    *blank=ch;
}

int print_matrix(char mat[],int k)
// This function is responsible for printing the matrix.
{
    int i,blank;

    if(k>0)
    {
        system("cls");
        printf("\n\n  Turns Remaining == %d",k);
    }
    for(i=0;i<16;i++)
    {
        if(i%4==0)
            printf("\n  _____________________\n  ");
        if(mat[i]==32)
        {
            if(k>0)
                blank=i;
            if(i%4==3)
                printf("| %c  |",mat[i]);
            else
                printf("| %c  ",mat[i]);
        }
        else
            if(mat[i]<10)
                if(i%4==3)
                    printf("| %d  |",mat[i]);
                else
                    printf("| %d  ",mat[i]);

            else
                if(i%4==3)
                    printf("| %d |",mat[i]);
                else
                    printf("| %d ",mat[i]);
    }
    printf("\n  _____________________");

    if(k>0)
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    return (blank);
}

char arrows(int *ch2,int blank,char mat[])
// This function decides the number with which the blank space is swapped by the function swap().
{
    char temp;
    switch(*ch2)
    {
        case 72:  // UP
            if(blank<12)
            {
                temp=mat[blank+4];
                swap(&mat[blank],&mat[blank+4]);
                *ch2=0;
                break;
            }
            else
                break;

        case 80:  // DOWN
            if(blank>3)
            {
                temp=mat[blank-4];
                swap(&mat[blank],&mat[blank-4]);
                *ch2=0;
                break;
            }
            else
                break;

        case 75: // LEFT
            if(blank%4!=3)
            {
                temp=mat[blank+1];
                swap(&mat[blank],&mat[blank+1]);
                *ch2=0;
                break;
            }
            else
                break;

        case 77: // RIGHT
            if(blank%4)
            {
                temp=mat[blank-1];
                swap(&mat[blank],&mat[blank-1]);
                *ch2=0;
                break;
            }
            else
                break;
    }
    return(temp);
}


void print_rules(char solved[])
{
    font_color(6);
    printf("                                     ***{ WELCOME TO MATRIX SORTING GAME }***");
    printf("\n\n ** OBJECTIVE OF THE GAME:");

    font_color(7);
    printf("\n  The objective of the game is to sort the matrix in ascending order to make it look something like this : ");

    font_color(12);
    print_matrix(solved,0);
    printf("\n  If you do this, YOU WIN !");

    font_color(6);
    printf("\n\n ** How to Play : ");

    font_color(7);
    printf("\n  The matrix will be sorted by shifting a number to the blank position with the help of arrow keys.");

    font_color(10);
    printf("\n               1. UP arrow key moves the number below the blank space upwards.");
    printf("\n               2. DOWN arrow key moves the number above the blank space downwards");
    printf("\n               3. LEFT arrow key moves the number at right side of blank space leftwards");
    printf("\n               4. RIGHT arrow key moves the number at left side of blank space rightwards");
    printf("\n               5. If you wish to quit the game midway, PRESS 'E' key.");

    font_color(12);
    printf("\n\n  If you are unable to sort the matrix in the given number of turns, you lose...");

    font_color(7);
    printf("\n\n ** The game has three difficulty levels:\n  EASY - 200 turns.\n  MEDIUM - 150 turns.\n  HARD - 100 turns.");
    printf("                                                              Press any key to continue : ");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    getch();
}


void gameplay(char mat[],char solved[],char name[])
{
    char gmply_mat[10][16]={{2,3,5,6,4,8,32,9,7,1,10,15,13,12,11,14},{5,15,14,2,3,4,7,11,9,10,32,13,12,1,6,8},{4,5,6,7,10,11,12,13,1,2,3,32,8,9,15,14},{3,15,1,14,2,13,4,12,5,11,6,10,7,8,9,32},{6,7,8,9,10,11,32,1,2,3,4,5,12,13,14,15},{32,15,1,3,5,9,11,2,4,6,8,10,12,14,7,13},{1,2,3,4,5,6,7,8,9,10,11,12,13,14,32,15},{8,3,1,9,7,5,4,6,2,10,11,32,12,13,14,15},{9,8,2,7,5,3,6,1,15,10,32,11,12,13,14,4},{10,11,12,13,14,15,32,1,9,8,2,3,7,6,5,4}};
    char temp;
    int turns=0,ch1,ch2=0;
    int i,j,k,m,blank,win=0,play,choice;
    int add,random=&add;

    print_rules(solved);
    while(turns==0)
    {
        fflush(stdin);
        system("cls");
        printf("\n\n  Choose difficulty level : \n  For Easy (200 turns), Press 1.\n  For Medium (150 turns), Press 2.\n  For Hard (100 turns), Press 3.\n\n  Enter Your Choice : ");
        scanf("%d",&choice);
        turns=difficulty(choice);
    }
    printf("\n  Press any key to start the game.\n\n  ");
    getch();

    for(k=0;k<=turns;k++)
    {
        for(m=0;m<16;m++)  //  This for loop checks whether the matrix is solved.
            if(mat[m]-solved[m]!=0)
            {
                win=0;
                if(k==turns)
                {
                    font_color(12);
                    printf("\n\n Sorry ");

                    font_color(11);
                    printf("%s,",strlwr(name));

                    font_color(12);
                    printf(" You Lose...\n\n\n\n\n\n\n\n\n\n");

                    font_color(7);
                    printf("Would you like to play again ?\n\n  Press 'Y' if Yes,\n  Press 'N' if No : \n\n  ");
                    while(play!='y' || play!='y' || play!='N' || play!='n')
                    {
                        play=getch();
                        if(play=='N' || play=='n' || play=='E' || play=='e')
                            exit(0);
                        else if(play=='Y' || play=='y')
                            gameplay(gmply_mat[blank%10],solved,name);
                    }
                }
                else
                    break;
            }
            else
                win=1;
        if(win)
        {
            print_matrix(mat,-1);

            font_color(6);
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n  *****  CONGRATULATIONS");

            font_color(11);
            printf("%s",strupr(name));

            font_color(6);
            printf("!!!! YOU HAVE WON !!!!  ****\n  You took");

            font_color(10);
            printf(" %d turns ",k);

            font_color(6);
            printf("to sort the matrix.\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

            font_color(7);
            printf("\n\n  Would you like to play again ?\n\n  Press 'Y' if Yes,\n  Press 'N' if NO : \n\n  ");

            while(play!='y' || play!='y' || play!='N' || play!='n')
            {
                play=getch();
                if(play=='N' || play=='n' || play=='E' || play=='e')
                    exit(0);
                else if(play=='Y' || play=='y')
                    gameplay(gmply_mat[blank%10],solved,name);
            }
        }

        blank=print_matrix(mat,turns-k); // prints the arrangement of the matrix after last key press.

        while(1) // this while loop ensures that user does not lose a turn if he presses a key for a direction where swapping is not possible.
        {
            ch1=getch();
            if(ch1=='E' || ch1=='e')
            {
                printf("\n\n  The user has quit the game....\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n  ");
                system("pause");
                exit(0);
            }
            if(ch1==0xE0)
                ch2=getch();

            temp=arrows(&ch2,blank,mat);
            if(temp==mat[blank]) // indicating successful swapping of blank space and directed number.
                break;
        }
    }

    printf("\n\n  Press any key to exit program.\n\n  ");
    getch();
}

void font_color(int Forgc) // block of code imported from the internet to color the fonts.
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (Forgc & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
