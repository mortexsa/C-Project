#ifndef DESSIN_HH
#define DESSIN_HH
#include <complex>
#include "Point.hh"

#define HAUTEUR 600
#define LARGEUR 600

struct cadre {
    double x_min;
    double x_max;
    double y_min;
    double y_max;
} typedef CADRE;

class Dessin {
protected: 
    CADRE cadre;
    double z_max;
    Point p;
public:
    Dessin();
    ~Dessin();
    void setCadre(double x_min,double x_max, double y_min, double y_max);
    CADRE getCadre();
    void setModMax(double z_max);
    double getModMax();
};

#endif
