#ifndef GEOLIB_H_INCLUDED
#define GEOLIB_H_INCLUDED

struct equation;
struct coordinate;
struct vertex;

double find_angle(struct equation, struct equation);
double find_distance(struct coordinate, struct coordinate);
double find_area(struct vertex*);

void get_equation(struct equation*);
int check_consist(struct equation, struct equation);
void get_coordinate(struct coordinate*);
void get_vertex(struct vertex*);
void print_equation(struct equation*);

#endif // GEOLIB_H_INCLUDED
