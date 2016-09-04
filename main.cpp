#include "Field.h"
#include "TransformedField.h"
#include "TransformedField.cpp"
#include "LapG.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    TField V(1,0,0.5,6.28,6.28);

    cout << V.GetUy(0.1,0.1,0) << endl;

    int n = 20.0;
    double ds = 2.0 / n;

    ofstream VelocityOut;
    VelocityOut.open("VelocityField.csv",std::ios::app);

    VelocityOut << "x" << "," << "y" << "," << "z" << "," << "Vx" << ","
                << "Vy" << "," << "Vz";
    VelocityOut << endl;

    for(int i=-10; i<=10; i++)
    {
        for(int j=-10; j<=10; j++)
        {
            for(int k=-10; k<=10; k++)
            {
                VelocityOut << i * ds << "," << j * ds << "," << k * ds << ","
                            << V.GetUx(i * ds, j * ds, k * ds) << ","
                            << V.GetUy(i * ds, j * ds, k * ds) << ","
                            << V.GetUz(i * ds, j * ds, k * ds);
                VelocityOut << endl;
                cout << i << ", " << j << "," << k << endl;
            }
        }
    }

    return 0;
}
