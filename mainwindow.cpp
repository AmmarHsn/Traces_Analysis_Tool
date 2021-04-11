#include "mainwindow.h"


#include <QLineEdit>
#include <QFormLayout>
#include <QMenuBar>

MainWindow::MainWindow()
{

    //CENTRAL WIDGET
    QWidget *centralZone = new QWidget;
    QLineEdit *nom = new QLineEdit;
    QLineEdit *prenom = new QLineEdit;
    QLineEdit *age = new QLineEdit;

    QFormLayout *layout = new QFormLayout;
    layout->addRow("Votre nom", nom);
    layout->addRow("Votre prénom", prenom);
    layout->addRow("Votre âge", age);
    centralZone->setLayout(layout);
    setCentralWidget(centralZone);      // set a widget in the center ! wiget can contain other widgets!

    //MENU WIDGET
    QMenu *menuFichier = menuBar()->addMenu("Fichier");    //les & sont des raccourci clavier!
    //QMenu *menuEdition = menuBar()->addMenu("Edition");
    //QMenu *menuAffichage = menuBar()->addMenu("&Affichage");
    QAction *actionQuitter = new QAction("&Quitter", this);
    menuFichier->addAction(actionQuitter);

    //barre
    QToolBar *toolBarFichier = addToolBar("Fichier222");
    //toolBarFichier->addAction(actionQuitter);
    //connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
}
