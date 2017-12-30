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
    double granularite;
    
public:
    Dessin();
    Dessin(const double x_min, const double x_max, const double y_min, const double y_max, const double z_max,double granularite);
    ~Dessin();
    void setCadre(const double x_min, const double x_max, const double y_min, const double y_max);
    double getCadreXmin();
    double getCadreXmax();
    double getCadreYmin();
    double getCadreYmax();
    double getGranularite();
    
    void setModMax(const double z_max);
    double getModMax();
    int algoMandelbrot(const double x, const double y, const double z_max, const int n_max);
    int algoJuliaFatou(const double x,const double y,const double z_max,const int n_max,const std::complex<double> c);
    virtual void dessiner_M(double x, double y, int i)=0;
     virtual void dessiner_J(double x, double y, int i)=0;
};

#endif
