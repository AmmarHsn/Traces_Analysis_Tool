#include "robot.h"

Robot::Robot(int nbr){this->name="Robot"+std::to_string(nbr+1);}

//void Robot::addAtom(Atom& atom){this->config.push_back(&atom);}

void Robot::createAtom(int t, int s,int c123,int a,int n, double sens){this->config.push_back(new Atom(t,s,c123,a,n,sens));nbrAtom++;}

void Robot::setAtom(int time)
{
    Atom* a = this->config.at(time);
    this->currentState = a->getstate();
    this->sensor = a->getSensorReading();
    this->time = a->getTime();

 /*   if (time != 0)
    {
        a = this->config.at(time-1);
        this->previousState = a->getstate();
    }else{this->previousState = -1;}

    if(time<255)                                            //define a max value!!!
    {
        a = this->config.at(time+1);
        this->nextState = a->getstate();
    }else {this->nextState = -1;}

  */
}


//Getters
string Robot::getName(){return this->name;}
int Robot::getCurrentState(){return currentState;}
int Robot::getPreviousState(){return previousState;}
int Robot::getNextState(){return nextState;}
int Robot::getTime(){return time;}
double Robot::getSensorReading(){return sensor;}
int Robot::getNbrAtom()const{return nbrAtom;}
Atom* Robot::getAtom(int pos)const{return config.at(pos);}
