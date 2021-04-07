#include "experiment.h"

Experiment::Experiment(string name, int score,int timeSteps)
{
    this->name="Experiment "+name;
    //this->robots=nbrRobots;
    this->score=score;
    this->timSteps=timeSteps;
}

void Experiment::createRobot(int nbr)
{
    this->robot_list.push_back(new Robot(nbr));
    this->robots++;
}

Robot* Experiment::getRobot(int pos){return robot_list.at(pos);}
Robot* Experiment::getLastRobot(){return robot_list.back();}

//void Experiment::init_counter(){nbrExp=0;} //pas besoin !!

//Getters
string Experiment::getname() const{return name;}
int Experiment::getScore() const{return score;}
int Experiment::getRobots()const{return this->robots;}
int Experiment::getTimesteps() const{return timSteps;}
