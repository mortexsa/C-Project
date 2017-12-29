#include <iostream>
#include <GL/glut.h>
#include <complex>

#define MAX_ITTERATION 50
using namespace std;
int idList;

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f,0.0f,0.0f);
    glCallList(idList); // Affiche toute la liste
    glFlush();
}

void addPoint(float x, float y){
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Afficher un point");
    glClearColor(1,1,1,1);

    idList = glGenLists(1);
    glNewList(idList,GL_COMPILE); // Commence une liste de dessin
    int x1= -2;
	int x2= 1;
	int y1= -1;
	int y2= 1;
	int zoomx=500/(x2-x1);
	int zoomy=500/(y2-y1);

    double x,y,i;
    double a,b;
    complex<double> z;
    for(x=0; x<600; x+= width) {
        for(y=0; y<600; y+= height) {
           
            complex<double> c(x,y);
            z = (0.0,0.0);
            i = 0;

            do {
                z = (z*z) + c;
                i = i + 1;
            }while(abs(z)<2 && i<100);

            if(i == 100) {
               
                addPoint(x+1, y);
            }

        }
    }


    glEndList(); // Une fois tous les points ajouté,
    // on termine la liste

    glutDisplayFunc(renderScene);
    glutMainLoop();
    return 0;
}