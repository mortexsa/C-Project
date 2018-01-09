#include <iostream>
#include <cairo.hh>
#include <cairo-svg.h>
#include "Dessin.hh"
#include "cairo.hh"
#include <complex>
#include <cmath>
Cairo::Cairo(const double x_min, const double x_max, const double y_min, const double y_max, const double z_max,double granularite) : Dessin(x_min, x_max, y_min, y_max,  z_max,  granularite){};

void Cairo::dessiner_M(){
	cairo_surface_t *surface;
	cairo_t *cr;
	int x;
	int y;
	int imagex=(this->getCadreXmax()-this->getCadreXmin())/this->getGranularite();
	int imagey=(this->getCadreYmax()-this->getCadreYmin())/this->getGranularite();
	surface = cairo_svg_surface_create("svgfile.svg", imagex, imagey);	
	cr = cairo_create(surface);
	cairo_set_source_rgb(cr, 0, 0, 0);
	for(x=0; x<imagex; x+=1){
		for(y=0; y<imagey; y+=1){
			Point p = this->algoMandelbrot(x,y,this->getModMax(),100);
			cairo_set_source_rgb(cr, p.getr(), p.getg(), p.getb());
			cairo_arc(cr,x,y,1,0,2*M_PI);
			cairo_fill (cr);
		}		
	}



	cairo_stroke(cr);
	cairo_surface_destroy(surface);
	cairo_destroy(cr);



	
}

void Cairo::dessiner_J(std::complex<double> c){
	  cairo_surface_t *surface;
  cairo_t *cr;
	int x;
	int y;
	int imagex=(this->getCadreXmax()-this->getCadreXmin())/this->getGranularite();
	int imagey=(this->getCadreYmax()-this->getCadreYmin())/this->getGranularite();
	surface = cairo_svg_surface_create("svgfile.svg", imagex, imagey);	
	cr = cairo_create(surface);
	cairo_set_source_rgb(cr, 0, 0, 0);
    for(x=0; x<imagex; x+=1){
		for(y=0; y<imagey; y+=1){
				Point p = this->algoJuliaFatou(x,y,this->getModMax(),100,c);
				cairo_set_source_rgb(cr, p.getr(), p.getg(), p.getb());
				cairo_arc(cr,x,y,1,0,2*M_PI);
				cairo_fill (cr);
			}		
	}


	
  cairo_stroke(cr);
  cairo_surface_destroy(surface);
  cairo_destroy(cr);
	
	
	
	
}
Cairo::~Cairo(){};
