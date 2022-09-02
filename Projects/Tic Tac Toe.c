#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"


int insert_Char(int,int,char[3][3]);
void howToPlay(void);
int scan_forVictory(char[3][3]);
void print_board(char[3][3]);
void human_vs_human(char[3][3]);
void smart_Comp(char[3][3]);
void evil_Comp(char[3][3]);
int evil_winLose(char[3][3],int);
int winLose(char[3][3],int);
int strategize_1(char[3][3],int);
int strategize_2(char[3][3],int);


int main()
{
    int choice,validChoice;
    char board[3][3]={0,0,0,0,0,0,0,0,0};
    srand(time(0));
    title_Screen();
    howToPlay();
    printf("\n\n                                                  1. PRESS 1 for two player mode.");
    printf("\n\n                                                  2. PRESS 2 to play with smart computer.");
    printf("\n\n                                                  3. PRESS 3 to play with evil computer.");
    printf("\n\n                                                  Enter your choice : ");
    do
    {
        scanf("%d",&choice);
        validChoice=0;
        switch(choice)
        {
        case 1:
            human_vs_human(board);
            validChoice=1;
            break;
        case 2:
            smart_Comp(board);
            validChoice=1;
            break;
        case 3:
            evil_Comp(board);
            validChoice=1;
            break;
        default:
            printf("\n                                                  Invalid choice. Please Enter your choice from the above three again : ");
            validChoice=0;
            break;
        }
    }while(!validChoice);

}


///FUNCTION - human_vs_human()
//Conducts the gameplay between two players
void human_vs_human(char board[3][3])
{
    int turn,check,result,first;
    char key;
    char play1[21],play2[21],restart=0;

    system("cls");
    printf("\n\n                                                  Enter name of PLAYER 1: ");
    fflush(stdin);

    fgets(play1,21,stdin);
    play1[strlen(play1)-1]=0;

    printf("\n\n                                                  Enter name of PLAYER 2: ");
    fflush(stdin);
    fgets(play2,21,stdin);
    play2[strlen(play2)-1]=0;

    if(rand()%2)
    {
        printf("\n\n                                                  %s will play first",play1);
        first=1;
    }
    else
    {
        printf("\n\n                                                  %s will play first",play2);
        first=2;
    }

    printf("\n\n                                                  Please hold for a few seconds while the screen loads...");
    system("pause");
    for(turn=1;turn<=9;turn++)
    {
        print_board(board);

        for(check=0;!check;)
        {
            fflush(stdin);
            key=getch()-48;
            check=insert_Char(turn,key,board);
        }

        print_board(board);

        result=scan_forVictory(board);
        if(result==1)
        {
            print_board(board);
            if(first==1)
                printf(ANSI_COLOR_YELLOW "\n\n                                                  %s has won !!!" ANSI_COLOR_RESET,play1);
            if(first==2)
                printf(ANSI_COLOR_YELLOW "\n\n                                                  %s has won !!!" ANSI_COLOR_RESET,play2);
            break;
        }
        else if(result==2)
        {
            print_board(board);
            if(first==1)
                printf(ANSI_COLOR_CYAN "\n\n                                                  %s, you have won.... !!!" ANSI_COLOR_RESET,play2);
            if(first==2)
                printf(ANSI_COLOR_CYAN "\n\n                                                  %s, you have won.... !!!" ANSI_COLOR_RESET,play1);
            break;
        }
        else if(turn==9 && result==0)
        {
            printf("\n\n                                                  Game has drawn...");
        }
    }
    printf("\n\n                                                  Do you wish to play again ?");
    printf("\n\n                                                  Press Y, if Yes,");
    printf("\n\n                                                  Press N, if No. ");
    scanf("%c",&restart);
    while(restart!='Y' || restart!='y' || restart!='N' || restart!='n')
    {
        if(restart=='Y' || restart=='y')
            main();
        if(restart=='N' || restart=='n')
            exit(0);
    }
}


///FUNCTION - smart_Comp()
//  Conducts the gameplay between player and smart computer.
void smart_Comp(char board[3][3])
{
    int turn,check,key,start,decide,toggle,result,i=1;
    char playerName[21],restart=0;
    srand(time(0));/// generating a random seed for the rand() used in the program.

    printf("\n                                                  Enter Your Name : ");
    fflush(stdin);
    fgets(playerName,21,stdin);
    playerName[strlen(playerName)-1]=0;

    /// Following If-else block randomly decides who starts first.
    if(rand()%2) ///  Assigning a random toggle to randomize the player which starts the game first.
    {
        toggle=1;
        printf("\n\n                                                  %s gets First turn.",playerName);
    }
    else
    {
        toggle=0;
        printf("\n\n                                                  Computer gets first turn.");
    }

    printf("\n\n                                                  Press any key to begin the game....\n\n  ");
    getch();
    print_board(board);

    for(turn=1;turn<=9;turn++,toggle=!toggle)
    {
        if(toggle)  /// If toggle==1, user gets the first turn, otherwise its computer's turn.
        {
            printf("\n\n                                                  %s's Turn",playerName);

            for(check=0;!check;)
            {
                fflush(stdin);
                key=getch()-48;
                check=insert_Char(turn,key,board);
            }

            print_board(board);  /// Prints tic tac toe board after user's turn.

            result=scan_forVictory(board);
            if(result==1 || result==2)
            {
                print_board(board);
                printf(ANSI_COLOR_GREEN "\n\n                                                  %s,You have beaten the Smart Computer....!!!!\n\n  " ANSI_COLOR_RESET,playerName);
                break;
            }
            else if(turn==9 && result==0)
            {
                print_board(board);
                printf("\n\n                                                  Game Drawn...\n\n  ");
            }
        }
        else
        {
            printf("\n\n                                                  Smart Computer's Turn...\n\n  ");
            check=0;
            if(i==1)     /// This if block ensures that the FIRST TURN taken by the computer is random
                while(!check)
                {
                    key=rand()%9+1;
                    check=insert_Char(turn,key,board);
                    i++; /// i was declared 1 at the beginning, i++, increments the value of i, so that value of i changes from 1, thereby ensuring that the above if block runs only once.
                    print_board(board);
                }
            else
            {
                if(turn%2)
                    start=1; // If toggle is 0 that means computer is going to start first., therefore it will have odd numbered turns;
                else
                    start=0; // If toggle is 1 that means user will start first, and computer will not start first, therefore even turns;

                decide=winLose(board,start);
                if(decide==0)
                {
                    if(turn==3 || turn==5)
                        decide=strategize_1(board,turn);
                    else if(turn==4 || turn==6)
                        decide=strategize_2(board,turn);
                    if(decide==0)
                    {
                        for(check=0;!check;)
                        {
                            key=rand()%9+1;
                            check=insert_Char(turn,key,board);
                        }
                    }
                }
                print_board(board);

                result=scan_forVictory(board);

                if(result==1 || result==2)
                {
                    printf(ANSI_COLOR_RED "\n\n                                                  Computer has won.....\n\n  " ANSI_COLOR_RED);
                    break;
                }
                else if(turn==9 && result==0)
                {
                    printf("\n\n                                                  Game Drawn...\n\n  ");
                }
            }
        }
    }
    printf("\n\n                                                  Do you wish to play again ?");
    printf("\n\n                                                  Press Y, if Yes,");
    printf("\n\n                                                  Press N, if No. ");
    scanf("%c",&restart);
    while(restart!='Y' || restart!='y' || restart!='N' || restart!='n')
    {
        if(restart=='Y' || restart=='y')
            main();
        if(restart=='N' || restart=='n')
            exit(0);
    }
}



