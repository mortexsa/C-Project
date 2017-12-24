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

  surface = cairo_svg_surface_create("svgfile.svg", 390, 390);
  cr = cairo_create(surface);
	int x1= -2.1;
	int x2= 0.6;
	int y1= -1.2;
	int y2= 1.2;
	int zoomx=390/(x2-x1);
	int zoomy=390/(y2-y1);
  cairo_set_source_rgb(cr, 0, 0, 0);
   double x,y,i;
		
    complex<double> z;
    for(x=0; x<390; x+=1) {
		cout<<"wesh";
        for(y=0; y<390; y+=1) {
            complex<double> c(x/(zoomx+x1),y/(zoomy+y1));
            z = (0.0,0.0);
            i = 0;

            do {
                z = (z*z) + c;
                i = i + 1;
            }while(abs(z)<2 && i<50);

            if(i == MAX_ITTERATION) {
				cout<<"hello";
				cairo_rectangle(cr,x,y,1,1);

				
			}		
		}
}

	cairo_fill (cr);
  cairo_stroke(cr);
  cairo_surface_destroy(surface);
  cairo_destroy(cr);
 //~ cairo_surface_t *surface;
  //~ cairo_t *cr;

  //~ surface = cairo_svg_surface_create("svgfile.svg", 390, 390);
  //~ cr = cairo_create(surface);

  //~ cairo_set_source_rgb(cr, 250, 0, 0);
  //~ cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
      //~ CAIRO_FONT_WEIGHT_NORMAL);
  //~ cairo_set_font_size(cr, 40.0);

  //~ cairo_move_to(cr, 10.0, 50.0);
  //~ cairo_rectangle(cr, 30, 30, 100, 100);
  //~ cairo_stroke(cr);	


  //~ cairo_surface_destroy(surface);
  //~ cairo_destroy(cr);

  return 0;
  
}
