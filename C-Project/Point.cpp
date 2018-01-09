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
Point& Point::operator=(const Point& p){
    this->x = p.x;
    this->y = p.y;
    couleur.r = p.couleur.r;
    couleur.g = p.couleur.g;
    couleur.b = p.couleur.b;
    return *this;
}
