#ifndef ATOM_H
#define ATOM_H

#include <string>
using std::string;


class Atom
{
private:
    int time;
    int state;
    string stateInformation="";
    int neighbor;
    double sensorReading;

public:
    Atom(int t, int s, string stateInfo,int n, double sens);
    int getTime()const;
    int getstate()const;
    string getStateInfo()const;
    int getNeighbor()const;
    double getSensorReading()const;
};

#endif // ATOM_H
