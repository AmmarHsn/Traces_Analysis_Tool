#include <experiment.h>
#include <robot.h>
#include <atom.h>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//GUI interface
#include <QApplication>
#include <QtWidgets>
#include "interface2.h"



using std::ifstream;
using std::getline;
using std::string;
using std::to_string;
using std::stoi;
using std::stod;
using std::istringstream;
using std::cout;
using std::endl;

vector<Experiment*>experiments;
vector<string>infoAboutExperiment;
vector<string>infoAboutAllExperiments;
int experimentLength;
int nbrStates;
int nbrExperiment = 0;

void createExperiment(int score,int timeSteps)
{
    nbrExperiment++;
    experiments.push_back(new Experiment(to_string(nbrExperiment),infoAboutExperiment, score, timeSteps));
    infoAboutExperiment.clear();
}



//--t 691 --s2 0 --c0 0 1 0.75 --a 1 --n 0 --f 0

void parseAtom(int& t, int& s, string& stateInfo,int& n,double&f, string l)
{
    istringstream ss(l);
    string word;
    while (ss >> word)
        {
            if(word.at(2)=='t'){ss>>word;t=stoi(word);}
            else if (word.at(2)=='n'){ss>>word;n=stoi(word);}
            else if (word.at(2)=='f'){ss>>word;f=stod(word);} //fct aussi avec stoi
            else if (word.at(2)=='a'){stateInfo+=word+" ";ss>>word;stateInfo+=word;}
            else if (word.at(2)=='s'){
                string state="";
                for (int i=3;i<(int)word.length();i++){state+=word.at(i);} // loop is important if the state is >= 10
                ss>>word; //do nothing with this info
                word=state;
                s=stoi(word);}
            else if (word.at(2)=='c'){
                stateInfo +=word+" ";
                ss>>word;
                stateInfo +=word+" ";
                ss>>word;
                stateInfo +=word+" ";
                ss>>word;
                stateInfo +=word+" ";
            }

        }
}

void parseExpLength(string str){
    istringstream ss(str);
    string l;
    string length;
    while (ss >> l){length=l;}
    experimentLength = stoi(length);
}

void parseNbrStates(string str){
    istringstream ss(str);
    string nbr;
    while(ss >>nbr){
        if(nbr=="--nstates"){
            ss>>nbr;
            break;
        }
    }nbrStates=stoi(nbr);
}


void testfunction()
{
    for (int i=0;i<nbrExperiment;i++){
        cout <<"Name = "+experiments.at(i)->getname() <<endl;
        cout<<"Score = "<<experiments.at(i)->getScore()<<endl;
        cout<<"nbr of robots = "<<experiments.at(i)->getRobots()<<endl;
        for(int j=0; j<experiments.at(i)->getRobots();j++){
            cout<<"NBR Atoms of Robot"<<j<<" = "<<experiments.at(i)->getRobot(j)->getNbrAtom()<<endl;
        }

    }
}


int main(int argc, char *argv[])
{
    //Openning desired file !

    QApplication app(argc,argv);                       //fsmlog
    QString fichier = QFileDialog::getOpenFileName(nullptr,"Open File","", "Files (*fsmlog)"); // searching the file with file extention control! 
    ifstream file(fichier.toStdString());
    string line;

    while (getline(file,line)){

        if(line.at(0) == '['){          //information about the experiment
            infoAboutExperiment.push_back(line);
            if(line.at(7) == 'T' && line.at(8) == 'o'){parseExpLength(line);} //Total length of experiment
        }

        else if (line.at(0)=='S'){   //Score case! -> creating an experiment
            string nbr="";
            for (int i=5; i < (int)line.length(); i++){
                nbr+=line.at(i);
            }
            createExperiment(stoi(nbr),experimentLength);
            //cout<<nbr<<endl;
        }
        else if (line.at(0) == '-' && line.at(2) == 't') {
            if(line.at(4)=='0'){experiments.back()->createRobot(experiments.back()->getRobots());}  //creating a new robot
            int t=-1,s=-1,n=-1;          // not initiate can creat problems
            string stateInfo="";
            double f=0;
            parseAtom(t, s, stateInfo, n, f, line);
            experiments.back()->getLastRobot()->createAtom(t,s,stateInfo,n,f);
            experiments.back()->getLastRobot()->setAtom(0);
        }
        else {
            if(line.at(2)=='f'){parseNbrStates(line);}
            infoAboutAllExperiments.push_back(line);  //global information or error line
        }
    }


    /*
    //testing the data structure!
    testfunction();
    */


    //Gui main menu !

    Interface2 mn(nullptr, &experiments, &infoAboutAllExperiments,nbrStates);
    mn.show();


    ////

    return app.exec();
}

