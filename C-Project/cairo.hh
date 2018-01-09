#ifndef CAIRO_HH
#define CAIRO_HH


#include <iostream>
#include "Dessin.hh"
#include <complex>

/*!
 *  \file cairo.hh
 * \brief enregistrement de fractale
 */
 


//! \class cairo 
/*! \brief class permettant l'enregistrement avec la bilbiotheque Cairo
cette classe héritant de la classe dessin, permet l'enregistrement de la fractal sous forme d'un fichier svg
*/ 
 class Cairo : public Dessin {
		public:
		//! \brief constructeur de la class cairo
		/*!
		 le constructeur prend les mêmes argument que la classe dessin
		 */
		Cairo(const double x_min, const double x_max, const double y_min, const double y_max, const double z_max,double granularite);
		
		
		//! \brief enregistrement de la fractale de mandelbrot
		/*! 
		  la fonction utilise les attributs de la classe pour enregistrer la fractale
		  * Pour cela la fonction crée une surface de dessin svg, calcule la taille de l'image en fonction du cadre et de la granularité puis calcule la couleur de chaque 
		 * pixel en fonction de ses coordonnées grâce à la fonction algoMandelbrot héritée de la classe Dessin. 
		*/
		void dessiner_M();
		
		//! \brief enregistrement de la fractale de julia et Fatou
		/*!
		 la fonction utilise les attributs de la classe et du complex c pour enregistrer la fractale
		 * Pour cela la fonction crée une surface de dessin svg, calcule la taille de l'image en fonction du cadre et de la granularité puis calcule la couleur de chaque 
		 * pixel en fonction de ses coordonnées grâce à la fonction algoJuliaFatou héritée de la classe Dessin.     
		 \c dessiner_J()
		 \param c complex utilisé pour dessiner la fractal de julia et Fatou
		 */
		void dessiner_J(std::complex<double> c);
		
		
		//! \brief destructeur de la class cairo
		/*!
		 * Destructeur
		*/
		~Cairo();
};









#endif
