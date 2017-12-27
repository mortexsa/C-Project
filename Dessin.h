#ifndef DESSIN_H
#define DESSIN_H
#include <complex>

struct cadre {
    double x_min;
    double x_max;
    double y_min;
    double y_max;
} typedef CADRE;

struct point {
    double x,y;
    double r,v,b;
} typedef POINT;

class Dessin {
    protected: 
        CADRE cadre;
        complex<double> z;
        complex<double> c;
        double module z_max;
    public:
        POINT mondelbrot(double x, double y);
};

#endif