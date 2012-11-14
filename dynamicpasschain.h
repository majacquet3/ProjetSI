#ifndef DYNAMICPASSCHAIN_H
#define DYNAMICPASSCHAIN_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
    class dynamicPassChain;
}

class DynamicPassChain : public QDialog
{
    Q_OBJECT

public:
    /**
     * Constructeur
     */
    explicit DynamicPassChain(QWidget *parent = 0);

    /**
     * Destructeur
     */
    ~DynamicPassChain();

private:
    /**
     * Interface graphique
     */
    Ui::dynamicPassChain *ui;

    /**
     * Liste des noms des passes a appliquer
     */
    QList<QString> list;

public slots:
    /**
     * Ajout l'�l�ment double cliqu� a la liste des passes
     * choisies
     */
    void addItemToChosen();

    /**
     * Supprime l'�l�ment double cliqu� a la liste des passes
     * choisies
     */
    void removeItemToChosen();

    /**
     * Ajout de toutes les passes a la liste des passes choisies
     */
    void addAllItemsToChosen();

    /**
     * Suppression de toutes les passes a la liste des passes choisies
     */
    void removeAllItemsToChosen();

    /**
     * Slot appel� lorsque la boite de dialogue est accept�e
     * Bouton "Ok"
     */
    void dialogAccepted();

signals:
    /**
     * Signal �mis lors de l'appuie sur "Ok" de la bo�te de dialogue
     * Envoi la liste des nom des passes a appliquer
     */
    void emitList(QList<QString> list);
};

#endif // DYNAMICPASSCHAIN_H
