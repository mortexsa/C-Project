#ifndef OPENGL_H
#define OPENGL_H

#include <glWidget.h>
#include "Dessin.hh"
#include <complex>

class Opengl : public GLWidget, public Dessin 
{
    Q_OBJECT
    
public:
    Opengl(QWidget *parent,const double x_min, const double x_max, const double y_min, const double y_max, const double z_max,double granularite);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void dessiner_J(std::complex<double> c);
    void dessiner_M();
};

#endif
