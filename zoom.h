#ifndef ZOOM_H
#define ZOOM_H

#include <QDialog>
#include <vector>
#include "robotwidget.h"

namespace Ui {
class Zoom;
}

class Zoom : public QDialog
{
    Q_OBJECT

public:
    explicit Zoom(QWidget *parent = nullptr,vector<RobotWidget*>* showing_robots=nullptr);
    ~Zoom();

private:
    Ui::Zoom *ui;
    vector<RobotWidget*>* showing_robots;
    int grid_size();
    void createToolbar();

};

#endif // ZOOM_H
