#include "atom.h"


Atom::Atom(int t, int s, string stateInfo,int n, double sens)
{
    this->time=t;
    this->state=s;
    this->stateInformation=stateInfo;
    this->neighbor=n;
    this->sensorReading=sens;

}

//Getters
int Atom::getTime()const{return time;}
int Atom::getstate()const{return state;}
string Atom::getStateInfo()const{return stateInformation;}
int Atom::getNeighbor()const{return neighbor;}
double Atom::getSensorReading()const{return sensorReading;}
