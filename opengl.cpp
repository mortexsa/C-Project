#include "opengl.h"
#include <GL/glut.h>


Opengl::Opengl(QWidget *parent,const double x_min, const double x_max, const double y_min, const double y_max, const double z_max,double granularite)
	   : GLWidget(1, parent, "fractal"), Dessin(x_min, x_max, y_min, y_max,  z_max, granularite){
		QLabel *xminLabel= new QLabel("xmin xmax ymin ymax zmax granularite",this);
		xminLabel->move(0,0);
		this->xmin= new QDoubleSpinBox(this);
		this->xmin->setRange(-10, 10);
		this->xmin->setSingleStep(0.1);
        this->xmin->setValue(-2);
        this->xmin->move(0,17);
        
      
		this->xmax= new QDoubleSpinBox(this);
		this->xmax->setRange(-10, 10);
		this->xmax->setSingleStep(0.1);
        this->xmax->setValue(2);
        this->xmax->move(72,17);
        
     
		this->ymin= new QDoubleSpinBox(this);
		this->ymin->setRange(-10, 10);
		this->ymin->setSingleStep(0.1);
        this->ymin->setValue(-2);
        this->ymin->move(144,17);
        
   
		this->ymax= new QDoubleSpinBox(this);
		this->ymax->setRange(-10, 10);
		this->ymax->setSingleStep(0.1);
        this->ymax->setValue(2);
        this->ymax->move(216,17);
           
           
           
    
		this->zmax= new QDoubleSpinBox(this);
		this->zmax->setRange(-10, 10);
		this->zmax->setSingleStep(0.1);
        this->zmax->setValue(2);
        this->zmax->move(288,17);
     
		this->granularite2= new QDoubleSpinBox(this);
		this->granularite2->setRange(0.001, 10);
		this->granularite2->setDecimals(3);
		this->granularite2->setSingleStep(0.001);
        this->granularite2->setValue(0.001);
        this->granularite2->move(360,17);   
           
         QObject::connect(this->xmin, SIGNAL(valueChanged(double)),this, SLOT(changerXmin(double)));
         QObject::connect(this->xmax, SIGNAL(valueChanged(double)),this, SLOT(changerXmax(double)));
         QObject::connect(this->ymin, SIGNAL(valueChanged(double)),this, SLOT(changerYmin(double)));
         QObject::connect(this->ymax, SIGNAL(valueChanged(double)),this, SLOT(changerYmax(double)));
         QObject::connect(this->zmax, SIGNAL(valueChanged(double)),this, SLOT(changerZmax(double)));
         QObject::connect(this->granularite2, SIGNAL(valueChanged(double)),this, SLOT(changerGran(double)));
		  
		   	//~ bool ok=false;
	
	//~ this->xmin=QInputDialog::getDouble(this,"param","cadre xmin",0,-5,5,4, &ok);
	//~ this->xmax=QInputDialog::getDouble(this,"param","cadre xmax",0,-5,5,4, &ok);
	//~ this->ymin=QInputDialog::getDouble(this,"param","cadre ymin",0,-5,5,4, &ok);
	//~ this->ymax=QInputDialog::getDouble(this,"param","cadre ymax",0,-5,5,4, &ok);
	//~ this->zmax=QInputDialog::getDouble(this,"param","cadre zmax",0,-5,5,4, &ok);
	//~ this->granularite2=QInputDialog::getDouble(this,"param","granularite",0.01,0.01,0.1,4, &ok);
		   };
   
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
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //~ gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
    //glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



void Opengl::paintGL()
{
	
    std::complex<double> c(-0.0519,0.688);
    //dessiner_J(c);
    dessiner_M();
	this->resizeGL((this->getCadreXmax()-this->getCadreXmin())/this->getGranularite(),(this->getCadreYmax()-this->getCadreYmin())/this->getGranularite());
	this->setFixedSize((this->getCadreXmax()-this->getCadreXmin())/this->getGranularite()+400,(this->getCadreYmax()-this->getCadreYmin())/this->getGranularite()+100);
	
	
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

//~ void Opengl::ouvrirDialogue(){
	//~ bool ok=false;
	//~ this->cadre.x_min=QInputDialog::getDouble(this,"param","cadre xmin",0,-5,5,4, &ok);
	//~ this->cadre.x_max=QInputDialog::getDouble(this,"param","cadre xmax",0,-5,5,4, &ok);
	//~ this->cadre.y_min=QInputDialog::getDouble(this,"param","cadre ymin",0,-5,5,4, &ok);
	//~ this->cadre.y_max=QInputDialog::getDouble(this,"param","cadre ymax",0,-5,5,4, &ok);
	//~ this->z_max=QInputDialog::getDouble(this,"param","cadre zmax",0,-5,5,4, &ok);
	//~ this->granularite=QInputDialog::getDouble(this,"param","granularite",0.01,0.01,0.1,4, &ok);
	
	
//~ };


void Opengl::changerXmin(double n){
	this->cadre.x_min=n;
	this->updateGL();
	};
	
void Opengl::changerXmax(double n){
	this->cadre.x_max=n;
	this->updateGL();
	};
	
void Opengl::changerYmin(double n){
	this->cadre.y_min=n;
	this->updateGL();
	};

void Opengl::changerYmax(double n){
	this->cadre.y_max=n;
	this->updateGL();
	};

void Opengl::changerZmax(double n){
	this->z_max=n;
	this->updateGL();
	};

void Opengl::changerGran(double n){
	this->granularite=n;
	this->updateGL();
	};


