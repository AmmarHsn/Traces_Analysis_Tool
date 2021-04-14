#ifndef MYPUSHBOUTTON_H
#define MYPUSHBOUTTON_H

#include <QPushButton>

class MyPushBoutton : public QPushButton
{
    Q_OBJECT
public:
    MyPushBoutton(int state);

public slots:
    void reemitClicked();

signals:
    void send(int state);

private:
    int state;
};

#endif // MYPUSHBOUTTON_H
