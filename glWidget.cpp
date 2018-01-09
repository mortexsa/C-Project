#include "glWidget.h"
#include <string.h>

GLWidget::GLWidget(int framesPerSecond, QWidget *parent, char *name) 
    : QGLWidget(parent)
{
    setWindowTitle(QString::fromUtf8(name));
   
}



void GLWidget::timeOutSlot()
{
}
