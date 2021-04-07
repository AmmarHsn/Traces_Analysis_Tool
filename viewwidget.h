#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H


#include <QWidget>
#include <experiment.h>

class ViewWidget : public QWidget
{
public:
    ViewWidget(vector<Experiment*>* exp_list);
private:
    vector<Experiment*>*list;
};

#endif // VIEWWIDGET_H
