#include "mypushbutton.h"
#include <QPainter>
#include <QPropertyAnimation>
MyPushButton::MyPushButton(QString normalImg, QString pressedImg, QWidget *parent)
    : QPushButton(parent)
    ,mNormalImg(normalImg)
    ,mPressedImg(pressedImg)
{
    this->myState = Normal;
}

MyPushButton::MyPushButton(QWidget *parent): QPushButton(parent)
{
    this->myState = Normal;
}


void MyPushButton::moveUp()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
    animation->setDuration(100);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::moveDown()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setDuration(100);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::setImgName(QString normalImg, QString pressedImg)
{
    this->mNormalImg = normalImg;
    this->mPressedImg = pressedImg;
}

void MyPushButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;

    if(this->myState == Normal) {
        pix.load(this->mNormalImg);
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
    } else {
        pix.load(this->mPressedImg);
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
    }
    painter.drawText(0,0,this->width(),this->height(),Qt::AlignCenter|Qt::AlignVCenter,this->text());
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    this->myState = Pressed;
    update();
    QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    this->myState = Normal;
    QPushButton::mouseReleaseEvent(e);
}
