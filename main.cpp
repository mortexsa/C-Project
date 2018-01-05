#include "Dessin.hh"
#include "cairo.hh"
#include "opengl.h"
#include <iostream>
#include <QPushButton>
using namespace std;
int main(int argc, char *argv[])
	{
	    QApplication app(argc, argv);
	    Opengl test(0,-2,1,-1,1,2,0.003); 
		test.ouvrirDialogue();
	    test.show();   //Exécution de notre fenêtre de rendu OpenGL
		//test.setFixedSize((2.6+2.6)/0.003,(2.0+2.0)/0.003);
		test.setFixedSize((3)/0.003,(2)/0.003);
		while(1)
		{
			test.ouvrirDialogue();
			test.updateGL();
		}

 
 
    //~ QPushButton* m_bouton = new QPushButton("Quitter");
    //~ m_bouton->setFont(QFont("Comic Sans MS", 14));
    //~ m_bouton->move(110, 50);
    //~ m_bouton->move(200, 50);
	//~ m_bouton->show();
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
