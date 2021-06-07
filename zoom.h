#ifndef ZOOM_H
#define ZOOM_H

#include <QDialog>
#include <vector>
#include "robotwidget.h"
#include <QTimer>
#include <QSpinBox>
#include <QToolBar>
#include <QLabel>
#include <QPushButton>


namespace Ui {
class Zoom;
}

class Zoom : public QDialog
{
    Q_OBJECT

public:
    explicit Zoom(QWidget *parent = nullptr,vector<RobotWidget*>* showing_robots=nullptr);
    ~Zoom();

public slots:
    void startTimer();


private:
    Ui::Zoom *ui;
    vector<RobotWidget*>* showing_robots;
    int grid_size();
    void createToolbar();
    QSpinBox* box;
    QSpinBox* timerbox;
    QTimer* timer;
};

#endif // ZOOM_H
