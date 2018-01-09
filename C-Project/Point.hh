#ifndef POINT_HH
#define POINT_HH


/*!
 *  \file Point.hh
 * \brief class Point 
 */
 
 
//! \struct color
/*! \brief objet la couleur d'un point 
la structure represente une couleur par la quantite de rouge, vert et bleu
*/  
struct color {
    double r; /*< quantite de rouge */
    double g; /*< quantite de vert */
    double b; /*< quantite de bleu */
}typedef COLOR;


//! \class Point
/*! \brief class represantant un point
 * 
 */
class Point {
private:
    double x; /*< abcisse du point */
    double y; /*< ordonné du point */
    COLOR couleur; /*< couleur du point */
public:
    friend class Dessin;
    
    
    //! \brief constructeur par default 
	/*! constructeur par default de la class Point
	 */
    Point(); 
    
    	//! \brief constructeur de la class Point
		/*!
		 * \param x : abscisse du point
		 * \param y : ordonnée du point
		 * \param r : quantite de rouge pour la couleur du point
		 * \param g : quantite de vert pour la couleur du point
		 * \param b : quantite de bleu pour la couleur du point
		 */
    Point(const double x,const double y, const double r, const double g, const double b); 
    
    //! \brief destructeur de la class Point
    ~Point(); 
    
    //! \brief accesseur de l'abcisse
    double getPx() const;
    
    //! \brief accesseur de l'ordonne
    double getPy() const;
    
    //! \brief accesseur de la quantite de rouge
    double getr() const;
    
    //! \brief accesseur de la quantite de vert
    double getg() const;
    
    //! \brief accesseur de la quantite de bleu
    double getb() const;
    
    //! \brief redefinition de l'operateur =
    Point& operator=(const Point& p);
};


#endif
