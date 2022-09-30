#include<stdio.h>
#include<conio.h>
#include<math.h>
#include"geolib.h"
#include"geolib.c"



int main()
{
    struct vertex vtx[4]; // three blocks for the three vertices to be taken from the user, 4th one for the ease of logic in find_area() function.
    int i;

    printf("\n  The program will calculate the area of a triangle bound by three vertices,\n  coordinates of which will be taken from the user.\n");
    printf("\n  Press any key to proceed...\n  ");
    getch();

    for(i = 0; i <= 3; i++)
    {
        if(i != 3)
        {
            printf("\n  Enter coordinates of Vertex No. %d : ",i+1);
            get_vertex(&vtx[i]);
        }
        else
        {
            vtx[i].x = vtx[0].x;
            vtx[i].y = vtx[0].y;
        }
    }

    printf("\n  Press any key to calculate the area...");
    getch();

    printf("\n\n  The area of triangle made by the three points \n\n  (%lf,%lf),\n  (%lf,%lf) and \n  (%lf,%lf) == %lf sq. units.\n\n  ",vtx[0].x, vtx[0].y, vtx[1].x, vtx[1].y, vtx[2].x, vtx[2].y, find_area(vtx));
    printf("\n\n  Press any key to exit the program...");
    getch();

    return(0);
}
