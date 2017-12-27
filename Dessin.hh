#ifndef DESSIN_HH
#define DESSIN_HH
#include <complex>

#define HAUTEUR 600
#define LARGEUR 600

struct cadre {
    double x_min;
    double x_max;
    double y_min;
    double y_max;
} typedef CADRE;

struct point {
    double x,y;
    double rouge,vert,bleu;
} typedef POINT;

class Dessin {
    protected: 
        CADRE cadre;
        complex<double> z;
        complex<double> c;
        double module z_max;
    public:
        void setCadre(double x_min, double x_max, double y_min, double x_max);
        POINT mondelbrot(double x, double y);
};

#endif