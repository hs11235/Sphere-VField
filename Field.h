#ifndef Field_h
#define Field_h
#include<cmath>

class VelocityField
{
    private:
        double Fperp; // force magnitude
        double Fpar;
        double x1; // force location

        double G11(double x, double y, double z)
        {
            double r = pow(x*x + y*y + z*z, 0.5);

            return (1.0 / r) + ((x*x) / pow(r, 3));
        }

        double G31(double x, double y, double z)
        {
            double r = pow(x*x + y*y + z*z, 0.5);

            return (x*z) / pow(r, 3);
        }

        double G22(double x, double y, double z)
        {
            double r = pow(x*x + y*y + z*z, 0.5);

            return (1.0 / r) + ((y*y) / pow(r, 3));
        }

        double G21(double x, double y, double z)
        {
            double r = pow(x*x + y*y + z*z, 0.5);

            return (x*y) / pow(r, 3);
        }

        double G32(double x, double y, double z)
        {
            double r = pow(x*x + y*y + z*z, 0.5);

            return (y*z) / pow(r, 3);
        }

    public:
        // class constructor
        VelocityField(double Fperp_, double Fpar_, double x1_):Fperp(Fperp_),Fpar(Fpar_),x1(x1_)
        {

        }

        double GetVx(double x, double y, double z);

        double GetVy(double x, double y, double z);

        double GetVz(double x, double y, double z);
};

#endif
