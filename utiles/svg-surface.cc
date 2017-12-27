/* M_PI is defined in math.h in the case of Microsoft Visual C++, Solaris,
 * et. al.
 */
#if defined(_MSC_VER)
#define _USE_MATH_DEFINES
#endif 
 
#include <string>
#include <iostream>
#include <cairommconfig.h>
#include <cairomm/context.h>
#include <cairomm/surface.h>
#include <cmath>

#define WIDTH   400
#define HEIGHT  300
    
    
    
    
typedef struct{
	double x,y;
}complex;
 
complex add(complex a,complex b){
	complex c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}
 
complex sqr(complex a){
	complex c;
	c.x = a.x*a.x - a.y*a.y;
	c.y = 2*a.x*a.y;
	return c;
}
 
double mod(complex a){
	return sqrt(a.x*a.x + a.y*a.y);
}
 
complex mapPoint(int width,int height,double radius,int x,int y){
	complex c;
	int l = (width<height)?width:height;
 
	c.x = 2*radius*(x - width/2.0)/l;
	c.y = 2*radius*(y - height/2.0)/l;
	return c;
}
 

int main()
{
#ifdef CAIRO_HAS_SVG_SURFACE

    std::string filename = "image.svg";
    double width = 400;
    double height = 200;
    auto surface = Cairo::SvgSurface::create(filename, width, height);

    auto cr = Cairo::Context::create(surface);

    cr->save(); // save the state of the context
    cr->set_source_rgb(0.86, 0.85, 0.47);
    cr->paint();    // fill image with the color
    
    
     
int x,y,n=50;
int i;
double coul;
double radius=2;
 complex z0,z1;
 complex c{-0.76,0.12}; 
	for(x=0;x<=WIDTH;x++)
		for(y=0;y<=HEIGHT;y++){
			z0 = mapPoint(WIDTH,HEIGHT,radius,x,y);
			for(i=1;i<=n;i++){
				z1 = add(sqr(z0),c);
				coul=(double)i/50;
				
				if(mod(z1)>radius) { 
					cr->set_source_rgb(coul, 1-coul, 1-coul);   
					cr->arc(x, y, 1, 0, 2 * M_PI);
					cr->fill();    break;}
				z0 = z1;
			    if(i>n) { cr->set_source_rgb( 1-coul, coul, 0);  
					cr->arc(x, y, 1, 0, 2 * M_PI);
					cr->fill();
				}
			}
		}
	
	
    cr->show_page();

    std::cout << "Wrote SVG file \"" << filename << "\"" << std::endl;
    return 0;

#else

    std::cout << "You must compile cairo with SVG support for this example to work."
        << std::endl;
    return 1;

#endif
}
