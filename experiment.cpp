#include "experiment.h"

Experiment::Experiment(string name, vector<string> info,int score,int timeSteps)
{
    this->name="Experiment "+name;
    this->information=info;
    this->score=score;
    this->timSteps=timeSteps;
}

void Experiment::createRobot(int nbr)
{
    this->robot_list.push_back(new Robot(nbr));
    this->robots++;
}


//Getters
string Experiment::getname() const{return name;}
vector<string>* Experiment::getinformation() {return &information;}
int Experiment::getScore() const{return score;}
int Experiment::getRobots()const{return this->robots;}
int Experiment::getTimesteps() const{return timSteps;}
Robot* Experiment::getRobot(int pos){return robot_list.at(pos);}
Robot* Experiment::getLastRobot(){return robot_list.back();}
