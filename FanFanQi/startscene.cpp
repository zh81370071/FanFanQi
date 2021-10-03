#include "startscene.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QTimer>
#include "selectscene.h"
#include <QDebug>
#include <QSound>
StartScene::StartScene(QWidget *parent) : MyMainWindow(parent)
{
    this->setWindowTitle("开始场景");



    MyPushButton *btnStart = new MyPushButton(":/res/MenuSceneStartButton.png",":/res/MenuSceneStartButton.png",this);
    btnStart->resize(114,114);
    btnStart->move((this->width() - btnStart->width()) / 2,(this->height() * 3 / 4 - btnStart->height() * 1 / 2));

    connect(&this->mySelectScene,&this->mySelectScene.btnBack,[=](){
        QSound::play(":/res/BackButtonSound.wav");
        this->show();
        this->mySelectScene.hide();
        this->move(this->mySelectScene.pos());
        //qDebug()<<"aaa"<<endl;
    });



    connect(btnStart, &MyPushButton::clicked,[=]{
        QSound::play(":/res/TapButtonSound.wav");
        btnStart->setEnabled(false);
        btnStart->moveDown();
        QTimer::singleShot(150,[=](){
           btnStart->moveUp();
        });
        QTimer::singleShot(300,[=](){
           btnStart->setEnabled(true);
           this->hide();
           this->mySelectScene.show();
           //移动窗口到当前位置
           this->mySelectScene.move(this->pos());
        });
    });
}
