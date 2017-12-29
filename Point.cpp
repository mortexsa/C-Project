#include "Point.hh"

Point::Point() : x(0),y(0){
    couleur.r = 1.0;
    couleur.g = 1.0;
    couleur.b = 1.0;
} 

Point::Point(const double x,const double y, const double r, const double g, const double b){
    this->x = x;
    this->y = y;
    couleur.r = r;
    couleur.g = g;
    couleur.b = b;
} 

Point::~Point(){}

double Point::getPx() const{
    return x;
}
double Point::getPy() const{
    return y;
}
double Point::getr() const{
    return couleur.r;
}
double Point::getg() const{
    return couleur.g;
}
double Point::getb() const{
    return couleur.b;
}
void Point::setP(const double x, const double y){
    this->x = x;
    this->y = y;
}
void Point::setColor(const double r, const double g, const double b){
    couleur.r = r;
    couleur.g = g;
    couleur.b = b;
}