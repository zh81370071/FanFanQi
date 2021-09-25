#include "mymainwindow.h"
#include <QApplication>
#include "startscene.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartScene sc;
    sc.show();

    return a.exec();
}
