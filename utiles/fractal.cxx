#include <cairo.h>
#include <cairo-svg.h>
#include <iostream> 
#include <complex> 
#define MAX_ITTERATION 50

using namespace std;


int main(void)  	
{
cairo_surface_t *surface;
cairo_t *cr;



int x1= -2.1;	
int x2= 1.6;
int y1= -1.2;
int y2= 1.2;
int zoom=300;
int imagex=zoom*(x2-x1);
int imagey=zoom*(y2-y1);

double x,y,i;
surface = cairo_svg_surface_create("svgfile.svg", imagex, imagey);	
cr = cairo_create(surface);
cairo_set_source_rgb(cr, 0, 0, 0);
complex<double> z;
for(x=0; x<imagex; x+=0.5) {

    for(y=0; y<imagey; y+=0.5) {
        complex<double> c(x/zoom+x1,y/zoom+y1);
        z = (0.0,0.0);
        i = 0;

        do {
            z = (z*z) + c;
            i = i + 1;
        }while(abs(z)<2 && i<100);

        if(i == 100) {
          cairo_rectangle(cr,x,y,0.5,0.5);
        }		
    }
}

cairo_fill (cr);
cairo_stroke(cr);
cairo_surface_destroy(surface);
cairo_destroy(cr);
return 0;
}
/*
int main(void)  	
{
  cairo_surface_t *surface;
  cairo_t *cr;

  surface = cairo_svg_surface_create("svgfile.svg", 1000, 1000);
  cr = cairo_create(surface);
	int x1= -2;
	int x2= 1;
	int y1= -1;
	int y2= 1;
	int zoomx=1000/(x2-x1);
	int zoomy=1000/(y2-y1);
  cairo_set_source_rgb(cr, 0, 0, 0);
   double x,y,i;
		
    complex<double> z;
    for(x=0; x<1000; x+=1) {
        for(y=0; y<1000; y+=1) {
            complex<double> c(x/zoomx+x1,y/zoomy+y1);
            z = (0.0,0.0);
            i = 0;

            do {
                z = (z*z) + c;
                i = i + 1;
            }while(abs(z)<2 && i<50);

            if(i == MAX_ITTERATION) {
				cairo_rectangle(cr,x,y,1,1);

				
			}		
		}
}

	cairo_fill (cr);
  cairo_stroke(cr);
  cairo_surface_destroy(surface);
  cairo_destroy(cr);
  return 0;
  
}*/



