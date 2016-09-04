#include "Field.h"
#include "Field.cpp"
#include "LapG.h"
#include "LapG.cpp"
#include "TransformedField.h"
#include<iostream>
#include<cmath>
using namespace std;

double TField::GetUx(double x, double y, double z)
{
    double u = Getu(x,y,z);
    double v = Getv(x,y,z);
    double w = Getw(x,y,z);

    VelocityField A(Fperp, Fpar, x1);

    double vu = A.GetVx(u,v,w);
    double vv = A.GetVy(u,v,w);
    double vw = A.GetVz(u,v,w);

    return Getx(vu,vv,vw);
}

double TField::GetUy(double x, double y, double z)
{
    double u = Getu(x,y,z);
    double v = Getv(x,y,z);
    double w = Getw(x,y,z);

    VelocityField A(Fperp, Fpar, x1);

    double vu = A.GetVx(u,v,w);
    double vv = A.GetVy(u,v,w);
    double vw = A.GetVz(u,v,w);

    return Gety(vu,vv,vw);
}

double TField::GetUz(double x, double y, double z)
{
    double u = Getu(x,y,z);
    double v = Getv(x,y,z);
    double w = Getw(x,y,z);

    VelocityField A(Fperp, Fpar, x1);

    double vu = A.GetVx(u,v,w);
    double vv = A.GetVy(u,v,w);
    double vw = A.GetVz(u,v,w);

    return Getz(vu,vv,vw);
}
