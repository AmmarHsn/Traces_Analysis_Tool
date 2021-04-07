#include "viewwidget.h"



#include <QVBoxLayout>
#include <QTreeView>
#include <QStandardItemModel>
#include <QListView>
#include <string>
#include <QString>

using std::to_string;
//testing
#include <iostream>



ViewWidget::ViewWidget(vector<Experiment*>* exp_list) : QWidget()
{
    this->list=exp_list;

    QVBoxLayout *layout = new QVBoxLayout;

    QStandardItemModel *modele = new QStandardItemModel;

    for(int i=0;i<(int)list->size();i++)
    {
        //Experiment
        string exp_name = list->at(i)->getname();
        QStandardItem *item = new QStandardItem(QString::fromStdString(exp_name));
        modele->appendRow(item);

        //Robot
        for(int j=0;j<list->at(i)->getRobots();j++){

            QStandardItem *item2 = new QStandardItem(QString::fromStdString(list->at(i)->getRobot(j)->getName()));
            item->appendRow(item2);

            //Timing
            for(int k=0;k<list->at(i)->getRobot(j)->getNbrAtom();k++){
                QStandardItem *item3 = new QStandardItem(QString::fromStdString("T"+ to_string((list->at(i)->getRobot(j)->getAtom(k)->getTime()))));
                item2->appendRow(item3);

                //Info
                item3->appendRow(new QStandardItem(QString::fromStdString("State = "+ to_string((list->at(i)->getRobot(j)->getAtom(k)->getstate())))));
                item3->appendRow(new QStandardItem(QString::fromStdString("Neighbors = "+ to_string((list->at(i)->getRobot(j)->getAtom(k)->getNeighbor())))));
                item3->appendRow(new QStandardItem(QString::fromStdString("Sensor = "+ to_string((list->at(i)->getRobot(j)->getAtom(k)->getSensorReading())))));
            }
        }


    }





    QTreeView *vue = new QTreeView;
    vue->setModel(modele);

    layout->addWidget(vue);
    setLayout(layout);

}
