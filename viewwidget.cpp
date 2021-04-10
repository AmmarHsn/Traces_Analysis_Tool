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



ViewWidget::ViewWidget(vector<string>* glb, vector<Experiment*>* exp_list) : QWidget()
{
    this->list=exp_list;

    QVBoxLayout *layout = new QVBoxLayout;

    QStandardItemModel *modele = new QStandardItemModel;

    //global informatoin or error lines
    QStandardItem *itemG = new QStandardItem(QString::fromStdString("Global information"));
    modele->appendRow(itemG);
    for (int i=0;i<(int)glb->size();i++) {
        QStandardItem* itemG1 = new QStandardItem(QString::fromStdString((glb->at(i))));
        itemG->appendRow(itemG1);
    }



    for(int i=0;i<(int)list->size();i++)
    {
        //Experiment
        string exp_name = list->at(i)->getname();
        QStandardItem *item = new QStandardItem(QString::fromStdString(exp_name));
        modele->appendRow(item);

        //Experiment information
        QStandardItem *item0 = new QStandardItem(QString::fromStdString("Information"));
        item->appendRow(item0);
        vector<string>* ptr =list->at(i)->getinformation();
        for (int i=0;i<(int)ptr->size();i++) {
            QStandardItem* item01 = new QStandardItem(QString::fromStdString((ptr->at(i))));
            item0->appendRow(item01);
       }

        //Experiment Score
        QStandardItem *itemS = new QStandardItem(QString::fromStdString("Score"));
        item->appendRow(itemS);
        itemS->appendRow(new QStandardItem(QString::fromStdString("Score = "+ to_string((list->at(i)->getScore())))));


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
