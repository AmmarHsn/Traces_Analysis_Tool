#include "colorwidget.h"
#include "ui_colorwidget.h"

//a monter en haut
#include <string.h>
using std::string;
using std::to_string;
#include <QPushButton>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QColorDialog>

//a retire
#include <iostream>


ColorWidget::ColorWidget(QWidget *parent, int nstates) :
    QWidget(parent),
    ui(new Ui::ColorWidget)
{
    ui->setupUi(this);
    this->nstates = nstates;
    colors.reserve(nstates);
    for (int i=0;i<nstates;i++) {colors.push_back(QColor());}
    designWidget();
}

ColorWidget::~ColorWidget()
{
    delete ui;
}


void ColorWidget::designWidget(){
    for (int i=0;i<nstates;i++) {
        QHBoxLayout* hline = new QHBoxLayout;
        MyPushBoutton* boutton = new MyPushBoutton(i);
        QObject::connect(boutton, SIGNAL(send(int)),this ,SLOT(setColor(int)));
        hline->addWidget(boutton);
        QLabel* color = new QLabel();
        stateColor.push_back(color);
        hline->addWidget(color);
        ui->verticalLayout->addLayout(hline);
    }
}

bool ColorWidget::allButtonSet(){
    bool b=true;
    for(int i=0;i<nstates;i++){
        if(stateColor.at(i)->text().toStdString()==""){
            b=false;
            break;
        }
    }
    return b;
}

vector<QColor>* ColorWidget::getColors(){return &colors;}

//slots
void ColorWidget::setColor(int state){
    std::cout<<state<<std::endl;
    colors.at(state) = QColorDialog::getColor(Qt::white, this);
    stateColor.at(state)->setText(colors.at(state).name());
    if(allButtonSet()){
        emit setColor();
    }
}









