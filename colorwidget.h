#ifndef COLORWIDGET_H
#define COLORWIDGET_H

#include <QWidget>
#include <QLabel>
#include <vector>
#include "mypushboutton.h"

#include <string.h>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QColorDialog>

using std::string;
using std::to_string;
using std::vector;




namespace Ui {
class ColorWidget;
}

class ColorWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ColorWidget(QWidget *parent = nullptr, int nstates=0);
    ~ColorWidget();
    vector<QColor>* getColors();

public slots:
    void setColor(int state);

signals:
    void setColor();

private:
    Ui::ColorWidget *ui;
    int nstates;
    void designWidget();
    vector<QLabel*> stateColor;
    vector<QColor> colors;
    bool allButtonSet();
};

#endif // COLORWIDGET_H
