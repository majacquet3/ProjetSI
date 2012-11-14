#pragma once

#include <opencv/cv.h>
#include <list>
#include "circle.h"

/**
 * @class IPass
 *
 * D�finit une interface permettant d'effectuer un traitement sur une image
 */
class IPass
{
public:
    /**
     * Destructeur
     */
    virtual ~IPass();

    virtual list<Circle> getCircles() const;

    /**
     * Ex�cute le traitement
     *
     * @param source L'image � traiter
     * @return L'image trait�e
     */
    virtual IplImage *operator()(IplImage *source) = 0;
};
