#include "LapG.h"
#include <cmath>

using namespace std;

double lapG21::lapG(double t)
{
    double r = pow((x-t)*(x-t) + y*y + z*z, 0.5);

    return ((-6)*(x-t)*y*t) / pow(r, 5);
}

double lapG22::lapG(double t)
{
    double r = pow((x-t)*(x-t) + y*y + z*z, 0.5);

    return (2.0*t / pow(r, 3)) - ((6.0*y*y*t) / pow(r, 5));
}

double lapG32::lapG(double t)
{
    double r = pow((x-t)*(x-t) + y*y + z*z, 0.5);

    return - (6*z*y*t) / pow(r, 5);
}
