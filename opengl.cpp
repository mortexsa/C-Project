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
    int x;
	int y;
	int imagex=(this->getCadreXmax()-this->getCadreXmin())/this->getGranularite();
	int imagey=(this->getCadreYmax()-this->getCadreYmin())/this->getGranularite();	
	for(x=0; x<imagex; x+=1){
		for(y=0; y<imagey; y+=1){
			int i=this->algoMandelbrot(x,y,this->getModMax(),100);
            glBegin(GL_POINTS);
            glColor3f(0.0f,0.0f,i/100.0);
            glVertex2f((x-imagex/2.0)/(imagex/2.0),(y-imagey/2.0)/(imagey/2.0));
            glEnd();
		}		
	}
}

void Opengl::dessiner_M()
{
	
};

void Opengl::dessiner_J(std::complex<double> c)
{
	
};





