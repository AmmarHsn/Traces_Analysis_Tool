#ifndef INTERFACE2_H
#define INTERFACE2_H

#include <QMainWindow>
#include <QTreeWidget>
#include "experiment.h"
#include "robotwidget.h"
#include "colorwidget.h"

namespace Ui {
class Interface2;
}

class Interface2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface2(QWidget *parent=nullptr, vector<Experiment*>* exp_list=nullptr, vector<string>*global_info=nullptr,int nstates=0);
    ~Interface2();

public slots:
    void setRobots(QTreeWidgetItem *item);
    void setColor();


private:
    Ui::Interface2 *ui;
    vector<Experiment*>* expr_list;
    void load_expr();
    vector<RobotWidget*> showing_robots;
    void delete_showing_robots();
    vector<string>*global_info;
    int nstates;
    vector<QColor>* colors;
    ColorWidget* cw;
    bool colorfilter=false;
};

#endif // INTERFACE2_H
