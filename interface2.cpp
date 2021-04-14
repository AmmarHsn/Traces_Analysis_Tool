#include "interface2.h"
#include "ui_interface2.h"
#include <QStandardItemModel>
#include <QString>
#include <string>
#include <QPushButton>
#include <iostream>

Interface2::Interface2(QWidget *parent, vector<Experiment*>* exp_list, vector<string>*global_info, int nstates) :
    QMainWindow(parent),
    ui(new Ui::Interface2)
{
    ui->setupUi(this);
    expr_list = exp_list;
    this->global_info = global_info;
    this->nstates=nstates;
    load_expr();
    cw = new ColorWidget(this,nstates);
    ui->verticalLayout->addWidget(cw); // tester avec n grand !
    QObject::connect(cw,SIGNAL(setColor()),this,SLOT(setColor()));
    QObject::connect(ui->my_treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(setRobots(QTreeWidgetItem*)));
    QObject::connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
    QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));

}

Interface2::~Interface2()
{
    delete ui;
}

//Display experiemts
void Interface2::load_expr(){
    for (int i=0;i<(int)expr_list->size();i++) {
        QTreeWidgetItem* exp = new QTreeWidgetItem(ui->my_treeWidget);
        exp->setText(0,tr(qPrintable(QString::fromStdString(expr_list->at(i)->getname()))));
        exp->setText(1,tr(qPrintable(QString::number(expr_list->at(i)->getScore()))));
        exp->setText(2,tr(qPrintable(QString::number(expr_list->at(i)->getRobots()))));
    }
}

//delete robot widget to avoid memomry leak
void Interface2::delete_showing_robots(){                                   //don't known if it necessary
    for(int i=0; i<(int)showing_robots.size();i++){
        //std::cout<<showing_robots.at(i)->robot->getName()<<std::endl;
        ui->gridLayout_5->removeWidget(showing_robots.at(i));
        delete showing_robots.at(i);
        //std::cout<<showing_robots.at(i)->robot->getName()<<std::endl;     //Why is this still working after delete?
    }
    showing_robots.clear();
}




//slots
void Interface2::setRobots(QTreeWidgetItem *item){
    //ui->verticalLayout->clear();
    delete_showing_robots();
    QString exp_name = item->text(0);
    string name = exp_name.toStdString();
    int pos=0;
    for (int i=0;i<(int)expr_list->size();i++) {
        if(expr_list->at(i)->getname()==name){
            pos=i;
            break;
        }
    }
    //Display information box:
    ui->textEdit->clear();
    for (int i=0;i<(int)global_info->size();i++) {ui->textEdit->append((QString::fromStdString(global_info->at(i))));}

    vector<string>* info = expr_list->at(pos)->getinformation();
    for (int i =0;i<(int)info->size();i++) {ui->textEdit->append(QString::fromStdString(info->at(i)));}

    //Creating robotWidgets and placing it in a grid
    int col=0;
    int row=0;
    ui->spinBox->setMaximum(expr_list->at(pos)->getTimesteps()-1);
    ui->horizontalSlider->setMaximum(expr_list->at(pos)->getTimesteps()-1);
    for (int i=0;i<expr_list->at(pos)->getRobots();i++) {
        RobotWidget* rob = new RobotWidget(this, expr_list->at(pos)->getRobot(i));
        if(colorfilter){rob->setColor(colors);}
        QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), rob, SLOT(set_spinbox(int)));
        if(col<4){  //MAKE A GENERAL PARAMETER!
        ui->gridLayout_5->addWidget(rob,row,col);
        col++;
        } else {
            col=0;
            row++;
            ui->gridLayout_5->addWidget(rob,row,col);
        }
        showing_robots.push_back(rob);
    }
}

void Interface2::setColor(){
    this->colors=cw->getColors();
    colorfilter=true;
    for (int i=0;i<(int)showing_robots.size();i++) {showing_robots.at(i)->setColor(colors);}
}
