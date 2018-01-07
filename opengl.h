#ifndef OPENGL_H
#define OPENGL_H

#include <glWidget.h>
#include "cairo.hh"
#include "Dessin.hh"
#include <complex>
#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

class Opengl : public GLWidget, public Dessin 
{
    Q_OBJECT;
    QDoubleSpinBox *xmin;
    QDoubleSpinBox *xmax;
    QDoubleSpinBox *ymin;
    QDoubleSpinBox *ymax;
    QDoubleSpinBox *zmax;
    QDoubleSpinBox *granularite2;
    
    //~ QDoubleSpinBox *C_r;
    //~ QDoubleSpinBox *C_i;
    //~ QPushButton *J;
    //~ QPushButton *M;
    QPushButton *save;
    QPushButton *ok;
    QPushButton *mandelbrot;
    QPushButton *juliaFatou1;
    QPushButton *juliaFatou2;
    QPushButton *zoom;
    QPushButton *dezoom;
    QPushButton *bas;
    QPushButton *haut;
    QPushButton *droit;
    QPushButton *gauche;

    bool J_M;
    std::complex<double> c;
 private: 
    int selectfractale;
    
    
public:
    Opengl(QWidget *parent,const double x_min, const double x_max, const double y_min, const double y_max, const double z_max,double granularite);
    void addPoint(double x, double y, double r, double g, double b);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void dessiner_J(std::complex<double> c);
    void dessiner_M();
    void Opengl::keyPressEvent(QKeyEvent *keyEvent)
    
    
public slots:
	void changerXmin(double n);
	void changerXmax(double n);
	void changerYmin(double n);
	void changerYmax(double n);
	void changerZmax(double n);
	void changerGran(double n);
	void refresh();
	void enregistrer();
    void mandelbrot1();
    void juliafatou1();
    void juliafatou2();
    void zoomFunc();
    void dezoomFunc();
    void basFunc();
    void hautFunc();
    void droitFunc();
    void gaucheFunc();
};

#endif
