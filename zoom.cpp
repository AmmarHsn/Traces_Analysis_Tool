#include "zoom.h"
#include "ui_zoom.h"




Zoom::Zoom(QWidget *parent, vector<RobotWidget*>* showing_robots) :
    QDialog(parent),
    ui(new Ui::Zoom)
{
    ui->setupUi(this);
    this->showFullScreen();
    this->showing_robots=showing_robots;
    this->timer = new QTimer;
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(startTimer()));


    createToolbar();

    int maxcol = grid_size();
    int row=0;
    int col=0;

    for (int i=0;i<(int)showing_robots->size();i++) {
        if(col<maxcol){ui->gridLayout_2->addWidget(showing_robots->at(i),row,col);col++;}
        else{col=0;row++,ui->gridLayout_2->addWidget(showing_robots->at(i),row,col);col++;}
    }
    this->exec();
}

Zoom::~Zoom()
{
    delete ui;
}


int Zoom::grid_size(){
    QSize total_width =ui->scrollArea->size();
    QSize rob = showing_robots->at(0)->minimumSize();
    int factor = (int) total_width.width()/rob.width();
    return factor;
}

void Zoom::createToolbar(){

    QLabel* timerms = new QLabel("Timer in ms :");
    timerbox = new QSpinBox;
    timerbox->setMaximum(1000000); //A verifier
    QPushButton* start = new QPushButton("Start");
    QObject::connect(start,SIGNAL(clicked()),this,SLOT(startTimer()));
    QPushButton* stop = new QPushButton("Stop");
    QObject::connect(stop,SIGNAL(clicked()),timer,SLOT(stop()));

    QLabel* lab = new QLabel("Time :");
    box = new QSpinBox;
    QSlider* slider = new QSlider(Qt::Horizontal);
    int nbrRobot = (int)showing_robots->size();
    if(nbrRobot!=0){
        int max =showing_robots->at(0)->getRobot()->getNbrAtom()-1;
        box->setMaximum(max);
        slider->setMaximum(max);
        //connecting Signals and slots
        QObject::connect(slider,SIGNAL(valueChanged(int)),box,SLOT(setValue(int)));
        QObject::connect(box,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
        for (int i=0;i<nbrRobot;i++) {QObject::connect(box,SIGNAL(valueChanged(int)),showing_robots->at(i),SLOT(set_spinbox(int)));}
    }

    QToolBar* bar=new QToolBar(this);
    //Timer
    bar->addWidget(timerms);
    bar->addWidget(timerbox);
    bar->addWidget(start);
    bar->addWidget(stop);

    //Filter
    bar->addWidget(lab);
    bar->addWidget(box);
    bar->addWidget(slider);
    ui->verticalLayout->addWidget(bar);
}


//slots

void Zoom::startTimer(){
    int val = box->value();
    if(val<box->maximum()){box->setValue(val+1);timer->start(timerbox->value());}
}

