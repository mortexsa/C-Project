#include "opengl.h"
#include <GL/glut.h>


Opengl::Opengl(QWidget *parent,const double x_min, const double x_max, const double y_min, const double y_max, const double z_max,double granularite)
	   : GLWidget(1, parent, "fractal"), Dessin(x_min, x_max, y_min, y_max,  z_max, granularite){};
   
void Opengl::addPoint(double x, double y, double r, double g, double b){
    glBegin(GL_POINTS);
    glColor3d(r,g,b);
    glVertex2d(x,y);
    glEnd();
}

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
	
    std::complex<double> c(-0.0519,0.688);
    dessiner_J(c);
    //dessiner_M();
}

void Opengl::dessiner_M()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    int x;
	int y;
	int imagex=(this->getCadreXmax()-this->getCadreXmin())/this->getGranularite();
	int imagey=(this->getCadreYmax()-this->getCadreYmin())/this->getGranularite();	
	for(x=0; x<imagex; x+=1){
		for(y=0; y<imagey; y+=1){
			Point p = this->algoMandelbrot(x,y,this->getModMax(),100);
            addPoint((p.getPx()-imagex/2.0)/(imagex/2.0),(p.getPy()-imagey/2.0)/(imagey/2.0),p.getr(),p.getg(),p.getb());
		}		
	}
};

void Opengl::dessiner_J(std::complex<double> c)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    int x;
	int y;
	int imagex=(this->getCadreXmax()-this->getCadreXmin())/this->getGranularite();
	int imagey=(this->getCadreYmax()-this->getCadreYmin())/this->getGranularite();	
	for(x=0; x<imagex; x+=1){
		for(y=0; y<imagey; y+=1){
			Point p=this->algoJuliaFatou(x,y,this->getModMax(),100,c);
            addPoint((p.getPx()-imagex/2.0)/(imagex/2.0),(p.getPy()-imagey/2.0)/(imagey/2.0),p.getr(),p.getg(),p.getb());
		}		
	}
};

void Opengl::ouvrirDialogue(){
	bool ok=false;
	this->cadre.x_min=QInputDialog::getDouble(this,"param","cadre xmin",0,-5,5,4, &ok);
	this->cadre.x_max=QInputDialog::getDouble(this,"param","cadre xmax",0,-5,5,4, &ok);
	this->cadre.y_min=QInputDialog::getDouble(this,"param","cadre ymin",0,-5,5,4, &ok);
	this->cadre.y_max=QInputDialog::getDouble(this,"param","cadre ymax",0,-5,5,4, &ok);
	this->z_max=QInputDialog::getDouble(this,"param","cadre zmax",0,-5,5,4, &ok);
	this->granularite=QInputDialog::getDouble(this,"param","granularite",0.01,0.01,0.1,4, &ok);
	
	
};



