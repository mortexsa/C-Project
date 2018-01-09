#ifndef OPENGL_H
#define OPENGL_H

#include <glWidget.h>
#include "cairo.hh"
#include "Dessin.hh"
#include <complex>
#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
/*!
 *  \file opengl.h
 * \brief class d'opengl Qt
 */
 //! \class Opengl
/*! \brief class permettant d'initialiser de redimentionner et d'afficher l'interface Qt
contenant le dessin ainsi que les boutton
*/
class Opengl : public GLWidget, public Dessin 
{
    Q_OBJECT; /*< objet qt */
    QLabel * label; /*< label qt */
    QDoubleSpinBox *xmin; /*< SpinBox reglage de la limite à gauche du cadre */
    QDoubleSpinBox *xmax; /*< SpinBox reglage de la limite à droite du cadre */
    QDoubleSpinBox *ymin; /*< SpinBox reglage de la limite en bas du cadre */
    QDoubleSpinBox *ymax; /*< SpinBox reglage de la limite en haut du cadre */
    QDoubleSpinBox *zmax; /*< SpinBox reglage de la borne module pour le dessin des fractales */
    QDoubleSpinBox *granularite2; /*< SpinBox reglage de la granularite du quadrillage */
    
    QPushButton *save; /*< Button de sauvegarde du dessin dans un fichier svg (cairo) */
    QPushButton *ok; /*< Button de validation des nouveaux parametres */
    QPushButton *mandelbrot; /*< Button de selection de la fractale de mandelbrot */
    QPushButton *juliaFatou1; /*< Button de selection de la fractale de julia et fatou [-0.0519;0.688] */
    QPushButton *juliaFatou2; /*< Button de selection de la fractale de julia et fatou [-0.5770;0.478] */
    QPushButton *zoom; /*< Button de zoom avant sur la fractale*/
    QPushButton *dezoom; /*< Button de zoom arriere sur la fractale*/
    QPushButton *bas; /*< Button de direction Bas*/
    QPushButton *haut; /*< Button de direction Haut*/
    QPushButton *droit; /*< Button de direction Droit*/
    QPushButton *gauche; /*< Button de direction Gauche*/

 private: 
    int selectfractale; /*< Selection de la fractale*/
    
    
public:
    //! \brief constructeur de la class Opengl
        /*!
         * \param parent : Widget parent
         * \param x_min : valeur x_min du cadre
         * \param x_max : valeur x_max du cadre
         * \param y_min : valeur y_min du cadre
         * \param y_max : valeur y_max du cadre
         * \param z_max : valeur du module
         * \param granularite : valeur de la granularite
         */
    Opengl(QWidget *parent,const double x_min, const double x_max, const double y_min, const double y_max, const double z_max,double granularite);
    
    //! \brief ajout un point au dessin
    /*!
     *la fonction permet d'ajouter un point coloré au dessin en fonction de son x (abscisse)
     *  et de son y (ordonnée) 
     * \param x : valeur de la coordonnée en abcisse du point
     * \param y : valeur de la coordonnée en ordinnée du point 
     * \param r : quantite de rouge
     * \param g : quantite de vert
     * \param b : quantite de bleu
     */
    void addPoint(double x, double y, double r, double g, double b);
    
    //! \brief initialise la fenetre
    void initializeGL();

    //! \brief redimensionne la fenetre
    /*!
     * \param width : largeur de la fenetre
     * \param height : hauteur de la fenetre
     */
    void resizeGL(int width, int height);

    //! \brief affiche la fractale
    void paintGL();

    //! \brief methode virtuel pur pour le dessin de la fractal de Julia et Fatou
    /*!
     * la methode est définie dans les sous-classes Cairo et Opengl
     */
    void dessiner_J(std::complex<double> c);

    //! \brief methode virtuel pur pour le dessin de la fractal de Mandelbrot
    /*!
     * la methode est définie dans les sous-classes Cairo et Opengl
     */
    void dessiner_M();

    //! \brief fonction pour les touches clavier
    void keyPressEvent(QKeyEvent *keyEvent);
    
    
public slots:

    //! \brief changer Xmin du cadre
    /*!
     * \param n : limite à gauche du cadre
     */
	void changerXmin(double n);

    //! \brief changer Xmax du cadre
    /*!
     * \param n : limite à droite du cadre
     */
	void changerXmax(double n);

    //! \brief changer Ymin du cadre
    /*!
     * \param n : limite en bas du cadre
     */
	void changerYmin(double n);
	
    //! \brief changer Ymax du cadre
    /*!
     * \param n : limite en haut du cadre
     */
    void changerYmax(double n);
    
    //! \brief changer la borne du module
    /*!
     * \param n : borne du module
     */	
    void changerZmax(double n);
	
    //! \brief changer la granularite du quadrillage
    /*!
     * \param n : granularite du quadrillage
     */ 
    void changerGran(double n);

    //! \brief actualise la page avec les nouveau parametres
	void refresh();

    //! \brief sauvegarde le dessin de fractale dans un fichier svg
	void enregistrer();

    //! \brief selectionner la fractale de mandelbrot
    void mandelbrot1();

    //! \brief selectionner la fractale de julia et fatou [-0.0519;0.688]
    void juliafatou1();

    //! \brief selectionner la fractale de julia et fatou [-0.5770;0.478]
    void juliafatou2();

    //! \brief zoom avant sur la fractale
    void zoomFunc();

    //! \brief zoom arriere sur la fractale
    void dezoomFunc();

    //! \brief deplacement vers le bas sur la fractale
    void basFunc();

    //! \brief deplacement vers le haut sur la fractale
    void hautFunc();

    //! \brief deplacement vers la droite sur la fractale
    void droitFunc();

    //! \brief deplacement vers la gauche sur la fractale
    void gaucheFunc();
};

#endif
