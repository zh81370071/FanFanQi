#include "mymainwindow.h"
#include "ui_mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("翻金币");
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setFixedSize(320,528);
}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}
