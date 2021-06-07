#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H


#include <experiment.h>
#include <QWidget>
#include <QVBoxLayout>
#include <QTreeView>
#include <QStandardItemModel>
#include <QListView>
#include <string>
#include <QString>



class ViewWidget : public QWidget
{
public:
    ViewWidget(vector<string>* glb,vector<Experiment*>* exp_list);
private:
    vector<Experiment*>*list;
};

#endif // VIEWWIDGET_H
