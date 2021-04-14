#include "mypushboutton.h"
#include <string.h>
#include <QString>


MyPushBoutton::MyPushBoutton(int state) : QPushButton()
{
    this->state = state;
    std::string name = "State";
    name+=std::to_string(state);
    this->setText(QString::fromStdString(name));
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(reemitClicked()));
}


//Slot
void MyPushBoutton::reemitClicked(){
    emit send(state);
}
