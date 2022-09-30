

struct equation
{
    double coeff_x;
    double coeff_y;
    double constant;
};

struct coordinate
{
    double latitude;
    double longitude;
};

struct vertex
{
    double x;
    double y;
};

int check_consist(struct equation eq1, struct equation eq2) // checks the solution consistency of the system of equation.
{
    double ratio_a, ratio_b, ratio_c; // these are ratios of coefficients of x,y and constant in the two equations.

    ratio_a = eq1.coeff_x / eq2.coeff_x;
    ratio_b = eq1.coeff_y / eq2.coeff_y;
    ratio_c = eq1.constant / eq2.constant;

    if(ratio_a != ratio_b)
    {
        return(1);
    }
    else if(ratio_a == ratio_b)
    {
        if(ratio_b == ratio_c)
        {
            printf("\n  The two equations correspond to the same street, thus there can be no angle of intersection");
            return(0);
        }
        else if(ratio_b != ratio_c)
        {
            printf("\n  The two streets are parallel, thus there is no angle of intersection.");
            return(0);
        }
    }
}

void get_equation(struct equation *eqn)
{
    printf("\n\n  Coefficient of x : ");
    scanf("%lf",&eqn->coeff_x);

    printf("  Coefficient of y : ");
    scanf("%lf",&eqn->coeff_y);

    printf("  Constant term : ");
    scanf("%lf",&eqn->constant);
}

double find_angle(struct equation eq1, struct equation eq2)
{
    double tanAng, angle;
    double m1, m2; /// m1 and m2 are slopes of equations 1 and respectively.

    m1 = (-1 * eq1.coeff_x) / eq1.coeff_y;
    m2 = (-1 * eq2.coeff_x) / eq2.coeff_y;

    tanAng = (m2-m1) / (1 + m1*m2);

    if(tanAng<0)
        tanAng = -(tanAng);

    angle = atan(tanAng) * 180.0 / 3.14;
    return(angle);
}

void get_coordinate(struct coordinate *coord)
{
    printf("\n  Enter Latitude value : ");
    scanf("%lf",&coord->latitude);
    while(coord->latitude > 90.0 || coord->latitude < -90.0)
    {
        printf("\n  Latitude out of bound error ! : Latitude coordinates have to be between 90 degrees and -90 degrees.\n");
        printf("\n  Enter Latitude value again : ");
        fflush(stdin);
        scanf("%lf",&coord->latitude);
    }

    printf("  Enter Longitude value : ");
    scanf("%lf",&coord->longitude);
    while(coord->longitude > 90.0 || coord->longitude < -90.0)
    {
        printf("\n  Longitude out of bound error ! : Longitude coordinates have to be between 180 degrees and -180 degrees.\n");
        printf("\n  Enter Longitude value again : ");
        fflush(stdin);
        scanf("%lf",&coord->latitude);
    }
}

void get_vertex(struct vertex *vtx)
{
    printf("\n  x : ");
    scanf("%lf",&vtx->x);
    printf("  y : ");
    scanf("%lf",&vtx->y);
}

double find_distance(struct coordinate c1, struct coordinate c2)
{
    double distance;
    double temp;

    temp = pow((c1.latitude - c2.latitude),2.0) + pow((c1.longitude - c2.longitude),2.0); // making use of the (x2 - x1)^2 + (y2 - y1)^2 formula for distance b/w two points
    distance = sqrt(temp);

    return(distance);
}

double find_area(struct vertex *vtx)
{
    int i,j;
    double temp = 0.0, area;
    for(i = 0, j = 0 ; j < 3 ; i++)
    {
        // using the general formula for calculating the area of any polygon coordinates of whose vertices are given.
        if(i < 3)
            temp = temp + vtx[i].x * vtx[i + 1].y;
        else
        {
            temp = temp - vtx[j].y * vtx[j + 1].x;
            j++;
        }
    }

    area = temp / 2.0;

    return( fabs(area) ); // return only the positive value of area via fabs() function of math.h.
}
