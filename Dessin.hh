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
    Dessin(double x_min,double x_max, double y_min, double y_max, double z_max);
    ~Dessin();
    void setCadre(double x_min,double x_max, double y_min, double y_max);
    double getCadreXmin();
    double getCadreXmax();
    double getCadreYmin();
    double getCadreYmax();
    Point getPoint();
    void setModMax(double z_max);
    double getModMax();
    Point algoMandelbrot(double x, double y, double z_max, int n_max);
    //virtual void dessiner(double height, double width)=0;
};

#endif
