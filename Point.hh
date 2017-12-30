#ifndef POINT_HH
#define POINT_HH

struct color {
    double r,g,b;
}typedef COLOR;

class Point {
private:
    double x;
    double y;
    COLOR couleur;
public:
    friend class Dessin;
    Point(); 
    Point(const double x,const double y, const double r, const double g, const double b); 
    ~Point(); 
    double getPx() const;
    double getPy() const;
    double getr() const;
    double getg() const;
    double getb() const;
    Point& operator=(const Point& p);
};


#endif