#ifndef ROBOTINFOWIDGET_H
#define ROBOTINFOWIDGET_H

#include <QDialog>
#include "robot.h"

class RobotInfoWidget: public QDialog
{
public:
    RobotInfoWidget(Robot* Rob);

private:
    Robot* robot;
};

#endif // ROBOTINFOWIDGET_H
