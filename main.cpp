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
#include "mainwindow.h"
#include "interface2.h"
#include "viewwidget.h"




using std::ifstream;
using std::getline;
using std::string;
using std::to_string;
using std::stoi;
using std::stod;
using std::istringstream;
using std::cout;
using std::endl;

vector<Experiment*>exp_list;
vector<string>exp_info;
vector<string>global_info;
int exp_length;
int nstates;
int nbrExperiment = 0;

void createExperiment(int score,int timeSteps)
{
    nbrExperiment++;
    exp_list.push_back(new Experiment(to_string(nbrExperiment),exp_info, score, timeSteps));
    exp_info.clear();
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
    exp_length = stoi(length);
}

void parseNbrStates(string str){
    istringstream ss(str);
    string nbr;
    while(ss >>nbr){
        if(nbr=="--nstates"){
            ss>>nbr;
            break;
        }
    }nstates=stoi(nbr);
}


void testfunction()
{
    for (int i=0;i<nbrExperiment;i++){
        cout <<"Name = "+exp_list.at(i)->getname() <<endl;
        cout<<"Score = "<<exp_list.at(i)->getScore()<<endl;
        cout<<"nbr of robots = "<<exp_list.at(i)->getRobots()<<endl;
        for(int j=0; j<exp_list.at(i)->getRobots();j++){
            cout<<"NBR Atoms of Robot"<<j<<" = "<<exp_list.at(i)->getRobot(j)->getNbrAtom()<<endl;
        }

    }
}


int main(int argc, char *argv[])
{
    //Openning desired file !

    QApplication app(argc,argv);                       //fsmlog
    QString fichier = QFileDialog::getOpenFileName(nullptr,"Open File","", "Files (*fsmlog)"); // searching the file with file extention control!
    //QSize screen_size = app.screens()[0]->size();


    ifstream file(fichier.toStdString());
    //ifstream file("/Users/ammar/Desktop/PROJ-H402/Traces_Analysis_Tool/test2.txt");
    string line;

    while (getline(file,line)){
        //getline(file,line);

        if(line.at(0) == '['){          //information about the experiment
            exp_info.push_back(line);
            if(line.at(7) == 'T' && line.at(8) == 'o'){parseExpLength(line);} //Total length of experiment
        }

        else if (line.at(0)=='S'){   //Score case! -> creating an experiment
            string nbr="";
            for (int i=5; i < (int)line.length(); i++){
                nbr+=line.at(i);
            }
            createExperiment(stoi(nbr),exp_length);
            //cout<<nbr<<endl;
        }
        else if (line.at(0) == '-' && line.at(2) == 't') {
            if(line.at(4)=='0'){exp_list.back()->createRobot(exp_list.back()->getRobots());}  //creating a new robot can also do with the t below
            int t=-1,s=-1,n=-1;          // not initiate can creat problems
            string stateInfo="";
            double f=0;
            parseAtom(t, s, stateInfo, n, f, line);
            exp_list.back()->getLastRobot()->createAtom(t,s,stateInfo,n,f);
            exp_list.back()->getLastRobot()->setAtom(0);
        }
        else {
            if(line.at(2)=='f'){parseNbrStates(line);}
            global_info.push_back(line);  //global information or error line
        }
    }


    /*
    //testing the data structure!
    testfunction();
    */


    //Gui main menu !

    Interface2 mn(nullptr, &exp_list, &global_info,nstates);
    mn.show();



/*
    //SIMPLE GUI
    ViewWidget vieuw(&global_info,&exp_list);
    vieuw.show();
*/
    ////

    return app.exec();
    return 0;
}

