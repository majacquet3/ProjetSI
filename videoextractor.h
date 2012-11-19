#pragma once

#include <QObject>
#include <iostream>
#include <opencv2/opencv.hpp>
//#include <opencv/cxcore.h>
//#include <opencv/highgui.h>
#include <QRegExp>

using namespace std;
using namespace cv;

/**
  * @class VideoExtractor
  *
  * Permet d'extraire des images depuis un fichier vid�o ou un flux vid�o
  * tel une webcam
  */
class VideoExtractor : public QObject
{
    Q_OBJECT

protected:
    /**
     * Le flux vid�o
     */
    CvCapture *video;

    /**
     * Frame actuelle
     */
    IplImage *frame;

    /**
     * Expression r�guli�re d�finissant le format utilis�
     * pour atteindre une trame
     */
    QRegExp timeFormat;

    /**
     * Indicateur de mode (webcam)
     *
     * @see isWebcam()
     */
    bool webcam;

    /**
      * Nombre d'images restant � extraire de la vid�o
      * Fix� � -2 pour une extraction continue.
      * 0 par d�faut
      */
    int extractSequence;

    /**
      * Frames pass�es depuis le d�but de la vid�o ou depuis la remise a 0 de la vid�o
      */
    int framesRetrieved;

public:
    /**
      * Nom du fichier vid�o ouvert
      */
    QString fileName;

    /**
     * Constructeur
     */
    explicit VideoExtractor();

    /**
      * Constructeur
      *
      * @param videoPath Chemin vers un fichier vid�o
      */
    explicit VideoExtractor(const string &videoPath);

    /**
     * Destructeur
     */
    virtual ~VideoExtractor();

    /**
      * Operateur de cast, effectue le conversion entre
      * Un VideoExtractor et une IplImage, concr�tement
      * retourne la frame actuelle.
      */
    operator IplImage*();

    /**
      * Trame suivante du flux vid�o
      *
      * @param timeToWait Temps d'attente pour passer � la trame suivant (pas d'attente par d�faut)
      * @return La trame actuelle
      */
    IplImage* nextFrame(int timeToWait = -1);

    /**
      * Charge un flux vid�o
      *
      * @param videoPath Chemin vers un fichier vid�o
      * @return Code de retour, erreur si n�gatif
      */
    int loadVideo(const string &videoPath);

    /**
      * Ouvre le flux vid�o depuis une webcam
      *
      * @return Code de retour, erreur si n�gatif
      */
    int loadDirectStream();

    /**
      * D�termine si le flux est arriv� � la fin
      *
      * @return Vrai si on est la fin du flux, faux sinon
      */
    bool isOver();

    /**
      * Avance la position dans le flux
      *
      * @param frameNumber Nombre de trames � sauter
      * @return La nouvelle trame
      */
    IplImage* advance(int frameNumber);

    /**
      * D�place le flux au temps indiqu�
      * Cette m�thode est ignor�e en mode stream
      *
      * @param ms Position dans le flux vid�o, en millisecondes
      */
    void goTo(int ms);

    /**
      * D�place le flux au temps indiqu�
      * Cette m�thode est ignor�e en mode stream
      *
      * @param time Position dans le flux vid�o, sous la forme hh:mm:ss
      */
    void goTo(string time);

    /**
     * D�termine si le mode est webcam
     *
     * @return Vrai si on effectue une lecture sur la webcam , faux si non.
     */
    bool isWebcam();

    /**
      * Ar�te l'action d'enregistrement courante
      */
    void stopRecording();

    /**
      * Ordonne au video extractor d'oublier les ressources qu'il utilise
      * (Lib�re la vid�o, mais pas la frame.)
      */
    void terminate();

    /**
      * Extrait la frame courante jpg dans un dossier
      */
    void saveFrame();

    /**
      * D�finit le nombre d'images � extraire
      *
      * @param n Le nombre d'images � extraire, -2 si toutes les images doivent �tre extraites
      */
    void extractImagesFromVideo(int n);

    /**
      * Remet la vid�o au d�but
      *
      * @param method 0 Relachement de la vid�o actuelle et recr�ation du contexte de la vid�o
      *               1 Methode goTo(0)
      */
    void restartVideo(int method = 1);

public slots:
    /**
      * Slot actionn� lorsque la slidebar est modifi�e
      *
      * @param val La nouvelle valeur de la position (0 - 100)
      */
    void goToPosition(int val);

signals:
    /**
      * Signal �mis lors du changement de position de la vid�o
      *
      * @param val La nouvelle valeur de la position (0 - 100)
      */
    void newVideoPosition(int val);

    void info(QString, QString);
};
