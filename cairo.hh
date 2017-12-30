#ifndef CAIRO_HH
#define CAIRO_HH


#include <iostream>
#include "Dessin.hh"
#include <complex>

class Cairo : public dessin{
		public:
		Cairo(const double x_min, const double x_max, const double y_min, const double y_max, const double z_max);
		void dessiner_M(double x, double y, int i);
		void dessiner_J(double x, double y, int i);
		~Cairo();
}









#endif
