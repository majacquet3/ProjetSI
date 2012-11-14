#pragma once

#include "circle.h"
#include "ipass.h"

using namespace std;

/**
 * @class CircleDetectionPass
 *
 * Fournit une interface permettant de d�tecter des cercles sur une image
 */
class CircleDetectionPass : public IPass
{
protected:
    /**
     * Cercles d�tect�s
     */
    list<Circle> circles;

public:
    /**
     * Destructeur
     */
    virtual ~CircleDetectionPass();

    /**
     * Accesseur : circles
     *
     * @return Les cercles d�tect�s
     */
    virtual list<Circle> getCircles() const;

    /**
     * Vide la liste des cercles d�tect�s
     */
    void clear();
};
