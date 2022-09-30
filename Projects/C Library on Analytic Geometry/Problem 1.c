
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include "geolib.h"
#include "geolib.c"

int main()
{
    double  angle_at_chowk;
    struct equation eq1, eq2;
    int check;

    printf("\n  The program will find the angle of intersection of two streets in degrees,\n  the equations for which will be taken from the user");

    printf("\n\n  Enter the following for the equation of first street : ");
    get_equation(&eq1);

    printf("\n\n  Enter the following for the equation of second street : ");
    get_equation(&eq2);

    printf("\n  Press any key to find angle of intersection...\n\n  ");
    getch();

    if( check_consist(eq1,eq2) )
    {
        angle_at_chowk = find_angle(eq1,eq2);
        printf("\n  The angle of intersection of the two streets at chowk123 is %lf degrees .",angle_at_chowk);
    }

    printf("\n\n  Press any key to exit program...");
    getch();
    return(0);
}

