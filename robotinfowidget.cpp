#include "robotinfowidget.h"

//a faire monter
#include <QVBoxLayout>
#include <QTreeView>
#include <QStandardItemModel>
#include <QListView>
#include <string>
#include <QString>
//testing
#include <iostream>

using std::to_string;

RobotInfoWidget::RobotInfoWidget(Robot* rob): QDialog()
{
    this->robot = rob;

    QVBoxLayout *layout = new QVBoxLayout;
    QStandardItemModel *modele = new QStandardItemModel;

    QStandardItem *item = new QStandardItem(QString::fromStdString(robot->getName()));
    modele->appendRow(item);

    //Timing
    for(int k=0;k<robot->getNbrAtom();k++){
        QStandardItem *item1 = new QStandardItem(QString::fromStdString("T"+ to_string(robot->getAtom(k)->getTime())));
        item->appendRow(item1);

        //Info
        item1->appendRow(new QStandardItem(QString::fromStdString("State = "+ to_string((robot->getAtom(k)->getstate())))));
        item1->appendRow(new QStandardItem(QString::fromStdString("Neighbors = "+ to_string((robot->getAtom(k)->getNeighbor())))));
        item1->appendRow(new QStandardItem(QString::fromStdString("Sensor = "+ to_string((robot->getAtom(k)->getSensorReading())))));
    }

    QTreeView *vue = new QTreeView;
    vue->setModel(modele);
    layout->addWidget(vue);
    setLayout(layout);
    //setModal(true);
    this->exec();

}
