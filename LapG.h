#ifndef LapG_h
#define LapG_h

class LG
{
    private:
        double x;
        double y;
        double z;

    public:
        LG() {}

        void SetCoords(double x_, double y_, double z_)
        {
            x = x_;
            y = y_;
            z = z_;
        }

        virtual double lapG (double t){return 0.0;}
};

class lapG21: public LG
{
    private:
        double x;
        double y;
        double z;

    public:
        lapG21() {}

        void SetCoords(double x_, double y_, double z_)
        {
            x = x_;
            y = y_;
            z = z_;
        }

        double Getx() {return x;}

        double lapG (double t);
};

class lapG22: public LG
{
    private:
        double x;
        double y;
        double z;

    public:
        lapG22() {}

        void SetCoords(double x_, double y_, double z_)
        {
            x = x_;
            y = y_;
            z = z_;
        }

        double lapG(double t);
};

class lapG32: public LG
{
    private:
        double x;
        double y;
        double z;

    public:
        lapG32() {}

        void SetCoords(double x_, double y_, double z_)
        {
            x = x_;
            y = y_;
            z = z_;
        }

        double lapG(double t);
};

#endif // LAPG_H_INCLUDED

