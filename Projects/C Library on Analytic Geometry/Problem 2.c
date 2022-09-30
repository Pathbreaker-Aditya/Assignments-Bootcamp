#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include"geolib.h"
#include"geolib.c"


int main()
{
    struct coordinate cord1, cord2;
    char lat,lon;
    printf("\n  The program will calculate the distance between two locations, coordinates of which will be given by the user.");

    printf("\n\n  Enter the coordinates of the First Location : ");
    get_coordinate(&cord1);

    lat = cord1.latitude > 0 ? 'N' : 'S';
    lon = cord1.longitude > 0 ? 'E' : 'W';
    printf("\n  The coordinates of the first location are : (%lf %c, %lf %c)",cord1.latitude, lat, cord1.longitude, lon);

    printf("\n\n  Enter the coordinates of the Second Location : ");
    get_coordinate(&cord2);

    lat = cord2.latitude > 0 ? 'N' : 'S';
    lon = cord2.longitude > 0 ? 'E' : 'W';
    printf("\n  The coordinates of the second location are : (%lf %c, %lf %c)",cord2.latitude, lat, cord2.longitude, lon);

    printf("\n\n  Press any key to calculate the distance....");
    getch();

    printf("\n\n  The Distance between the two locations is : %lf units  \n\n  ", find_distance(cord1, cord2));
    return(0);
}
