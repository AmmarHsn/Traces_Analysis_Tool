#include "atom.h"


#include <iostream>

Atom::Atom(int t, int s,int c123,int a,int n, double sens)
{
    this->time=t;
    this->state=s;
    this->c123=c123;
    this->a=a;
    this->neighbor=n;
    this->sensorReading=sens;

}

//Getters
int Atom::getTime()const{return time;}
int Atom::getstate()const{return state;}
int Atom::getNeighbor()const{return neighbor;}
double Atom::getSensorReading()const{return sensorReading;}
