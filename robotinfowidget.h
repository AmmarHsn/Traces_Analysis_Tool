#ifndef ROBOTINFOWIDGET_H
#define ROBOTINFOWIDGET_H

#include <QDialog>
#include "robot.h"
#include <QVBoxLayout>
#include <QTreeView>
#include <QStandardItemModel>
#include <QListView>
#include <string>
#include <QString>

using std::to_string;



class RobotInfoWidget: public QDialog
{
public:
    RobotInfoWidget(Robot* Rob);

private:
    Robot* robot;
};

#endif // ROBOTINFOWIDGET_H