///FUNCTION - evil_Comp()
//  The rascal cheats when it senses defeat.
void evil_Comp(char board[3][3])
{
    int turn,check,key,start,decide,toggle,result,i=1,count;
    int j,k;
    char playerName[21],restart=0;
    srand(time(0));/// generating a random seed for the rand() used in the program.

    printf("\n                                                  Enter Your Name : ");
    fflush(stdin);
    fgets(playerName,21,stdin);
    playerName[strlen(playerName)-1]=0;

    /// Following If-else block randomly decides who starts first.
    if(rand()%2) ///  Assigning a random toggle to randomize the player which starts the game first.
    {
        toggle=1;
        printf("\n\n                                                  %s gets First turn.",playerName);
    }
    else
    {
        toggle=0;
        printf("\n\n                                                  Computer gets first turn.");
    }

    printf("\n\n                                                  Press any key to begin the game....\n\n  ");
    getch();
    print_board(board);

    for(turn=1;turn<=9;turn++,toggle=!toggle)
    {
        if(toggle)  /// If toggle==1, user gets the first turn, otherwise its computer's turn.
        {
            printf("\n\n                                                  %s's Turn",playerName);

            for(check=0;!check;)
            {
                fflush(stdin);
                key=getch()-48;
                check=insert_Char(turn,key,board);
            }

            print_board(board);  /// Prints tic tac toe board after user's turn.

            result=scan_forVictory(board);
            if(result==1 || result==2)
            {
                print_board(board);
                printf(ANSI_COLOR_GREEN "\n\n                                                  %s,You have beaten the Evil Computer....!!!! UNBELIEVABLE !!!\n\n  " ANSI_COLOR_RESET,playerName);
                break;
            }
            else if(result==0)
            {
                print_board(board);
                printf("\n\n                                                  Game Drawn...\n\n  ");
            }
            else if(result==0)
            {
                for(count=0,k=0;k<3;k++)
                    for(j=0;j<3;j++)
                        if(board[k][j]!=0)
                            count++;     /// If count==9, it means all the places on the board are filled,
                                         ///regardless of the completion of the 9 turns of the game.

                if(count==9 || turn==9)  ///The game is a draw if there is no winner when all the places on the board are filled
                {
                    printf("\n\n                                                  Game Drawn...\n\n  ");
                    break;
                }
            }
        }
        else
        {
            printf("\n\n                                                  Computer's Turn...\n\n  ");
            check=0;
            if(i==1)     /// This if block ensures that the FIRST TURN taken by the computer is random
                while(!check)
                {
                    key=rand()%9+1;
                    check=insert_Char(turn,key,board);
                    i++; /// i was declared 1 at the beginning, i++, increments the value of i, so that value of i changes from 1, thereby ensuring that the above if block runs only once.
                    print_board(board);
                }
            else
            {
                if(turn%2)
                    start=1; // If toggle is 0 that means computer is going to start first., therefore it will have odd numbered turns;
                else
                    start=0; // If toggle is 1 that means user will start first, and computer will not start first, therefore even turns;

                decide=evil_winLose(board,start);
                if(decide==0)
                {
                    if(turn==3 || turn==5)
                        decide=strategize_1(board,turn);
                    else if(turn==4 || turn==6)
                        decide=strategize_2(board,turn);
                    if(decide==0)
                    {
                        for(check=0;!check;)
                        {
                            key=rand()%9+1;
                            check=insert_Char(turn,key,board);
                        }
                    }
                }
                print_board(board);

                result=scan_forVictory(board);

                if(result==1 || result==2)
                {
                    printf(ANSI_COLOR_RED "\n\n                                                 Evil Computer has won.....\n\n  " ANSI_COLOR_RESET);
                    break;
                }
                else if(result==0)
                {
                    for(count=0,k=0;k<3;k++)
                        for(j=0;j<3;j++)
                            if(board[k][j]!=0)
                                count++;     /// If count==9, it means all the places on the board are filled,
                                             ///regardless of the completion of the 9 turns of the game.

                    if(count==9 || turn==9)  ///The game is a draw if there is no winner when all the places on the board are filled
                    {
                        printf("\n\n                                                  Game Drawn...\n\n  ");
                        break;
                    }
                }
            }
        }
    }
    printf("\n\n                                                  Do you wish to play again ?");
    printf("\n\n                                                  Press Y, if Yes,");
    printf("\n\n                                                  Press N, if No. ");
    scanf("%c",&restart);
    while(restart!='Y' || restart!='y' || restart!='N' || restart!='n')
    {
        if(restart=='Y' || restart=='y')
            main();
        if(restart=='N' || restart=='n')
            exit(0);
    }
}




///FUNCTION - print_board():
//prints the tic tac toe board.
void print_board(char board[3][3])
{
    int i,j;

    system("cls");
    printf("\n\n\n\n\n\n\n");
    printf("                                                   ******************************************************************");
    for(i=0;i<3;i++)
    {
        printf("\n                                                   *                           |       |                            *\n");
        for(j=0;j<3;j++)
        {
            if(j%3==0)
            {
                if(board[i][j]==0)
                    printf("                                                   *                       %c    ",board[i][j]);
                else
                {
                    if(board[i][j]=='X')
                    {
                        printf("                                                   *");
                        printf(ANSI_COLOR_YELLOW"                       %c   "ANSI_COLOR_RESET,board[i][j]);
                    }
                    if(board[i][j]=='O')
                    {
                        printf("                                                   *");
                        printf(ANSI_COLOR_CYAN"                       %c   "ANSI_COLOR_RESET,board[i][j]);
                    }
                }
            }
            else
            {
                if(j%3==1)
                {
                    if(board[i][j]==0)
                    printf("|   %c    ",board[i][j]);
                    else
                    {
                        if(board[i][j]=='X')
                        {
                            printf("|");
                            printf(ANSI_COLOR_YELLOW"   %c   "ANSI_COLOR_RESET,board[i][j]);
                        }
                        if(board[i][j]=='O')
                        {
                            printf("|");
                            printf(ANSI_COLOR_CYAN"   %c   "ANSI_COLOR_RESET,board[i][j]);
                        }
                    }
                }
                else
                {
                    if(board[i][j]==0)
                    printf("|   %c                         *",board[i][j]);
                    else
                    {
                        if(board[i][j]=='X')
                        {
                            printf("|");
                            printf(ANSI_COLOR_YELLOW"   %c   "ANSI_COLOR_RESET,board[i][j]);
                            printf("                     *");
                        }
                        if(board[i][j]=='O')
                        {
                            printf("|");
                            printf(ANSI_COLOR_CYAN"   %c   "ANSI_COLOR_RESET,board[i][j]);
                            printf("                     *");
                        }
                    }
                }
            }
        }
        if(i%3<2)
            printf("\n                                                   *                    _______|_______|_______                     *");
        else
            printf("\n                                                   *                           |       |                            *\n");

    }
    printf("                                                   ******************************************************************");
    printf("\n\n");
}



///FUNCTION - howToPlay()
//Shows user how to enter the mark on the user.
void howToPlay()
{
    system("cls");
    printf(ANSI_COLOR_YELLOW "\n\n\n\n                                                 ** HOW TO PLAY **" ANSI_COLOR_RESET);
    printf("\n                                                   Press the corresponding keys on the numpad\n                                                   to enter your mark on the desired location :---");
    printf("\n\n                                                   ******************************************************************");
    printf("\n                                                   *                          |         |                           *");
    printf("\n                                                   *                   Num 7  |  Num 8  |  Num 9                    *");
    printf("\n                                                   *                 _________|_________|_________                  *");
    printf("\n                                                   *                          |         |                           *");
    printf("\n                                                   *                   Num 4  |  Num 5  |  Num 6                    *");
    printf("\n                                                   *                 _________|_________|_________                  *");
    printf("\n                                                   *                          |         |                           *");
    printf("\n                                                   *                   Num 1  |  Num 2  |  Num 3                    *");
    printf("\n                                                   *                          |         |                           *");
    printf("\n                                                   ******************************************************************");
    printf("\n\n                                                   Press any key to continue....");
    getch();
}


