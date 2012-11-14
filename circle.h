#pragma once

#include <list>

using namespace std;

/**
 * @struct Circle
 *
 * Repr�sente un cercle
 */
struct Circle
{
    /**
     * Abscisse du centre du cercle
     */
    double x;

    /**
     * Ordonn�e du centre du cercle
     */
    double y;

    /**
     * Rayon du cercle
     */
    double r;

    /**
     * Irr�gularit� du cercle
     *
     * Plus ce nombre est petit, plus le cercle est "parfait"
     */
    double i;

    /**
     * Points de contour du cercle
     */
    list<pair<int, int> > edge;

    /**
     * Constructeur
     *
     * @param x L'abscisse du centre du cercle
     * @param y L'ordonn�e du centre du cercle
     * @param r Le rayon du cercle
     */
    explicit Circle(double x = 0.0, double y = 0.0, double r = 0.0);

    /**
     * Constructeur
     *
     * @param edge Les points de contour du cercle
     */
    explicit Circle(list<pair<int, int> > edge);

    /**
     * Destructeur
     */
    virtual ~Circle();
};

/**
 * Op�rateur d'�galit�
 *
 * @param lhs Op�rande de gauche
 * @param rhs Op�rande de droite
 *
 * @return True si les deux op�randes sont �gales, false sinon
 */
bool operator==(Circle lhs, Circle rhs);
