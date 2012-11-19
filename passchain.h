#pragma once

#include <list>

#include <opencv2/opencv.hpp>

#include "ipass.h"

using namespace std;

/**
 * @class PassChain
 *
 * Repr�sente une cha�ne de passes
 */
class PassChain
{
protected:
    /**
     * Liste des passes � ex�cuter
     */
    list<IPass*> passes;

public:
    /**
     * Destructeur
     */
    virtual ~PassChain();

    /**
     * Renvoie la taille de la liste de passes
     */
    int size() const;

    /**
     * Vide la liste de passes
     */
    void clear();

    /**
     * Ajoute une passe � la liste des passes � ex�cuter
     *
     * @param pass La passe � ajouter
     */
    void add(IPass *pass);

    /**
     * Traite une image en suivant la cha�ne de passes
     * L'image r�sultante doit �tre lib�r�e par l'appelant
     * avec cvReleaseImage
     *
     * @param source L'image � traiter
     * @return L'image trait�e
     */
    virtual IplImage *process(const IplImage *source);
};