///FUNCTION - int insert_Char()
//ensures that user does not mark a position that is already marked.
int insert_Char(int turn, int key, char board[3][3])
{
    switch(key)
    {
    case 7:
        if(board[0][0]=='X' || board[0][0]=='O')
            return(0);
        else
            {
                if(turn%2)
                    board[0][0]='X';
                else
                    board[0][0]='O';
                return(1); //  indicates entry at valid position.
            }

    case 8:
        if(board[0][1]=='X' || board[0][1]=='O')
            return(0);
        else
            {
                if(turn%2)
                    board[0][1]='X';
                else
                    board[0][1]='O';
                return(1); //  indicates entry at valid position.
            }

    case 9:
        if(board[0][2]=='X' || board[0][2]=='O')
            return(0);
        else
            {
                if(turn%2)
                    board[0][2]='X';
                else
                    board[0][2]='O';
                return(1); //  indicates entry at valid position.
            }

    case 4:
        if(board[1][0]=='X' || board[1][0]=='O')
            return(0);
        else
            {
                if(turn%2)
                    board[1][0]='X';
                else
                    board[1][0]='O';
                return(1); //  indicates entry at valid position.
            }

    case 5:
        if(board[1][1]=='X' || board[1][1]=='O')
            return(0);
        else
            {
                if(turn%2)
                    board[1][1]='X';
                else
                    board[1][1]='O';
                return(1); //  indicates entry at valid position.
            }

    case 6:
        if(board[1][2]=='X' || board[1][2]=='O')
            return(0);
        else
            {
                if(turn%2)
                    board[1][2]='X';
                else
                    board[1][2]='O';
                return(1); //  indicates entry at valid position.
            }

    case 1:
        if(board[2][0]=='X' || board[2][0]=='O')
            return(0);
        else
            {
                if(turn%2)
                    board[2][0]='X';
                else
                    board[2][0]='O';
                return(1); //  indicates entry at valid position.
            }

    case 2:
        if(board[2][1]=='X' || board[2][1]=='O')
            return(0);
        else
            {
                if(turn%2)
                    board[2][1]='X';
                else
                    board[2][1]='O';
                return(1); //  indicates entry at valid position.
            }

    case 3:
        if(board[2][2]=='X' || board[2][2]=='O')
            return(0);
        else
            {
                if(turn%2)
                    board[2][2]='X';
                else
                    board[2][2]='O';
                return(1); //  indicates entry at valid position.
            }

    default:
        return(0);
    }
}

///FUNCTION - title_Screen()
//Prints the title screen of the game.
void title_Screen()
{
    system("cls");

    printf("\n\n\n                                                  ******************************************************************");
    printf("\n                                                  *                           WELCOME TO                           *");
    printf("\n                                                  *                                                                *");

    printf("\n                                                  *                           |       |                            *");
    printf("\n                                                  *                    ");
    printf(ANSI_COLOR_RED "  TIC  " ANSI_COLOR_RESET);
    printf("|       |                            *");
    printf("\n                                                  *                    _______|_______|_______                     *");
    printf("\n                                                  *                           |       |                            *");
    printf("\n                                                  *                           |");
    printf(ANSI_COLOR_YELLOW "  TAC  " ANSI_COLOR_RESET);
    printf("|                            *");
    printf("\n                                                  *                    _______|_______|_______                     *");
    printf("\n                                                  *                           |       |                            *");
    printf("\n                                                  *                           |       |");
    printf(ANSI_COLOR_CYAN "  TOE  " ANSI_COLOR_RESET);
    printf("                     *");
    printf("\n                                                  *                           |       |                            *");
    printf("\n                                                  *                                                                *");
    printf("\n                                                  ******************************************************************");
    printf("\n\n   ");
    printf("\n                                                  Press any key to continue...");
    getch();
}



///FUCNTION - scan_forVictory() :
//scans the board to see if either of the player has won.
int scan_forVictory(char board[3][3])
{
    int i,j,X,O;
    int win=0;

    //ROWS = Code for checking rows.
    for(i=0;i<3;i++)
    {
        for(X=0,O=0,j=0;j<3;j++)
        {
            if(board[i][j]=='X')
                X++;
            if(board[i][j]=='O')
                O++;
        }
        if(X==3)
        {
            win=1;
            return(1);
        }
        if(O==3)
        {
            win=1;
            return(2);
        }
    }

    //COLUMNS = Code for checking columns.
    if(win==0) ///  If no victor was found when checking rows, program checks the columns.
    {
        for(j=0;j<3;j++)
        {
            for(X=0,O=0,i=0;i<3;i++)
            {
                if(board[i][j]=='X')
                    X++;
                if(board[i][j]=='O')
                    O++;
            }
            if(X==3)
            {
                win=1;
                return(1);
            }
            if(O==3)
            {
                win=1;
                return(2);
            }
        }
    }

    //DIAGONAL = Code for checking this diagonal : [(0,0),(1,1),(2,2)]
    if(win==0)  ///  If no victor was found when checking columns, program checks the first diagonal.
    {
        for(X=0,O=0,i=0;i<3;i++)
        {
            if(board[i][i]=='X')
                X++;
            if(board[i][i]=='O')
                O++;
            if(i==2)
            {
                if(X==3)
                {
                    win=1;
                    return(1);
                }
                if(O==3)
                {
                    win=1;
                    return(2);
                }
            }
        }
    }

    //DIAGONAL = Code for checking this diagonal : [(2,0),(1,1),(0,2)]
    if(win==0)  ///  If no victor was found when checking the first diagonal, program checks the second diagonal.
    for(X=0,O=0,i=2;i>=0;i--)
    {
        if(board[i][2-i]=='X')
            X++;
        if(board[i][2-i]=='O')
            O++;
        if(i==0)
        {
            if(X==3)
            {
                win=1;
                return(1);
            }
            if(O==3)
            {
                win=1;
                return(2);
            }
            else
                return(0); /// If no victor was found even in the last diagonal, the function returns 0.
        }
    }
}




///FUNCTION- int winLose(char[3][3],int) -
//To see if the computer is ABOUT TO win or lose and help it decide accordingly.
int winLose(char board[3][3],int start)
{
    int i,j,blank,checked,empty;
    char cMark,pMark;


    if(start==1)
    {
        cMark='X'; //If computer starts 1st, its mark is 'X' and Player's mark is 'O'
        pMark='O'; //cMark = computer's Mark, pMark = player's mark.
    }
    else
    {
        cMark='O'; //If computer starts 2nd, its mark is 'O' and Player's mark is 'X'
        pMark='X';
    }


    ///WINNING CONDITIONS FOR THE COMPUTER.
    ///The computer is supposed to prioritize its own victory over playing to defeat the user.
    ///That means, if any row,column or a diagonal
       //has two marks made by the computer and has an empty block, the computer should choose that block rather than preventing user's victory.


    //ROWS = Code for checking rows.
    for(i=0;i<3;i++)
    {
        for(blank=0,checked=0,empty=0,j=0;j<3;j++)
        {
            if(board[i][j]==cMark)
                checked++;
            if(board[i][j]==0)
            {
                blank = j;
                empty++;
            }
        }
        if(checked==2 && empty==1)
        {
            board[i][blank] = cMark;
            return(1);  /// Return(1) means computer has made a decision about its mark.
        }
    }

    //COLUMNS = Code for checking columns.
    for(j=0;j<3;j++)
    {
        for(blank=0,checked=0,empty=0,i=0;i<3;i++)
        {
            if(board[i][j]==cMark)
                checked++;
            if(board[i][j]==0)
            {
                blank = i;
                empty++;
            }
        }
        if(checked==2 && empty==1)
        {
            board[blank][j] = cMark;
            return(1);
        }
    }

    //DIAGONAL = Code for checking this diagonal : [(0,0),(1,1),(2,2)]
    for(blank=0,checked=0,empty=0,i=0;i<3;i++)
    {
        if(board[i][i]==cMark)
            checked++;
        if(board[i][i]==0)
        {
            blank = i;
            empty=1;
        }
        if(checked==2 && empty==1)
        {
            board[blank][blank] = cMark;
            return(1);
        }
    }

    //DIAGONAL = Code for checking this diagonal : [(2,0),(1,1),(2,2)]
    for(blank=0,checked=0,empty=0, i=2;i>=0;i--)
    {
        if(board[i][2-i]==cMark)
            checked++;
        if(board[i][2-i]==0)
        {
            blank = i;
            empty=1;
        }
        if(checked==2 && empty==1)
        {
            board[blank][2-blank] = cMark;
            return(1);
        }
    }
    ///If at some point, the computer is not in winning position, but the user is, then it must prevent user's victory.



    ///LOSING CONDITIONS FOR COMPUTER:
    ///When user has successfully marked two out of three boxes in a row,column or in a diagonal.
    ///In such a situation, computer has to prevent user's victory by making its mark.

    //ROWS
    for(i=0;i<3;i++)
    {
        for(blank=0,checked=0,empty=0,j=0;j<3;j++)
        {
            if(board[i][j]==pMark)
                checked++;
            if(board[i][j]==0)
            {
                blank = j;
                empty++;
            }
        }
        if(checked==2 && empty==1)
        {
            board[i][blank] = cMark;
            return(1);
        }
    }

    //COLUMNS
    for(j=0;j<3;j++)
    {
        for(blank=0,checked=0,empty=0,i=0;i<3;i++)
        {
            if(board[i][j]==pMark)
                checked++;
            if(board[i][j]==0)
            {
                blank = i;
                empty++;
            }
        }
        if(checked==2 && empty==1)
        {
            board[blank][j] = cMark;
            return(1);
        }
    }

    //DIAGONAL [(0,0),(1,1),(2,2)]
    for(blank=0,checked=0,empty=0,i=0;i<3;i++)
    {
        if(board[i][i]==pMark)
            checked++;
        if(board[i][i]==0)
        {
            blank = i;
            empty=1;
        }
        if(checked==2 && empty==1)
        {
            board[blank][blank] = cMark;
            return(1);
        }
    }

    //DIAGONAL [(2,0),(1,1),(2,2)]
    for(blank=0,checked=0,empty=0, i=2;i>=0;i--)
    {
        if(board[i][2-i]==pMark)
            checked++;
        if(board[i][2-i]==0)
        {
            blank = i;
            empty=1;
        }
        if(checked==2 && empty==1)
        {
            board[blank][2-blank] = cMark;
            return(1);
        }
    }

    return(0); ///  return(0) means none of the above conditions have been met., which means that computer is neither winning, nor losing currently in the game.
               ///  If the computer is neither winning nor losing, it will see if it can strategize by calling appropriate functions.

}




