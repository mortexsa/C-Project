#include "Dessin.hh"
#include "cairo.hh"
#include "opengl.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
	{
	    QApplication app(argc, argv);
	    Opengl test(0,-2,1,-1,1,2,0.005); //Ajout de notre classe myWindow
	    test.show();   //Exécution de notre fenêtre de rendu OpenGL
		//test.setFixedSize((2.6+2.6)/0.003,(2.0+2.0)/0.003);
		test.setFixedSize((3)/0.005,(2)/0.005);

		return app.exec();
	}

 //~ Cairo test(-2.6,2.6,-2,2,2,0.01);
 //~ test.dessiner_M();
 //~ Opengl test2(0,-2.6,2.6,-2,2,2,0.01);
 //~ test2.initializeGL();
 //~ test2.resizeGL(500,500);
 //~ test2.paintGL();


    //~ return 0;
//~ }
