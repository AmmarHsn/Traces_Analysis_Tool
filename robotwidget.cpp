#include "robotwidget.h"
#include "ui_robotwidget.h"

RobotWidget::RobotWidget(QWidget *parent, Robot* rob) :
    QWidget(parent),
    ui(new Ui::RobotWidget)
{
    ui->setupUi(this);
    robot=rob;
    setRobot();
    ui->Slider->setMaximum(robot->getNbrAtom()-1);
    ui->spinBox->setMaximum(robot->getNbrAtom()-1);
    QObject::connect(ui->Slider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
    QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(refresh_info(int)));
    QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->Slider, SLOT(setValue(int)));
}

RobotWidget::~RobotWidget()
{
    delete ui;
}

void RobotWidget::setRobot(){
    ui->name->setText(QString::fromStdString(robot->getName()));
    ui->ps->setText(QString::number(robot->getPreviousState()));
    ui->cs->setText(QString::number(robot->getCurrentState()));
    ui->ns->setText(QString::number(robot->getNextState()));
    //ui->ti->setText(QString::number(robot->getTime()));
    ui->nbrNeighbors->setText(QString::number(robot->getNeighbor()));
    ui->sr->setText(QString::number(robot->getSensorReading()));
    if(colorfilter){
        QString ca = "color:";
        ca+= colors->at(robot->getCurrentState()).name();
        ca+=";";
        ui->frame->setStyleSheet((ca));
    }
}

void RobotWidget::setColor(vector<QColor>* colors){this->colors=colors;colorfilter=true;}
Robot* RobotWidget::getRobot(){return robot;}

//slots
void RobotWidget::refresh_info(int nbr){
    robot->setAtom(nbr);
    setRobot();
}

void RobotWidget::set_spinbox(int value){
    ui->spinBox->setValue(value);
}
