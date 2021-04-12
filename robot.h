#ifndef ROBOT_H
#define ROBOT_H

#include "atom.h"
#include <vector>
#include <string>

using std::string;
using std::vector;



class Robot
{
private:
    string name;
    int currentState=-1;
    int previousState=-1;
    int nextState=-1;
    int time=-1;
    double sensor=-1;
    vector<Atom*> config;
    int nbrAtom=0;
public:
    Robot(int nbr);
    //void addAtom(Atom& atom);
    void createAtom(int t, int s,int c123,int a,int n, double sens);
    void setAtom(int time);

    string getName();
    int getCurrentState();
    int getPreviousState();
    int getNextState();
    int getTime();
    double getSensorReading();
    int getNbrAtom()const;
    Atom* getAtom(int pos)const;

};

#endif // ROBOT_H

