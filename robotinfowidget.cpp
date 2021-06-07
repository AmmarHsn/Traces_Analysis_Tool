#include "robotinfowidget.h"



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
        string stateInfo = robot->getAtom(k)->getStateInfo();
        if (stateInfo!=""){item1->appendRow(new QStandardItem(QString::fromStdString("State Information : "+stateInfo)));}
        item1->appendRow(new QStandardItem(QString::fromStdString("Neighbors = "+ to_string((robot->getAtom(k)->getNeighbor())))));
        item1->appendRow(new QStandardItem(QString::fromStdString("Sensor = "+ to_string((robot->getAtom(k)->getSensorReading())))));
    }

    QTreeView *vue = new QTreeView;

    vue->setModel(modele);
    layout->addWidget(vue);
    setLayout(layout);
    this->exec();

}
