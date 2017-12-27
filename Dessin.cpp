#include "Dessin.h"

POINT Dessin::mondelbrot(double x, double y) {
    POINT merde;
    do {
        z = (z*z) + c;
        i = i + 1;
    }while(abs(z)<2 && i<50);
    if(i == MAX_ITTERATION) {
               
       merde.x = x;
       merde.y = y;
       merde.r = jcp;
       merde.v = jcp;
       merde.b = jcp;
    }
    return merde;
}