#include "Dessin.hh"

void setCadre(double x_min, double x_max, double y_min, double x_max) {
    this->cadre.x_min = x_min;
    this->cadre.x_max = x_max;
    this->cadre.y_min = y_min;
    this->cadre.y_max = y_max;
}


POINT Dessin::mondelbrot(double x, double y) {
    int i=0;
    POINT point;
    do {
        this->z = (this->z*this->z) + this->c;
        i = i + 1;
    }while(abs(this->z)<2 && i<50);
    
    if(i == 50) {
               
       point.x = x;
       point.y = y;
    }
    return point;
}