#include <iostream>
#include <cairo.h>
#include <cairo-svg.h>
#include "Dessin.hh"
#include "cairo.hh"
#include <complex>

Cairo::Cairo(const double x_min, const double x_max, const double y_min, const double y_max, const double z_max,double granularite) : Dessin(const double x_min, const double x_max, const double y_min, const double y_max, const double z_max, double granularite);

void Cairo::dessiner_M(){
  cairo_surface_t *surface;
  cairo_t *cr;
	int zoom=1/this->getGranularite();
	
  

	
	int imagex=this->getGranularite()/(this->getCadreXmax()-this->getCadreXmin());
	int imagey=this->getGranularite()/(this->getCadreYmax()-this->getCadreYmin());
	surface = cairo_svg_surface_create("svgfile.svg", imagex, imagey);	
	cr = cairo_create(surface);
	cairo_set_source_rgb(cr, 0, 0, 0);
    for(x=0; x<imagex; x+=1){
		for(y=0; y<imagey; y+=1){
			int i=this->algoMandelbrot(x,y,this->getModMax(),100);
				cairo_set_source_rgb(cr, 0, 0, i*255/100);
				cairo_rectangle(cr,x,y,1,1);
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
	int zoom=1/this->getGranularite();
	
  

	
	int imagex=this->getGranularite()/(this->getCadreXmax()-this->getCadreXmin());
	int imagey=this->getGranularite()/(this->getCadreYmax()-this->getCadreYmin());
	surface = cairo_svg_surface_create("svgfile.svg", imagex, imagey);	
	cr = cairo_create(surface);
	cairo_set_source_rgb(cr, 0, 0, 0);
    for(x=0; x<imagex; x+=1){
		for(y=0; y<imagey; y+=1){
			int i=this->algoJuliaFatou(x,y,this->getModMax(),100,c);
				cairo_set_source_rgb(cr, 0, 0, i*255/100);
				cairo_rectangle(cr,x,y,1,1);
				cairo_fill (cr);
			}		
	}


	
  cairo_stroke(cr);
  cairo_surface_destroy(surface);
  cairo_destroy(cr);
	
	
	
	
}
	
