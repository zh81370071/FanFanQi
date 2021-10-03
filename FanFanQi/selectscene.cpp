#include "selectscene.h"
#include <QPushButton>
#include <QPainter>
#include <QMenuBar>
#include "mypushbutton.h"
#include "playscene.h"
#include <QDebug>
#include <QLabel>
#include "coinbutton.h"
#include <QSound>
SelectScene::SelectScene(QWidget *parent) : MyMainWindow(parent)
{
    MyPushButton *btnBack = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png",this);
    btnBack->setText("Back");
    btnBack->resize(72,32);
    connect(btnBack,&btnBack->clicked,this,&this->btnBack);

    btnBack->move(this->width()-btnBack->width(),this->height()-btnBack->height());

    MyPushButton *btnArray = new MyPushButton[20];
    const int colWidth = 70;
    const int rowHeight = 70;
    const int xOffset = 25;
    const int yOffset = 130;
    //添加20个关卡按钮
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 4; j++) {
            btnArray[i * 4 + j].setParent(this);
            btnArray[i * 4 + j].resize(57,57);
            btnArray[i * 4 + j].setImgName(":/res/LevelIcon.png",":/res/LevelIcon.png");
            btnArray[i * 4 + j].move(xOffset + j * colWidth,yOffset + i * rowHeight);
            btnArray[i * 4 + j].setText(QString::number(i * 4 + j + 1));
            connect(&btnArray[i * 4 + j],&btnArray[i * 4 + j].clicked,[=]{
                QSound::play(":/res/TapButtonSound.wav");
                PlayScene *playScene = new PlayScene;
                playScene->setAttribute(Qt::WA_DeleteOnClose);
                playScene->setLevel(i * 4 + j + 1);
                QLabel *label = new QLabel(playScene);
                //qDebug()<<"test2"<<playScene->getLevel()<<endl;
                label->setText(QString("Level:%1").arg(playScene->getLevel()));
                label->move(0,playScene->height() - label->height());
                label->setFont(QFont("华文新魏",20));
                label->resize(label->width()*2,label->height());
                qDebug()<<i * 4 + j + 1<<endl;
                playScene->move(this->pos());
                playScene->show();
                this->hide();
                connect(playScene,&playScene->backSignal,[=]{
                    playScene->hide();
                    this->show();
                    this->move(playScene->pos());
                });
                playScene->drawButton();


            });

        }
    }

}

void SelectScene::paintEvent(QPaintEvent *event)
{
    //绘制背景图片
    QPainter painter(this);
    painter.translate(0,this->menuBar()->height());
    QPixmap pix(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //QPixmap pix();
}

