#include "Dessin.hh"
#include "cairo.hh"
#include "opengl.h"
#include <iostream>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGridLayout>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Opengl test(0,-2,1,-1,1,2,0.004);
    test.show();   //Exécution de notre fenêtre de rendu OpenGL
	
	return app.exec();
}

