#include "coinbutton.h"
#include <QPushButton>
#include <QPainter>
#include <QDebug>
CoinButton::CoinButton(QWidget *parent) : QPushButton(parent)
{
    //this->setState(0);
    this->setStyleSheet("QPushButton{border:0px;}");
    connect(&mTimer,&mTimer.timeout,[=](){
        if(this->mState == 0) {
            this->mFrame++;
        } else {
            this->mFrame--;
        }
        qDebug()<<this->mFrame<<endl;
        QString frameName = QString(":/res/Coin000%1.png").arg(this->mFrame);
        this->setIcon(QIcon(frameName));
        if(this->mFrame == 8 || this->mFrame == 1) {
            this->mTimer.stop();
        }
    });
}

int CoinButton::state() const
{
    return mState;
}

void CoinButton::setState(int state)
{
    mState = state;
    if(mState == 0) {
        this->setIcon(QIcon(":/res/Coin0008.png"));
    } else {
        this->setIcon(QIcon(":/res/Coin0001.png"));
    }
    this->setIconSize(this->size());
}

void CoinButton::setStateWidthAnimation(int state)
{
    this->mState = state;
    if(this->mState == 1) {
        this->mFrame = 8;
    } else {
        this->mFrame = 1;
    }
    this->mTimer.start(30);
}

void CoinButton::flip()
{
    //this->setState(!this->mState);
    this->setStateWidthAnimation(!this->mState);
}

void CoinButton::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/BoardNode.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //this->setIcon(QIcon(":/res/Coin0001.png"));
    QPushButton::paintEvent(event);
}