///FUNCTION- int evil_winLose(char[3][3],int) -
//This function shows the evil computer at what places it is going to lose and allows it to mark more than one place.
int evil_winLose(char board[3][3],int start)
{
    int i,j,blank,checked,empty,cheat=0;
    char cMark,pMark;


    if(start==1)
    {
        cMark='X'; //If computer starts 1st, its mark is 'X' and Player's mark is 'O'
        pMark='O'; //cMark = computer's Mark, pMark = player's mark.
    }
    else
    {
        cMark='O'; //If computer starts 2nd, its mark is 'O' and Player's mark is 'X'
        pMark='X';
    }


    ///WINNING CONDITIONS FOR THE COMPUTER.
    ///The computer is supposed to prioritize its own victory over playing to defeat the user.
    ///That means, if any row,column or a diagonal
       //has two marks made by the computer and has an empty block, the computer should choose that block rather than preventing user's victory.


    //ROWS = Code for checking rows.
    for(i=0;i<3;i++)
    {
        for(blank=0,checked=0,empty=0,j=0;j<3;j++)
        {
            if(board[i][j]==cMark)
                checked++;
            if(board[i][j]==0)
            {
                blank = j;
                empty++;
            }
        }
        if(checked==2 && empty==1)
        {
            board[i][blank] = cMark;
            return(1);  /// Return(1) means computer has made a decision about its mark.
        }
    }

    //COLUMNS = Code for checking columns.
    for(j=0;j<3;j++)
    {
        for(blank=0,checked=0,empty=0,i=0;i<3;i++)
        {
            if(board[i][j]==cMark)
                checked++;
            if(board[i][j]==0)
            {
                blank = i;
                empty++;
            }
        }
        if(checked==2 && empty==1)
        {
            board[blank][j] = cMark;
            return(1);
        }
    }

    //DIAGONAL = Code for checking this diagonal : [(0,0),(1,1),(2,2)]
    for(blank=0,checked=0,empty=0,i=0;i<3;i++)
    {
        if(board[i][i]==cMark)
            checked++;
        if(board[i][i]==0)
        {
            blank = i;
            empty=1;
        }
        if(checked==2 && empty==1)
        {
            board[blank][blank] = cMark;
            return(1);
        }
    }

    //DIAGONAL = Code for checking this diagonal : [(2,0),(1,1),(2,2)]
    for(blank=0,checked=0,empty=0, i=2;i>=0;i--)
    {
        if(board[i][2-i]==cMark)
            checked++;
        if(board[i][2-i]==0)
        {
            blank = i;
            empty=1;
        }
        if(checked==2 && empty==1)
        {
            board[blank][2-blank] = cMark;
            return(1);
        }
    }
    ///If at some point, the computer is not in winning position, but the user is, then it must prevent user's victory.



    ///LOSING CONDITIONS FOR COMPUTER:
    ///When user has successfully marked two out of three boxes in a row,column or in a diagonal.
    ///In such a situation, computer has to prevent user's victory by making its mark.

    //ROWS
    for(i=0;i<3;i++)
    {
        for(blank=0,checked=0,empty=0,j=0;j<3;j++)
        {
            if(board[i][j]==pMark)
                checked++;
            if(board[i][j]==0)
            {
                blank = j;
                empty++;
            }
        }
        if(checked==2 && empty==1)
        {
            board[i][blank] = cMark;
            cheat++;
        }
    }

    //COLUMNS
    for(j=0;j<3;j++)
    {
        for(blank=0,checked=0,empty=0,i=0;i<3;i++)
        {
            if(board[i][j]==pMark)
                checked++;
            if(board[i][j]==0)
            {
                blank = i;
                empty++;
            }
        }
        if(checked==2 && empty==1)
        {
            board[blank][j] = cMark;
            cheat++;
            if(cheat==2)
                return(1);
        }
    }

    //DIAGONAL [(0,0),(1,1),(2,2)]
    for(blank=0,checked=0,empty=0,i=0;i<3;i++)
    {
        if(board[i][i]==pMark)
            checked++;
        if(board[i][i]==0)
        {
            blank = i;
            empty=1;
        }
        if(checked==2 && empty==1)
        {
            board[blank][blank] = cMark;
            cheat++;
            if(cheat==2)
                return(1);
        }
    }

    //DIAGONAL [(2,0),(1,1),(2,2)]
    for(blank=0,checked=0,empty=0, i=2;i>=0;i--)
    {
        if(board[i][2-i]==pMark)
            checked++;
        if(board[i][2-i]==0)
        {
            blank = i;
            empty=1;
        }
        if(checked==2 && empty==1)
        {
            board[blank][2-blank] = cMark;
            cheat++;
            if(cheat==2)
                return(1);
        }
    }

    return(0); ///  return(0) means none of the above conditions have been met., which means that computer is neither winning, nor losing currently in the game.
               ///  If the computer is neither winning nor losing, it will see if it can strategize by calling appropriate functions.

}




