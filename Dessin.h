#ifndef DESSIN_H
#define DESSIN_H
#include <complex>

struct cadre {
    double x_min;
    double x_max;
    double y_min;
    double y_max;
} typedef CADRE;

class Dessin {
    protected: 
        CADRE cadre;
        complex<double> z;
        complex<double> c;
        double module z_max;
    public:

};

#endif