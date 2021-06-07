#ifndef ROBOTWIDGET_H
#define ROBOTWIDGET_H

#include <QWidget>
#include "robot.h"
#include "robotinfowidget.h"

namespace Ui {
class RobotWidget;
}

class RobotWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RobotWidget(QWidget *parent = nullptr,Robot* rob=nullptr);
    ~RobotWidget();
    void setColor(vector<QColor>* colors);
    Robot* getRobot();

public slots:
    void refresh_info(int nbr);
    void set_spinbox(int value);

protected:
    void mouseDoubleClickEvent(QMouseEvent* event)
    {
        new RobotInfoWidget(robot);
    }

private:
    Ui::RobotWidget *ui;
    Robot* robot;
    void setRobot();
    vector<QColor>* colors;
    bool colorfilter=false;

};

#endif // ROBOTWIDGET_H
