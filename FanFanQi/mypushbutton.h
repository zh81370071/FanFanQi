#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QString normalImg,QString pressedImg,QWidget *parent = 0);
    explicit MyPushButton(QWidget *parent = 0);
    enum MyPushButtonState
    {
       Normal,
       Pressed,
    };
    void moveUp();
    void moveDown();
    void setImgName(QString normalImg,QString pressedImg);
protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
private:
    QString mNormalImg;
    QString mPressedImg;
    MyPushButtonState myState;
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
