#include "Field.h".
#include "LapG.h"
#include<iostream>
#include<cmath>
using namespace std;

double VelocityField::GetVx(double x, double y, double z)
{
    double vxperp;
    double vxpar;

    vxperp = G21(x - x1, y, z) - (1.0 / x1) * G21(x - (1.0 / x1), y, z);

    lapG21 A;

    A.SetCoords(x,y,z);

    double sum;
    double h = 0.1;
    int N = 10000;

    sum = A.lapG((1.0 / x1));

    for (int i=1; i <= N; i++)
    {
        sum = sum + 2*A.lapG((1.0/ x1) + h*i);
    }

    sum = sum + A.lapG(h*N + (1.0 / x1));

    vxperp = vxperp - 2.0 * ((1.0 - pow(x1,2)) / (1.0 / x1)) * sum * h * 0.5;

    // Calculate Parallel force.
    vxpar = G11(x - x1, y, z) - (1.0 / x1) * G11(x - (1.0 / x1), y, z);

    // Vx is linear combination of each force direction.
    return (Fpar * vxpar) + (Fperp * vxperp);
}

double VelocityField::GetVy(double x, double y, double z)
{
    double vyperp;
    double vypar;

    vyperp = G22(x - x1, y, z) - (1.0 / x1) * G22(x - (1.0 / x1), y, z);

    lapG22 A;

    A.SetCoords(x,y,z);

    // trapezium rule integration to approximate term 3
    double sum;
    double h = 0.1;
    int N = 10000;

    sum = A.lapG((1.0/x1));

    for (int i=1; i <= N; i++)
    {
        sum = sum + 2*A.lapG((1.0/x1) + h*i);
    }

    sum = sum + A.lapG(h*N + (1.0/x1));

    vyperp = vyperp - 2.0 * ((1.0 - pow(x1,2)) / (1.0 / x1)) * sum * h * 0.5;

    // calculate parallel force.
    vypar = G21(x - x1, y, z) - (1.0 / x1) * G21(x - (1.0 / x1), y, z);

    return (Fperp * vyperp) + (Fpar * vypar);
}

double VelocityField::GetVz(double x, double y, double z)
{
    double vzperp;
    double vzpar;

    vzperp = G32(x - x1, y, z) - (1.0 / x1) * G32(x - (1.0 / x1), y, z);

    lapG32 A;

    A.SetCoords(x,y,z);

    double sum;
    double h = 0.1;
    int N = 10000;

    sum = A.lapG((1.0/x1));

    for (int i=1; i <= N; i++)
    {
        sum = sum + 2*A.lapG((1.0/x1) + h*i);
    }

    sum = sum + A.lapG(h*N + (1.0/x1));

    vzperp = vzperp - 2.0 * ((1.0 - pow(x1,2)) / (1.0 / x1)) * sum * h * 0.5;

    // parallel force.
    vzpar = G31(x - x1, y, z) - (1.0 / x1) * G31(x - (1.0 / x1), y, z);

    return (Fperp * vzperp) + (Fpar * vzpar);
}
