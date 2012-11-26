#pragma once

#include <list>

using namespace std;

/** @brief Repr�sente un cerle.
 */
struct Circle
{
    /** @brief Abscisse du centre du cercle
     */
    double x;

    /**  @brief Ordonn�e du centre du cercle
     */
    double y;

    /** @brief Rayon du cercle
     */
    double r;

    /** @brief
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
