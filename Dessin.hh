#ifndef DESSIN_HH
#define DESSIN_HH
#include <complex>
#include "Point.hh"


#define HAUTEUR 600
#define LARGEUR 600


/*!
 *  \file Dessin.hh
 * \brief class abstraite de dessin
 */
 

//! \struct cadre
/*! \brief objet représentant le cadre du dessin 
la structure contient les variables x_min, x_max, y_min, y_max  représentant les limite du cadre
*/ 
struct cadre {
    double x_min; /*< limite à gauche du cadre */
    double x_max; /*< limite à droite du cadre */
    double y_min; /*< limite en bas du cadre  */
    double y_max; /*< limite en haut du cadre   */
} typedef CADRE;




//! \class Dessin
/*! \brief class abstraite contenant les variables permettant de dessiner 
 * 
 */
class Dessin {
protected: 
    CADRE cadre;  /*!< cadre du dessin */
    double z_max; /*!< borne module pour le dessin des fractales */
    double granularite; /*!< granularite du quadrillage */
    
public:
	
	//! \brief constructeur par default 
	/*! constructeur par default de la class Dessin
	 */
	Dessin();
	
	//! \brief constructeur de la class Dessin
		/*!
		 * \param x_min : valeur x_min du cadre
		 * \param x_max : valeur x_max du cadre
		 * \param y_min : valeur y_min du cadre
		 * \param y_max : valeur y_max du cadre
		 * \param z_max : valeur du module
		 * \param granularite : valeur de la granularite
		 */
    Dessin(const double x_min, const double x_max, const double y_min, const double y_max, const double z_max,double granularite);
    
    
    
    //! \brief destructeur de la class Dessin
		/*!
		 * Destructeur 
		 */
    ~Dessin();
    
    //! \brief changer la cadre
    /*! methode permettant de changer le cadre
     */
    void setCadre(const double x_min, const double x_max, const double y_min, const double y_max);
    
    //! \brief avoir x_min
    double getCadreXmin();
    
    //! \brief avoir x_max
    double getCadreXmax();
    
    //! \brief avoir y_min
    double getCadreYmin();
    
    //! \brief avoir y_max
    double getCadreYmax();
    
    //! \brief avoir la granularite
    double getGranularite();
    
    //! \brief changer le module
    void setModMax(const double z_max);
    
    //! \brief avoir le module
    double getModMax();
    
    
    //! \brief algo pour la fractale de Mandelbrot
    /*!
     *la fonction permet d'obtenir la couleur d'un point en fonction de ses coordonnées, de la borne du module et du nombre d'iteration maximum
     * Pour cela la fonction initialise les complex z et c puis calcul les valeurs de la suite pour le point, 
     * on donne la couleur du point en fonction de la convergence de la suite ie des valeur du nombre d'iteration et de la valuer de z 
     * \param x : valeur de la coordonnée en abcisse du point
     * \param y : valeur de la coordonnée en ordinnée du point 
     * \param z_max : valeur de la borne du module
     * \param n_max : valeur du nombre d'iteration maximum
     * \return une instance de la classe Point 
     */
    Point algoMandelbrot(const double x, const double y, const double z_max, const int n_max);
    
    
    //! \brief algo pour la fractale de Julia et Fatou
    /*!
     * la fonction permet d'obtenir la couleur d'un point en fonction de ses coordonnées, de la borne du module, du nombre d'iteration maximum
     * et du complex c. 
     * Pour cela la fonction initialise le complex z puis calcul les valeurs de la suite pour le point, 
     * on donne la couleur du point en fonction de la convergence de la suite ie des valeur du nombre d'iteration et de la valuer de z 
     * \param x : valeur de la coordonnée en abcisse du point
     * \param y : valeur de la coordonnée en ordinnée du point 
     * \param z_max : valeur de la borne du module
     * \param n_max : valeur du nombre d'iteration maximum
     * \param c : valeur du complex c
     * \return une instance de la classe Point 
     * 
     */
    Point algoJuliaFatou(const double x,const double y,const double z_max,const int n_max,const std::complex<double> c);
    
    //! \brief methode virtuel pur pour le dessin de la fractal de Mandelbrot
    /*!
     * la methode est définie dans les sous-classes Cairo et Opengl
     */
    virtual void dessiner_M()=0;
    
    
    //§ \brief methode virtuel pur pour le dessin de la fractal de Julia et Fatou
    /*!
     * la methode est définie dans les sous-classes Cairo et Opengl
     */
    virtual void dessiner_J(std::complex<double> c)=0;
     
};

#endif
