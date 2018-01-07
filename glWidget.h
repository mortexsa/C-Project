#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QtOpenGL>
#include <QGLWidget>
#include "Dessin.hh"
/*!
 *  \file glWidget.h
 * \brief class de widget Qt 
 */
 
 //! \class GLWidget 
/*! \brief class permettant l'integration d'opengl dans une interface Qt
cette classe dont la class Opengl herite permet de dessiner avec openGl dans un widget Qt
*/ 
class GLWidget : public QGLWidget
{
    Q_OBJECT	; /*< objet qt*/
public:
	//! \brief constructeur de GLWidget
    explicit GLWidget(int framesPerSecond = 0, QWidget *parent = 0, char *name = 0);
    
    //! \brief fonction d'iniatlisation 
    virtual void initializeGL() = 0;
    
    //! \brief fonction de redimensionnage 
    virtual void resizeGL(int width, int height) = 0;
    
    //! \brief fonction de dessin
    virtual void paintGL() = 0;
   
        
public slots:
	//! \brief fonction necessaire à l'integration d'opengl dans qt
    virtual void timeOutSlot();

private:
	//! \brief attribut necessaire à l'integration d'opengl dans qt
    QTimer *t_Timer;

};


#endif 
