#include "interface2.h"
#include "ui_interface2.h"
#include <QStandardItemModel>
#include <QString>
#include <string>

Interface2::Interface2(QWidget *parent, vector<Experiment*>* exp_list) :
    QMainWindow(parent),
    ui(new Ui::Interface2)
{
    ui->setupUi(this);
    expr_list = exp_list;
    load_expr();
    QObject::connect(ui->my_treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), this, SLOT(setRobots(QTreeWidgetItem*)));
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
    }
}

//slots
void Interface2::setRobots(QTreeWidgetItem *item){
    ui->treeWidget_2->clear();
    QString exp_name = item->text(0);
    string name = exp_name.toStdString();
    int pos=0;
    for (int i=0;i<(int)expr_list->size();i++) {
        if(expr_list->at(i)->getname()==name){
            pos=i;
            break;
        }
    }
    for (int i=0;i<expr_list->at(pos)->getRobots();i++) {
        QTreeWidgetItem* exp = new QTreeWidgetItem(ui->treeWidget_2);
        exp->setText(0,tr(qPrintable(QString::fromStdString(expr_list->at(pos)->getRobot(i)->getName()))));
    }
}
