#include "playscene.h"
#include <QPainter>
#include <QMenuBar>
#include "mypushbutton.h"
#include <QLabel>
#include <QDebug>
#include "coinbutton.h"
#include "dataconfig.h"
#include <QMessageBox>
#include <QLabel>
#include <QSound>
PlayScene::PlayScene(QWidget *parent) : MyMainWindow(parent)
{
    mHasWin = false;
    MyPushButton *btnBack = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png",this);
    btnBack->setText("Back");
    btnBack->resize(72,32);
    btnBack->move(this->width()-btnBack->width(),this->height()-btnBack->height());
    connect(btnBack,&btnBack->clicked,this,&this->backSignal);

}

void PlayScene::setLevel(int level)
{
    this->level = level;
    //qDebug()<<"test3"<<this->level<<endl;
}

int PlayScene::getLevel()
{
    //qDebug()<<"test4"<<this->level<<endl;
    return this->level;
}

void PlayScene::drawButton()
{
    const int colWidth = 50;
    const int rowHeight = 50;
    const int xOffset = 57;
    const int yOffset = 200;

    dataConfig data;
    QVector <QVector<int>> dataArray = data.mData[this->level];

    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 4; col++){
            int x = col * colWidth + xOffset;
            int y = row * rowHeight + yOffset;
            CoinButton *btn = new CoinButton(this);
            mCoins[row][col] = btn;
            btn->setGeometry(x,y,50,50);
            btn->setState(dataArray[row][col]);
            btn->show();
            connect(btn, &btn->clicked,[=](){
               this->flip(row, col);
               //this->judgeWin();
            });
        }
    }
}

void PlayScene::flip(int row, int col)
{
    if(this->mHasWin == true) {
        return;
    }
    QSound::play(":/res/TapButtonSound.wav");
    this->mCoins[row][col]->flip();

    QTimer::singleShot(250,[=](){
        if(row+1 < 4) {
            this->mCoins[row+1][col]->flip();
        }
        if(row>0){
            this->mCoins[row-1][col]->flip();
        }

        if(col+1 < 4) {
            this->mCoins[row][col+1]->flip();
        }
        if(col > 0) {
            this->mCoins[row][col-1]->flip();
        }
        judgeWin();
    });
}

int PlayScene::judgeWin()
{
    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 4; col++){
            if(this->mCoins[row][col]->state() == 0){
                return 0;
            }
        }
    }
    //QMessageBox::information(this,"恭喜","您已经胜利了");
    mHasWin = true;
    QLabel *labelWin = new QLabel(this);
    QPixmap pix = QPixmap(":/res/LevelCompletedDialogBg.png");
    labelWin->setPixmap(pix);
    labelWin->resize(pix.size());
    labelWin->move((this->width()-labelWin->width())/2,100);
    labelWin->show();
    QSound::play(":/res/LevelWinSound.wav");
    //return 1;
}

void PlayScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.translate(0,this->menuBar()->height());
    QPixmap pix(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap(0,0,pix);

}
