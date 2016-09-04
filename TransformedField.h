#ifndef TransformedField_h
#define TransformedField_h
#include "Field.h"
#include <cmath>

class TField
{
    private:
        double Fperp; // force magnitude
        double Fpar;
        double x1; // force location
        double theta; // angle of rotation in xy plane
        double phi; // angle of rotation in xz plane

        double Getu(double x, double y, double z)
        {
            return cos(theta) * cos(phi) * x + sin(theta) * y + cos(theta) * sin(phi) * z;
        }

        double Getv(double x, double y, double z)
        {
            return -sin(theta) * cos(phi) * x + cos(theta) * y - sin(theta) * sin(phi) * z;
        }

        double Getw(double x, double y, double z)
        {
            return -sin(phi) * x + cos(phi) * z;
        }

        double Getx(double u, double v, double w)
        {
            return cos(theta) * cos(phi) * u - sin(theta) * v - cos(theta) * sin(phi) * w;
        }

        double Gety(double u, double v, double w)
        {
            return sin(theta) * cos(phi) * u + cos(theta) * v - sin(theta) * sin(phi) * w;
        }

        double Getz(double u, double v, double w)
        {
            return sin(phi) * u + cos(phi) * w;
        }

    public:
        TField(double Fperp_, double Fpar_, double x1_, double theta_, double phi_):Fperp(Fperp_),Fpar(Fpar_),x1(x1_),theta(theta_),phi(phi_)
        {

        }

        double GetUx(double x, double y, double z);

        double GetUy(double x, double y, double z);

        double GetUz(double x, double y, double z);
};

#endif // TRANSFORMEDFIELD_H_INCLUDED
