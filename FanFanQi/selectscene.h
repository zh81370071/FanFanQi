#ifndef SELECTSCENE_H
#define SELECTSCENE_H

#include <QMainWindow>
#include "mymainwindow.h"
class SelectScene : public MyMainWindow
{
    Q_OBJECT
public:
    explicit SelectScene(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
signals:
    void btnBack();
public slots:
};

#endif // SELECTSCENE_H
