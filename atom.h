#ifndef ATOM_H
#define ATOM_H


class Atom
{
private:
    int time;
    int state;
    int c123;    //not always
    int a;      //not always
    int neighbor;
    double sensorReading;

public:
    Atom(int t, int s,int c123,int a,int n, double sens);
    int getTime()const;
    int getstate()const;
    int getNeighbor()const;
    double getSensorReading()const;
};

#endif // ATOM_H
