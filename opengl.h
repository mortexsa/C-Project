#ifndef FENETRE_H
#define FENETRE_H

#include "glWidget.h"

class Fenetre : public GLWidget,public dessin 
{
    Q_OBJECT
public:
    explicit myWindow(QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
};

#endif