///FUNCTION - strategize_1()
//Helps computer come up with some strategy when 1st turn of the game was computer's
int strategize_1(char board[3][3],int turn) /// Used to analyze the board at Game's third turn i.e. computer's second turn)
{
    int place;

    ///POSIT 2: ( VERIFIED )
    if(board[0][0]=='X' && board[0][2]=='O')
    {
        if(turn==3)
        {
            board[2][1]='X';
            return(1);
        }
        if(turn==5 && board[0][1]=='O')
        {
            board[2][2]='X';
            return(1);
        }
        else if(turn==5 && board[1][0]=='O')
        {
            board[1][1]='X';
            return(1);
        }
        else
            return(0);
    }
    else if(board[0][0]=='X' && board[2][0]=='O')
    {
        if(turn==3)
        {
            board[1][2]='X';
            return(1);
        }
        if(turn==5 && board[1][0]=='O')
        {
            board[2][2]='X';
            return(1);
        }
        else if(turn==5 && board[2][1]=='O')
        {
            board[1][1]='X';
            return(1);
        }
        else
            return(0);
    }
    else if(board[0][2]=='X' && board[0][0]=='O')
    {
        if(turn==3)
        {
            board[2][1]='X';
            return(1);
        }
        if(turn==5 && board[0][1]=='O')
        {
            board[2][0]='X';
            return(1);
        }
        else if(turn==5 && board[1][2]=='O')
        {
            board[1][1]='X';
            return(1);
        }
        else
            return(0);
    }
    else if(board[0][2]=='X' && board[2][2]=='O')
    {
        if(turn==3)
        {
            board[1][0]='X';
            return(1);
        }
        if(turn==5 && board[1][2]=='O')
        {
            board[2][0]='X';
            return(1);
        }
        else if(turn==5 && board[0][1]=='O')
        {
            board[1][1]='X';
            return(1);
        }
        else
            return(0);
    }
    else if(board[2][2]=='X' && board[2][0]=='O')
    {
        if(turn==3)
        {
            board[0][1]='X';
            return(1);
        }
        if(turn==5 && board[2][1]=='O')
        {
            board[0][0]='X';
            return(1);
        }
        else if(turn==5 && board[1][2]=='O')
        {
            board[1][1]='X';
            return(1);
        }
        else
            return(0);
    }
    else if(board[2][2]=='X' && board[0][2]=='O')
    {
        if(turn==3)
        {
            board[1][0]='X';
            return(1);
        }
        if(turn==5 && board[1][2]=='O')
        {
            board[0][0]='X';
            return(1);
        }
        else if(turn==5 && board[2][1]=='O')
        {
            board[1][1]='X';
            return(1);
        }
        else
            return(0);
    }
    else if(board[2][0]=='X' && board[2][2]=='O')
    {
        if(turn==3)
        {
            board[0][1]='X';
            return(1);
        }
        if(turn==5 && board[2][1]=='O')
        {
            board[0][2]='X';
            return(1);
        }
        else if(turn==5 && board[1][0]=='O')
        {
            board[1][1]='X';
            return(1);
        }
        else
            return(0);
    }
    else if(board[2][0]=='X' && board[0][0]=='O')
    {
        if(turn==3)
        {
            board[1][2]='X';
            return(1);
        }
        if(turn==5 && board[1][0]=='O')
        {
            board[0][2]='X';
            return(1);
        }
        else if(turn==5 && board[2][1]=='O')
        {
            board[1][1]='X';
            return(1);
        }
        else
            return(0);
    }


    ///POSIT 3 and 4:
    if(turn==3 && board[1][1]=='O')
    {
        if(rand()%2)
        {
            if(board[0][0]=='X')
                if(rand()%2)
                {
                    board[1][2]='X';
                    return(1);
                }
                else
                {
                    board[2][1]='X';
                    return(1);
                }
            else if(board[2][0]=='X')
                if(rand()%2)
                {
                    board[1][2]='X';
                    return(1);
                }
                else
                {
                    board[0][1]='X';
                    return(1);
                }
            else if(board[2][2]=='X')
                if(rand()%2)
                {
                    board[1][0]='X';
                    return(1);
                }
                else
                {
                    board[0][1]='X';
                    return(1);
                }
            else if(board[0][2]='X')
            {
                if(rand()%2)
                {
                    board[1][0]='X';
                    return(1);
                }
                else
                {
                    board[2][1]='X';
                    return(1);
                }
            }
        }
        else
        {
            if(board[0][0]=='X')
                board[2][2]='X';
            else if(board[2][0]=='X')
                board[2][2]='X';
            else if(board[2][2]=='X')
                board[0][0]='X';
            else if(board[0][2]='X')
                board[2][0]='X';
            return(1);
        }
    }
    if(turn==5)
    {
        if(board[0][0]=='X' && board[1][1]=='O' && board[2][2]=='X')
        {
            if(board[2][0]=='O')
            {
                board[0][2]='X';
                return(1);
            }
            else if(board[0][2]=='O')
            {
                board[2][0]='X';
                return(1);
            }
        }
        else if(board[2][0]=='X' && board[1][1]=='O' && board[0][2]=='X')
        {
            if(board[0][0]=='O')
            {
                board[2][2]='X';
                return(1);
            }
            else if(board[2][2]=='O')
            {
                board[0][0]='X';
                return(1);
            }
        }
        else if((board[1][1]=='O' && board[0][0]=='X' && board[1][2]=='X') && (board[2][0]=='O' || board[1][0]=='O'))
        {
            board[0][2]='X';
            return(1);
        }
        else if((board[1][1]=='O' && board[0][0]=='X' && board[2][1]=='X') && (board[0][1]=='O' || board[0][2]=='O'))
        {
            board[2][0]='X';
            return(1);
        }
        else if((board[1][1]=='O' && board[2][0]=='X' && board[1][2]=='X') && (board[1][0]=='O' || board[0][0]=='O'))
        {
            board[2][2]='X';
            return(1);
        }
        else if((board[1][1]=='O' && board[2][0]=='X' && board[0][1]=='X') && (board[2][1]=='O' || board[2][2]=='O'))
        {
            board[0][0]='X';
            return(1);
        }
        else if((board[1][1]=='O' && board[2][2]=='X' && board[1][0]=='X') && (board[1][2]=='O' || board[0][2]=='O'))
        {
            board[2][0]='X';
            return(1);
        }
        else if((board[1][1]=='O' && board[2][2]=='X' && board[0][1]=='X') && (board[2][0]=='O' || board[2][1]=='O'))
        {
            board[0][2]='X';
            return(1);
        }
        else if((board[1][1]=='O' && board[0][2]=='X' && board[1][0]=='X') && (board[1][2]=='O' || board[2][2]=='O'))
        {
            board[0][0]='X';
            return(1);
        }
        else if((board[1][1]=='O' && board[0][2]=='X' && board[2][1]=='X') && (board[0][0]=='O' || board[0][1]=='O'))
        {
            board[2][2]='X';
            return(1);
        }
        else
            return(0);
    }



        ///POSIT 5:
        if(board[0][0]=='X' && board[1][1]=='X' && board[2][2]=='O')
        {
            if(board[0][1]=='O')
            {
                board[1][0]=='X';
                return(1);
            }
            else if(board[1][0]=='O')
            {
                board[0][1]='X';
                return(1);
            }
            else if(board[2][0]=='X' && board[1][1]=='X' && board[0][2]=='O')
                if(board[1][0]=='O')
                {
                    board[2][1]=='X';
                    return(1);
                }
                else if(board[2][1]=='O')
                {
                    board[1][0]='X';
                    return(1);
                }
            else if(board[2][2]=='X' && board[1][1]=='X' && board[0][0]=='O')
                if(board[2][1]=='O')
                {
                    board[1][2]=='X';
                    return(1);
                }
                else if(board[2][1]=='O')
                {
                    board[1][2]='X';
                    return(1);
                }
            else if(board[0][2]=='X' && board[1][1]=='X' && board[2][0]=='O')
                if(board[1][2]=='O')
                {
                    board[0][1]=='X';
                    return(1);
                }
                else if(board[0][1]=='O')
                {
                    board[1][2]='X';
                    return(1);
                }
           else
                return(0);
        }


        ///POSIT 8:
        if(turn==5)
        {
            if((board[0][1]=='X' && board[1][0]=='X' && board[1][1]=='O') && (board[1][2]=='O' || board[2][1]=='O' || board[2][2]=='O'))
                {
                    board[0][0]='X';
                    return(1);
                }
            else if((board[1][0]=='X' && board[2][1]=='X' && board[1][1]=='O') && (board[0][1]=='O' || board[0][2]=='O' || board[1][2]=='O'))
                {
                    board[2][0]='X';
                    return(1);
                }
            else if((board[2][1]=='X' && board[1][2]=='X' && board[1][1]=='O') && (board[0][1]=='O' || board[0][0]=='O' || board[1][0]=='O'))
                {
                    board[2][2]='X';
                    return(1);
                }
            else if((board[1][2]=='X' && board[0][1]=='X' && board[1][1]=='O') && (board[1][0]=='O' || board[2][0]=='O' || board[2][1]=='O'))
                {
                    board[0][2]='X';
                    return(1);
                }
            else
                return(0);
        }


        ///POSIT 9:
        if(turn==3)
        {
            if(board[0][0]=='X' && board[2][1]=='O')       //if(board[2][1]=='O' && board[0][0]=='X' && board[1][2]=='X')
            {
                board[1][2]='X';
                return(1);
            }
            else if(board[0][2]=='X' && board[2][1]=='O')  //if(board[2][1]=='O' && board[1][0]=='X' && board[0][2]=='X')
            {
                board[1][0]='X';
                return(1);
            }
            else if(board[0][2]=='X' && board[1][0]=='O')  //if(board[1][0]=='O' && board[2][1]=='X' && board[0][2]=='X')
            {
                board[2][1]='X';
                return(1);
            }
            else if(board[0][1]=='X' && board[1][0]=='O')  //***if(board[1][0]=='O' && board[0][1]=='X' && board[2][0]=='X')
            {
                board[2][2]='X';
                return(1);
            }
            else if(board[1][0]=='X' && board[0][1]=='O')  //if(board[0][1]=='O' && board[1][0]=='X' && board[2][2]=='X')
            {
                board[2][2]='X';
                return(1);
            }
            else if(board[2][0]=='X' && board[0][1]=='O')  //if(board[0][1]=='O' && board[2][0]=='X' && board[1][2]=='X')
            {
                board[1][2]='X';
                return(1);
            }
            else if(board[0][1]=='X' && board[1][2]=='O')  //if(board[1][2]=='O' && board[0][1]=='X' && board[2][0]=='X')
            {
                board[2][0]='X';
                return(1);
            }
            else if(board[0][0]=='X' && board[1][2]=='O')  //if(board[1][2]=='O' && board[0][0]=='X' && board[2][1]=='X')
            {
                board[2][1]='X';
                return(1);
            }
        }
        else if(turn==5)
        {
            if(board[0][1]=='O' && board[1][0]=='X' && board[2][2]=='X')
            {
                if(board[1][2]=='O' || board[2][0]=='O')
                {
                    board[1][1]='X';
                    return(1);
                }
                else
                    return(0);

            }
            else if(board[0][1]=='O' && board[2][0]=='X' && board[1][2]=='X')
            {
                if(board[2][2]=='O' || board[1][0]=='O')
                {
                    board[1][1]='X';
                    return(1);
                }
                else
                    return(0);
            }
            else if(board[1][0]=='O' && board[2][1]=='X' && board[0][2]=='X')
            {
                if(board[0][1]=='O' || board[2][2]=='O')
                {
                    board[1][1]='X';
                    return(1);
                }
                else
                    return(0);
            }
            else if(board[1][0]=='O' && board[0][1]=='X' && board[2][2]=='X')  //if(board[1][0]=='O' && board[0][1]=='X' && board[2][2]=='X')
            {
                if(board[2][1]=='O' || board[0][2]=='O')
                {
                    board[1][1]='X';
                    return(1);
                }
                else
                    return(0);
            }
            else if(board[2][1]=='O' && board[0][0]=='X' && board[1][2]=='X')
            {
                if(board[1][0]=='O' || board[0][2]=='O')
                {
                    board[1][1]='X';
                    return(1);
                }
                else
                    return(0);
            }
            else if(board[2][1]=='O' && board[1][0]=='X' && board[0][2]=='X')
            {
                if(board[0][0]=='O' || board[1][2]=='O')
                {
                    board[1][1]='X';
                    return(1);
                }
                else
                    return(0);
            }
            else if(board[1][2]=='O' && board[0][1]=='X' && board[2][0]=='X')
            {
                if(board[0][0]=='O' || board[2][1]=='O')
                {
                    board[1][1]='X';
                    return(1);
                }
                else
                    return(0);
            }
            else if(board[1][2]=='O' && board[0][0]=='X' && board[2][1]=='X')
            {
                if(board[0][1]=='O' || board[2][0]=='O')
                {
                    board[1][1]='X';
                    return(1);
                }
                else
                    return(0);
            }
        }

        ///POSIT 10:
        if(turn==3)
        {
            if(board[0][1]=='O' && board[2][1]=='X')
            {
                board[1][2]=='X';
                return(1);
            }
            else if(board[0][1]=='O' && board[2][1]=='X')
            {
                board[1][0]=='X';
                return(1);
            }
            else if(board[1][0]=='O' && board[1][2]=='X')
            {
                board[2][1]=='X';
                return(1);
            }
            else if(board[1][0]=='O' && board[1][2]=='X')
            {
                board[0][1]=='X';
                return(1);
            }
            else if(board[2][1]=='O' && board[0][1]=='X')
            {
                board[1][2]=='X';
                return(1);
            }
            else if(board[2][1]=='O' && board[0][1]=='X')
            {
                board[1][0]=='X';
                return(1);
            }
            else if(board[1][2]=='O' && board[1][0]=='X')
            {
                board[2][1]=='X';
                return(1);
            }
            else if(board[1][2]=='O' && board[1][0]=='X')
            {
                board[0][1]=='X';
                return(1);
            }
            else
                return(0);
        }
        else if(turn==5)
        {
            if(board[0][1]=='O' && board[2][1]=='X' && board[1][2]=='X')
            {
                board[2][2]='O';
                return(1);
            }
            else if(board[0][1]=='O' && board[2][1]=='X' && board[1][0]=='X')
            {
                board[2][0]='O';
                return(1);
            }
            else if(board[1][0]=='O' && board[1][2]=='X' && board[2][1]=='X')
            {
                board[2][2]='O';
                return(1);
            }
            else if(board[1][0]=='O' && board[1][2]=='X' && board[0][1]=='X')
            {
                board[0][2]='O';
                return(1);
            }
            else if(board[2][1]=='O' && board[0][1]=='X' && board[1][2]=='X')
            {
                board[0][2]='O';
                return(1);
            }
            else if(board[2][1]=='O' && board[0][1]=='X' && board[1][0]=='X')
            {
                board[0][0]='O';
                return(1);
            }
            else if(board[1][2]=='O' && board[1][0]=='X' && board[2][1]=='X')
            {
                board[2][0]='O';
                return(1);
            }
            else if(board[1][2]=='O' && board[1][0]=='X' && board[0][1]=='X')
            {
                board[0][0]='O';
                return(1);
            }
            else
                return(0);
        }


        ///POSIT 10 A:
        if(turn==3)
        {
            if(board[0][1]=='X' && board[0][0]=='O')
            {
                board[1][0]=='X';
                return(1);
            }
            else if(board[0][1]=='X' && board[0][2]=='O')
            {
                board[1][2]=='X';
                return(1);
            }
            else if(board[1][0]=='X' && board[0][0]=='O')
            {
                board[0][1]=='X';
                return(1);
            }
            else if(board[1][0]=='X' && board[2][0]=='O')
            {
                board[2][1]=='X';
                return(1);
            }
            else if(board[2][1]=='X' && board[2][0]=='O')
            {
                board[1][0]=='X';
                return(1);
            }
            else if(board[2][1]=='X' && board[2][2]=='O')
            {
                board[1][2]=='X';
                return(1);
            }
            else if(board[1][2]=='X' && board[2][2]=='O')
            {
                board[2][1]=='X';
                return(1);
            }
            else if(board[1][2]=='X' && board[0][2]=='O')
            {
                board[0][1]=='X';
                return(1);
            }
            else
                return(0);
        }
        else if(turn==5)
        {
            if(board[0][1]=='X' && board[0][0]=='O' && board[1][0]=='X')
            {
                if(board[2][0]=='O' || board[2][2]=='O' || board[0][2]=='O')
                {
                    board[1][1]='X';
                    return(1);
                }
                else
                    return(0);
            }
            else if(board[0][1]=='X' && board[0][2]=='O' && board[1][2]=='X')
            {
                if(board[0][0]=='O' || board[2][0]=='O' || board[2][2]=='O')
                {
                    board[1][1]='X';
                    return(1);
                }
                else
                    return(0);
            }
            else if(board[1][0]=='X' && board[2][0]=='O' && board[2][1]=='X')
            {
                if(board[0][0]=='O' || board[2][2]=='O' || board[0][2]=='O')
                {
                    board[1][1]='X';
                    return(1);
                }
                else
                    return(0);
            }
            else if(board[2][1]=='X' && board[2][2]=='O' && board[1][2]=='X')
            {
                if(board[0][0]=='O' || board[0][2]=='O' || board[2][0]=='O')
                {
                    board[1][1]='X';
                    return(1);
                }
                else
                    return(0);
            }
        }




        ///POSIT 11:
        if(turn==3)
        {
            if(board[0][1]=='O')
            {
                if(board[1][1]=='X')
                {
                    board[2][1]=='X';
                    return(1);
                }
                else if(board[2][1]=='X')
                {
                    board[1][1]=='X';
                    return(1);
                }
            }
            else if(board[1][0]=='O')
            {
                if(board[1][1]=='X')
                {
                    board[1][2]=='X';
                    return(1);
                }
                else if(board[1][2]=='X')
                {
                    board[1][1]=='X';
                    return(1);
                }
            }
            else if(board[2][1]=='O')
            {
                if(board[1][1]=='X')
                {
                    board[0][1]=='X';
                    return(1);
                }
                else if(board[0][1]=='X')
                {
                    board[1][1]=='X';
                    return(1);
                }
            }
            else if(board[1][2]=='O')
            {
                if(board[1][1]=='X')
                {
                    board[1][0]=='X';
                    return(1);
                }
                else if(board[1][0]=='X')
                {
                    board[1][1]=='X';
                    return(1);
                }
            }
            else
                return(0);
        }
        else if(turn==5)
        {
            if(board[0][1]=='O' && board[1][1]=='X' && board[2][1]=='X')
            {
                if(board[1][0]=='O' || board[1][2]=='O')
                {
                    if(rand()%2)
                    {
                        board[2][0]='X';
                        return(1);
                    }
                    else
                    {
                        board[2][2]='X';
                        return(1);
                    }
                }
                else if(board[2][0]=='O')
                {
                    board[0][0]=='X';
                    return(1);
                }
                else if(board[2][2]=='O')
                {
                    board[0][2]='X';
                    return(1);
                }
            }
            else if(board[1][0]=='O' && board[1][1]=='X' && board[1][2]=='X')
            {
                if(board[0][1]=='O' || board[2][1]=='O')
                {
                    if(rand()%2)
                    {
                        board[0][2]='X';
                        return(1);
                    }
                    else
                    {
                        board[2][2]='X';
                        return(1);
                    }
                }
                else if(board[0][2]=='O')
                {
                    board[0][0]=='X';
                    return(1);
                }
                else if(board[2][2]=='O')
                {
                    board[2][0]='X';
                    return(1);
                }
            }
            else if(board[2][1]=='O' && board[1][1]=='X' && board[0][1]=='X')
            {
                if(board[1][0]=='O' || board[1][2]=='O')
                {
                    if(rand()%2)
                    {
                        board[0][0]='X';
                        return(1);
                    }
                    else
                    {
                        board[0][2]='X';
                        return(1);
                    }
                }
                else if(board[0][0]=='O')
                {
                    board[2][0]=='X';
                    return(1);
                }
                else if(board[0][2]=='O')
                {
                    board[2][2]='X';
                    return(1);
                }
            }
            else if(board[1][2]=='O' && board[1][1]=='X' && board[1][0]=='X')
            {
                if(board[0][1]=='O' || board[2][1]=='O')
                {
                    if(rand()%2)
                    {
                        board[0][0]='X';
                        return(1);
                    }
                    else
                    {
                        board[2][0]='X';
                        return(1);
                    }
                }
                else if(board[0][0]=='O')
                {
                    board[0][2]=='X';
                    return(1);
                }
                else if(board[2][0]=='O')
                {
                    board[2][2]='X';
                    return(1);
                }
            }
            else
                return(0);
        }
}


