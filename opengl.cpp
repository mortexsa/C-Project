#include "opengl.h"
#include <GL/glut.h>


Opengl::Opengl(QWidget *parent,const double x_min, const double x_max, const double y_min, const double y_max, const double z_max,double granularite)
	   : GLWidget(1, parent, "fractal"), Dessin(x_min, x_max, y_min, y_max,  z_max, granularite){};
   

void Opengl::initializeGL()
{
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Opengl::resizeGL(int width, int height)
{
    if(height == 0)
        height = 1;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //~ gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



void Opengl::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    //code de dessin 	
    double x,y;
    std::cout<<"mandelbrot i:"<<algoMandelbrot(0.0,0.0,this->getModMax(),100)<<std::endl;
	for(x=this->getCadreXmin(); x<this->getCadreXmax(); x+=this->getGranularite()){
		for(y=this->getCadreYmin(); y<this->getCadreYmax(); y+=this->getGranularite()){
			int i=this->algoMandelbrot(x,y,this->getModMax(),100);
            //std::cout<<"[x:"<<x<<";y:"<<y<<"]"<<std::endl;
            glBegin(GL_POINTS);
            glColor3d(0.5,0.5,0.5);
            glVertex2d(x,y);
            glEnd();
            glFlush();
		}		
	}

}

void Opengl::dessiner_M()
{
	
};

void Opengl::dessiner_J(std::complex<double> c)
{
	
};





