#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mymainwindow.h"
#include "mypushbutton.h"
#include "coinbutton.h"
class PlayScene : public MyMainWindow
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = 0);
    void setLevel(int level);
    int getLevel();
    void drawButton();
    void flip(int row, int col);
    int judgeWin();
protected:
    void paintEvent(QPaintEvent *event);
private:
    bool mHasWin;
    int level;
    CoinButton *mCoins[4][4];
signals:
    void backSignal();
public slots:
};

#endif // PLAYSCENE_H