///FUNCTION - strategize_2()
// Helps computer decide its moves when it plays after user.
int strategize_2(char board[3][3],int turn) ///Used to analyze the board at the 4th and 6th turn of the game, i.e. computer's 2nd and 3rd turn.
{
    int place;

    if(turn==4)
    {
                ///POSIT 2:
        if(board[0][0]=='O' && board[0][2]=='X' && board[2][1]=='X')
        {
            board[2][0]='O';
            return(1);
        }
        else if(board[2][0]=='O' && board[0][1]=='X' && board[2][2]=='X')
        {
            board[2][0]='O';
            return(1);
        }
        else if(board[2][2]=='O' && board[2][0]=='X' && board[0][2]=='X')
        {
            board[2][0]='O';
            return(1);
        }
        else if(board[0][2]=='O' && board[0][0]=='X' && board[2][1]=='X')
        {
            board[2][0]='O';
            return(1);
        }


        ///POSIT 3: USER-diagonal(2), COMP-center:
        if((board[2][0]=='X' && board[1][1]=='O' && board[2][0]=='X') || (board[0][0]=='X' && board[1][1]=='O' && board[2][2]=='X'))
        {
            place=rand()%4;
            switch(place)
            {
            case 0:
                board[2][1]='O';
                return(1);
            case 1:
                board[1][0]='O';
                return(1);
            case 2:
                board[1][2]='O';
                return(1);
            case 3:
                board[0][1]='O';
                return(1);
            }
        }

        ///POSIT 4:
        if(board[1][1]=='O' && board[0][0]=='X' && board[1][2]=='X')
        {
            place=rand()%4;
            switch(place)
            {
            case 0:
                board[0][1]='O';
                return(1);
            case 1:
                board[0][2]='O';
                return(1);
            case 2:
                board[2][1]='O';
                return(1);
            case 3:
                board[2][2]='O';
                return(1);
            }
        }
        else if(board[1][1]=='O' && board[0][0]=='X' && board[2][1]=='X')
        {
            place=rand()%4;
            switch(place)
            {
            case 0:
                board[1][0]='O';
                return(1);
            case 1:
                board[2][0]='O';
                return(1);
            case 2:
                board[1][2]='O';
                return(1);
            case 3:
                board[2][2]='O';
                return(1);
            }
        }
        else if(board[1][1]=='O' && board[2][0]=='X' && board[1][2]=='X')
        {
            place=rand()%4;
            switch(place)
            {
            case 0:
                board[0][1]='O';
                return(1);
            case 1:
                board[0][2]='O';
                return(1);
            case 2:
                board[2][1]='O';
                return(1);
            case 3:
                board[2][2]='O';
                return(1);
            }
        }
        else if(board[1][1]=='O' && board[2][0]=='X' && board[0][1]=='X')
        {
            place=rand()%4;
            switch(place)
            {
            case 0:
                board[0][0]='O';
                return(1);
            case 1:
                board[0][2]='O';
                return(1);
            case 2:
                board[1][0]='O';
                return(1);
            case 3:
                board[1][2]='O';
                return(1);
            }
        }
        else if(board[1][1]=='O' && board[2][2]=='X' && board[1][0]=='X')
        {
            place=rand()%4;
            switch(place)
            {
            case 0:
                board[0][0]='O';
                return(1);
            case 1:
                board[0][1]='O';
                return(1);
            case 2:
                board[2][0]='O';
                return(1);
            case 3:
                board[2][1]='O';
                return(1);
            }
        }
        else if(board[1][1]=='O' && board[2][2]=='X' && board[0][1]=='X')
        {
            place=rand()%4;
            switch(place)
            {
            case 0:
                board[0][0]='O';
                return(1);
            case 1:
                board[1][0]='O';
                return(1);
            case 2:
                board[0][2]='O';
                return(1);
            case 3:
                board[1][2]='O';
                return(1);
            }
        }
        else if(board[1][1]=='O' && board[0][2]=='X' && board[1][0]=='X')
        {
            place=rand()%4;
            switch(place)
            {
            case 0:
                board[0][0]='O';
                return(1);
            case 1:
                board[2][0]='O';
                return(1);
            case 2:
                board[2][1]='O';
                return(1);
            case 3:
                board[0][1]='O';
                return(1);
            }
        }
        else if(board[1][1]=='O' && board[0][2]=='X' && board[2][1]=='X')
        {
            place=rand()%4;
            switch(place)
            {
            case 0:
                board[1][0]='O';
                return(1);
            case 1:
                board[2][0]='O';
                return(1);
            case 2:
                board[1][2]='O';
                return(1);
            case 3:
                board[2][2]='O';
                return(1);
            }
        }



        ///POSIT 5:
        if(board[2][0]=='O' && board[0][2]=='X' && board[1][1]=='X')
        {
            place=rand()%3;
            switch(place)
            {
            case 0:
                board[0][0]='O';
                return(1);
            case 1:
                board[1][2]='O';
                return(1);
            case 2:
                board[2][2]='O';
                return(1);
            }

        }
        else if(board[2][2]=='O' && board[0][0]=='X' && board[1][1]=='X')
        {
            place=rand()%3;
            switch(place)
            {
            case 0:
                board[2][0]='O';
                return(1);
            case 1:
                board[0][1]='O';
                return(1);
            case 2:
                board[0][2]='O';
                return(1);
            }
        }
        else if(board[0][2]=='O' && board[2][0]=='X' && board[1][1]=='X')
        {
            place=rand()%3;
            switch(place)
            {
            case 0:
                board[0][0]='O';
                return(1);
            case 1:
                board[1][0]='O';
                return(1);
            case 2:
                board[2][2]='O';
                return(1);
            }
        }
        else if(board[0][0]=='O' && board[2][2]=='X' && board[1][1]=='X')
        {
           place=rand()%3;
            switch(place)
            {
            case 0:
                board[0][2]='O';
                return(1);
            case 1:
                board[2][0]='O';
                return(1);
            case 2:
                board[2][1]='O';
                return(1);
            }
        }





        /// POSIT 8:
        if(board[1][1]=='O' && board[0][1]=='X' && board[1][0]=='X')
        {
            place=rand()%3;
            switch(place)
            {
            case 0:
                board[0][0]='O';
                return(1);
            case 1:
                board[0][2]='O';
                return(1);
            case 2:
                board[2][0]='O';
                return(1);
            }

        }
        else if(board[1][1]=='O' && board[1][0]=='X' && board[2][1]=='X')
        {
            place=rand()%3;
            switch(place)
            {
            case 0:
                board[2][0]='O';
                return(1);
            case 1:
                board[0][0]='O';
                return(1);
            case 2:
                board[2][2]='O';
                return(1);
            }
        }
        else if(board[1][1]=='O' && board[2][1]=='X' && board[1][2]=='X')
        {
            place=rand()%3;
            switch(place)
            {
            case 0:
                board[2][2]='O';
                return(1);
            case 1:
                board[0][2]='O';
                return(1);
            case 2:
                board[2][0]='O';
                return(1);
            }
        }
        else if(board[1][1]=='O' && board[1][2]=='X' && board[0][1]=='X')
        {
           place=rand()%3;
            switch(place)
            {
            case 0:
                board[0][2]='O';
                return(1);
            case 1:
                board[0][0]='O';
                return(1);
            case 2:
                board[2][2]='O';
                return(1);
            }
        }


        ///POSIT 9:
        if(board[0][1]=='O' && board[1][0]=='X' && board[2][2]=='X')
        {
            place=rand()%3;
            switch(place)
            {
            case 0:
                board[0][0]='O';
                return(1);
            case 1:
                board[1][1]='O';
                return(1);
            case 2:
                board[2][0]='O';
                return(1);
            }
        }
        else if(board[0][1]=='O' && board[2][0]=='X' && board[1][2]=='X')
        {
            place=rand()%3;
            switch(place)
            {
            case 0:
                board[0][2]='O';
                return(1);
            case 1:
                board[1][1]='O';
                return(1);
            case 2:
                board[2][2]='O';
                return(1);
            }
        }
        else if(board[1][0]=='O' && board[2][1]=='X' && board[0][2]=='X')
        {
            place=rand()%3;
            switch(place)
            {
            case 0:
                board[2][0]='O';
                return(1);
            case 1:
                board[1][1]='O';
                return(1);
            case 2:
                board[2][2]='O';
                return(1);
            }
        }
        else if(board[1][0]=='O' && board[0][1]=='X' && board[2][0]=='X')
        {
            place=rand()%3;
            switch(place)
            {
            case 0:
                board[0][0]='O';
                return(1);
            case 1:
                board[1][1]='O';
                return(1);
            case 2:
                board[0][2]='O';
                return(1);
            }
        }
        else if(board[2][1]=='O' && board[0][0]=='X' && board[1][2]=='X')
        {
            place=rand()%3;
            switch(place)
            {
            case 0:
                board[0][2]='O';
                return(1);
            case 1:
                board[1][1]='O';
                return(1);
            case 2:
                board[2][2]='O';
                return(1);
            }
        }
        else if(board[2][1]=='O' && board[1][0]=='X' && board[0][2]=='X')
        {
            place=rand()%3;
            switch(place)
            {
            case 0:
                board[0][0]='O';
                return(1);
            case 1:
                board[1][1]='O';
                return(1);
            case 2:
                board[2][0]='O';
                return(1);
            }
        }
        else if(board[1][2]=='O' && board[0][1]=='X' && board[2][0]=='X')
        {
            place=rand()%3;
            switch(place)
            {
            case 0:
                board[0][0]='O';
                return(1);
            case 1:
                board[1][1]='O';
                return(1);
            case 2:
                board[0][2]='O';
                return(1);
            }
        }
        else if(board[1][2]=='O' && board[0][0]=='X' && board[2][1]=='X')
        {
            place=rand()%3;
            switch(place)
            {
            case 0:
                board[2][0]='O';
                return(1);
            case 1:
                board[1][1]='O';
                return(1);
            case 2:
                board[2][2]='O';
                return(1);
            }
        }



        ///POSIT 10:
        if(board[0][1]=='O' && board[2][1]=='X' && board[1][2]=='X')
        {
            board[2][2]='O';
            return(1);
        }
        else if(board[0][1]=='O' && board[2][1]=='X' && board[1][0]=='X')
        {
            board[2][0]='O';
            return(1);
        }
        else if(board[1][0]=='O' && board[1][2]=='X' && board[2][1]=='X')
        {
            board[2][2]='O';
            return(1);
        }
        else if(board[1][0]=='O' && board[1][2]=='X' && board[0][1]=='X')
        {
            board[0][2]='O';
            return(1);
        }
        else if(board[2][1]=='O' && board[0][1]=='X' && board[1][2]=='X')
        {
            board[0][2]='O';
            return(1);
        }
        else if(board[2][1]=='O' && board[0][1]=='X' && board[1][0]=='X')
        {
            board[0][0]='O';
            return(1);
        }
        else if(board[1][2]=='O' && board[1][0]=='X' && board[2][1]=='X')
        {
            board[2][0]='O';
            return(1);
        }
        else if(board[1][2]=='O' && board[1][0]=='X' && board[0][1]=='X')
        {
            board[0][0]='O';
            return(1);
        }
    }


    ///POSIT 11:
    if(turn==4 && ((board[0][1]=='O' && board[1][1]=='X' && board[2][1]=='X') || (board[2][1]=='O' && board[1][1]=='X' && board[0][1]=='X') || (board[1][0]=='O' && board[1][1]=='X' && board[1][2]=='X') || (board[1][2]=='O' && board[1][1]=='X' && board[1][0]=='X')))
    {
        place=rand()%4;
        switch(place)
        {
        case 0:
            board[0][2]='O';
            return(1);
        case 1:
            board[2][2]='O';
            return(1);
        case 2:
            board[0][0]='O';
            return(1);
        case 3:
            board[2][0]='O';
            return(1);
        }
    }
    if(turn==6)
    {
        if((board[1][2]=='O' && board[1][1]=='X' && board[1][0]=='X') && (board[0][1]=='X' || board[2][1]=='X'))
        {
            if(rand()%2)
            {
                board[0][0]='O';
                return(1);
            }
            else
            {
                board[2][0]='O';
                return(1);
            }
        }
        else if((board[2][1]=='O' && board[1][1]=='X' && board[0][1]=='X') && (board[1][2]=='X' || board[1][0]=='X'))
        {
            if(rand()%2)
            {
                board[0][0]='O';
                return(1);
            }
            else
            {
                board[0][2]='O';
                return(1);
            }
        }
        else if((board[1][0]=='O' && board[1][1]=='X' && board[1][2]=='X') && (board[0][1]=='X' || board[2][1]=='X'))
        {
            if(rand()%2)
            {
                board[0][2]='O';
                return(1);
            }
            else
            {
                board[2][2]='O';
                return(1);
            }
        }
        else if((board[0][1]=='O' && board[1][1]=='X' && board[2][1]=='X') && (board[1][2]=='X' || board[1][0]=='X'))
        {
            if(rand()%2)
            {
                board[2][0]='O';
                return(1);
            }
            else
            {
                board[2][2]='O';
                return(1);
            }
        }
        else
            return(0);
    }


}


