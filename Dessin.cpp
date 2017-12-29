#include "Dessin.hh"
#include "Point.hh"

Dessin::Dessin() : z_max(0){
    p = Point();
    cadre.x_min = 0.0;
    cadre.x_max = 0.0;
    cadre.y_min = 0.0;
    cadre.y_max = 0.0;
}

Dessin::Dessin(double x_min,double x_max, double y_min, double y_max, double z_max){
    this->z_max = z_max;
    cadre.x_min = x_min;
    cadre.x_max = x_max;
    cadre.y_min = y_min;
    cadre.y_max = y_max;
}

Dessin::~Dessin(){}

void Dessin::setCadre(double x_min,double x_max, double y_min, double y_max){
    cadre.x_min = x_min;
    cadre.x_max = x_max;
    cadre.y_min = y_min;
    cadre.y_max = y_max;
}

double Dessin::getCadreXmin(){
    return cadre.x_min;
}
double Dessin::getCadreXmax(){
    return cadre.x_max;
}
double Dessin::getCadreYmin(){
    return cadre.y_min;
}
double Dessin::getCadreYmax(){
    return cadre.y_max;
}

void Dessin::setModMax(double z_max){
    this->z_max = z_max;
}

double Dessin::getModMax(){
    return z_max;
}
