#ifndef OPENGL_H
#define OPENGL_H

#include <glWidget.h>
#include "Dessin.hh"
#include <complex>

class Opengl : public GLWidget, public Dessin  
{
    Q_OBJECT
public:
    explicit Opengl(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void dessiner_J(std::complex<double> c);
    void dessiner_M();
};

#endif
