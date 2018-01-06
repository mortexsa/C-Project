#include "opengl.h"
#include <GL/glut.h>


Opengl::Opengl(QWidget *parent,const double x_min, const double x_max, const double y_min, const double y_max, const double z_max,double granularite)
	   : GLWidget(1, parent, "fractal"), Dessin(x_min, x_max, y_min, y_max,  z_max, granularite){

	this->selectfractale = 1;


	QLabel *xminLabel= new QLabel("   xmin           xmax            ymin          ymax          zmax        Granularite                                            ",this);
	xminLabel->move(0,0);
	this->xmin= new QDoubleSpinBox(this);
	this->xmin->setRange(-10, 10);
	this->xmin->setSingleStep(0.1);
	this->xmin->setValue(x_min);
	this->xmin->move(0,17);
	
	
	this->xmax= new QDoubleSpinBox(this);
	this->xmax->setRange(-10, 10);
	this->xmax->setSingleStep(0.1);
	this->xmax->setValue(x_max);
	this->xmax->move(72,17);
	
	
	this->ymin= new QDoubleSpinBox(this);
	this->ymin->setRange(-10, 10);
	this->ymin->setSingleStep(0.1);
	this->ymin->setValue(y_min);
	this->ymin->move(144,17);
	

	this->ymax= new QDoubleSpinBox(this);
	this->ymax->setRange(-10, 10);
	this->ymax->setSingleStep(0.1);
	this->ymax->setValue(y_max);
	this->ymax->move(216,17);
		
		
		

	this->zmax= new QDoubleSpinBox(this);
	this->zmax->setRange(-10, 10);
	this->zmax->setSingleStep(0.1);
	this->zmax->setValue(z_max);
	this->zmax->move(288,17);
	
	this->granularite2= new QDoubleSpinBox(this);
	this->granularite2->setRange(0.001, 10);
	this->granularite2->setDecimals(3);
	this->granularite2->setSingleStep(0.001);
	this->granularite2->setValue(granularite);
	this->granularite2->move(360,17);   
		
	this->ok= new QPushButton("ok",this);
	this->ok->move(432,17);
	
	this->save= new QPushButton("save",this);
	this->save->move(504,17);
	
	this->mandelbrot= new QPushButton("Mandelbrot",this);
	this->mandelbrot->move(0,44);
	this->juliaFatou1= new QPushButton("Julia[-0.0519;0.688]",this);
	this->juliaFatou1->move(100,44);
	this->juliaFatou2= new QPushButton("Julia[-0.577;0.478]",this);
	this->juliaFatou2->move(252,44);
	
	QObject::connect(this->xmin, SIGNAL(valueChanged(double)),this, SLOT(changerXmin(double)));
	QObject::connect(this->xmax, SIGNAL(valueChanged(double)),this, SLOT(changerXmax(double)));
	QObject::connect(this->ymin, SIGNAL(valueChanged(double)),this, SLOT(changerYmin(double)));
	QObject::connect(this->ymax, SIGNAL(valueChanged(double)),this, SLOT(changerYmax(double)));
	QObject::connect(this->zmax, SIGNAL(valueChanged(double)),this, SLOT(changerZmax(double)));
	QObject::connect(this->granularite2, SIGNAL(valueChanged(double)),this, SLOT(changerGran(double)));
	QObject::connect(this->ok, SIGNAL(clicked()), this, SLOT(refresh()));
	QObject::connect(this->save, SIGNAL(clicked()), this, SLOT(enregistrer()));
	QObject::connect(this->mandelbrot, SIGNAL(clicked()), this, SLOT(mandelbrot1()));
	QObject::connect(this->juliaFatou1, SIGNAL(clicked()), this, SLOT(juliafatou1()));
	QObject::connect(this->juliaFatou2, SIGNAL(clicked()), this, SLOT(juliafatou2()));  
	this->updateGL();

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
	int largeur = (this->getCadreXmax()-this->getCadreXmin())/this->getGranularite();
	int hauteur = (this->getCadreYmax()-this->getCadreYmin())/this->getGranularite();
    if(this->selectfractale == 1){
		dessiner_M();
	}else if(this->selectfractale == 2){
		std::complex<double> c(-0.0519,0.688);
    	dessiner_J(c);
	}else if(this->selectfractale == 3){
		std::complex<double> c(-0.577,0.478);
    	dessiner_J(c);
	}
	
    //
	this->resizeGL(largeur,hauteur);
	
	if(largeur > 600){
		this->setFixedSize(largeur,hauteur+80);
	}
	else{
		this->setFixedSize(600,hauteur+80);
	}
	
	
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
	
	};
	
void Opengl::changerXmax(double n){
	this->cadre.x_max=n;
	
	};
	
void Opengl::changerYmin(double n){
	this->cadre.y_min=n;
	
	};

void Opengl::changerYmax(double n){
	this->cadre.y_max=n;
	
	};

void Opengl::changerZmax(double n){
	this->z_max=n;
	
	};

void Opengl::changerGran(double n){
	this->granularite=n;
	
	};

void Opengl::refresh(){
	this->updateGL();
	this->updateGL();
}


void Opengl::enregistrer(){
	Cairo save_cairo(this->cadre.x_min,this->cadre.x_max,this->cadre.y_min,this->cadre.y_max,this->z_max,this->granularite);
	save_cairo.dessiner_M();
}
	
void Opengl::mandelbrot1(){
	this->selectfractale = 1;
	this->updateGL();
}

void Opengl::juliafatou1(){
	this->selectfractale = 2;
	this->updateGL();
}

void Opengl::juliafatou2(){
	this->selectfractale = 3;
	this->updateGL();
}

