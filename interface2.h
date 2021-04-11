#ifndef INTERFACE2_H
#define INTERFACE2_H

#include <QMainWindow>
#include <QTreeWidget>
#include "experiment.h"

namespace Ui {
class Interface2;
}

class Interface2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface2(QWidget *parent = nullptr, vector<Experiment*>* exp_list= nullptr);
    ~Interface2();

public slots:
    void setRobots(QTreeWidgetItem *item);


private:
    Ui::Interface2 *ui;
    vector<Experiment*>* expr_list;
    void load_expr();
};

#endif // INTERFACE2_H
