#include "Dessin.hh"

using namespace std;

Dessin::Dessin() : z_max(0){
    
    cadre.x_min = 0.0;
    cadre.x_max = 0.0;
    cadre.y_min = 0.0;
    cadre.y_max = 0.0;
}

Dessin::Dessin(const double x_min, const double x_max, const double y_min, const double y_max, const double z_max,double granularite){
    this->z_max = z_max;
    cadre.x_min = x_min;
    cadre.x_max = x_max;
    cadre.y_min = y_min;
    cadre.y_max = y_max;
    this->granularite=granularite;
}

Dessin::~Dessin(){}

void Dessin::setCadre(const double x_min, const double x_max, const double y_min, const double y_max){
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

double Dessin::getGranularite(){
	return granularite;
}

void Dessin::setModMax(const double z_max){
    this->z_max = z_max;
}

double Dessin::getModMax(){
    return z_max;
}
Point Dessin::algoMandelbrot(const double x, const double y, const double z_max, const int n_max){
    int i = 0;
    Point p;
    complex<double> z(0.0,0.0);
    complex<double> c(x*this->getGranularite()+this->getCadreXmin(),y*this->getGranularite()+this->getCadreYmin());
    do {
        z = (z*z) + c;
        i = i + 1;
    }while(abs(z)<z_max && i<n_max);
    if(abs(z)<=2){
        p = Point(x,y,abs(z)/2.0,abs(z)/2.0,i/100.0);
    }
    else{
        p = Point(x,y,i/100.0,i/100.0,i/100.0);
    }    
    return p;
}
Point Dessin::algoJuliaFatou(const double x,const double y,const double z_max,const int n_max,const complex<double> c){
    int i = 0;
    Point p;
    complex<double> z(x*this->getGranularite()+this->getCadreXmin(),y*this->getGranularite()+this->getCadreYmin());
    do {
        z = (z*z) + c;
        i = i + 1;
    }while(abs(z)<z_max && i<n_max);
     if(abs(z)<=2){
        p = Point(x,y,abs(z)/2.0,abs(z)/2.0,i/100.0);
    }
    else{
        p = Point(x,y,i/100.0,i/100.0,i/100.0);
    }    
    return p;
}
