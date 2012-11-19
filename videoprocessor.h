#pragma once

#include <opencv2/opencv.hpp>

#include <QThread>
#include <QObject>
#include <QMutex>
#include <QWaitCondition>

#include "videoextractor.h"

/**
 * @class VideoProcessor
 *
 * Lance la lecture de la video en parallele
 */
class VideoProcessor : public QThread
{
    Q_OBJECT

protected:
    /**
     * Flux video en entr�e
     */
    VideoExtractor *input;

    /**
     * Image en sortie
     */
    IplImage *output;

    /**
     * Indique si le jeux est en pause
     */
    bool paused;

    /**
     * Indique que le thread fait son premier tour de boucle
     */
    bool firstTime;

    /**
      * Mutex de traitement des images
      */
    QMutex *mutex;

    /**
      * Mutex de la pause
      */
    QMutex mutexPause;

    /**
      * Variable de conditions qui attend le r�veil par le controller
      */
    QWaitCondition *waitcond;

    /**
      * Condition d'attente de la pause
      */
    QWaitCondition waitcondPause;

    /**
     * S'il est � True, arr�te le run
     */
    bool isStopped;

    /**
      * D�finit la vitesse de la vid�o, plus exactement le temps que
      * le videoProcessor doit attendre (en ms) avant de demander
      * la nouvelle image a l'extracteur de vid�o
      * Initialement 180ms
      */
    int forward;

public:
    /**
     * Constucteur
     *
     * @param input     L'image en entr�e
     */
    explicit VideoProcessor(VideoExtractor *input, QMutex *mutex, QWaitCondition *waitcond);

    /**
     * Destructeur
     */
    virtual ~VideoProcessor();

    /**
     * Accesseur : input
     *
     * @return Le flux video en entr�e
     */
    VideoExtractor *getInput() const;

    /**
     * Accesseur : input
     *
     * @param input Le flux video en entr�e
     */
    void setInput(VideoExtractor *input);

    /**
     * Accesseur : output
     *
     * @return L'image en sortie
     */
    IplImage *getOutput() const;

    /**
     * Lance le traitement
     */
    void run();

    /**
     * La lecture de la vid�o n'est plus en pause
     */
    void play();

    /**
     * Si la vid�o est en pause ou non
     * @return True si la vid�o est en pause, false sinon
     */
    bool isPaused();

    /**
     * Indique si une vid�o est charg�e.
     *
     * @return Vrai si un flux vid�o est charg�, faux si non
     */
    bool videoLoaded();

    /**
     * Passe le bool�en stop � false pour arr�ter le traitement
     */
    void stop();

    /**
      * Param�tre l'avance rapide ou non.
      *
      * @param enabled D�finit si on doit �tre en avance rapide ou non
      */
    void setForward(bool enabled);

signals:
    /**
     * Envoi la frame suivante.
     */
    void nextFrame(IplImage *output);

public slots:
    /**
     * La lecture de la vid�o est en pause
     */
    void pause();
};
