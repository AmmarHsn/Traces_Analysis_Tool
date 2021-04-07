#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include "robot.h"
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::to_string;

class Experiment
{
private:
    string name;
    int robots=0;
    int score;
    int timSteps;
    vector<Robot*>robot_list;
    static int nbrExp;        /// pas besoin !!

public:
    Experiment(string name, int score,int timeSteps);
    string getname() const;
    int getScore() const;
    int getRobots() const;
    int getTimesteps() const;
    void createRobot(int nbr);
    Robot* getRobot(int pos);
    Robot* getLastRobot();
    static void init_counter();
};

#endif // EXPERIMENT_H
