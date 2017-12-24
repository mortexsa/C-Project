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
    glutInitWindowSize(540,480);
    glutCreateWindow("Afficher un point");
    glClearColor(1,1,1,1);

    idList = glGenLists(1);
    glNewList(idList,GL_COMPILE); // Commence une liste de dessin
    

    double x,y,i;
    
    complex<double> z;
    for(x=-2; x<1; x+=0.003703704) {
        for(y=-1; y<1; y+=0.004166667) {
            complex<double> c(x*2.5,y*2.5);
            z = (0.0,0.0);
            i = 0;

            do {
                z = (z*z) + c;
                i = i + 1;
            }while(abs(z)<2 && i<50);

            if(i == MAX_ITTERATION) {
               
                addPoint(x, y);
            }

        }
    }


    glEndList(); // Une fois tous les points ajouté,
    // on termine la liste

    glutDisplayFunc(renderScene);
    glutMainLoop();
    return 0;
}