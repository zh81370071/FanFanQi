#ifndef COINBUTTON_H
#define COINBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QTimer>
class CoinButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CoinButton(QWidget *parent = 0);
    int state() const;
    void setState(int state);
    void setStateWidthAnimation(int state);
    void flip();
protected:
    void paintEvent(QPaintEvent *event);
private:
    int mState;
    int mFrame;
    QTimer mTimer;
signals:

public slots:
};

#endif // COINBUTTON_H
