#include "anatrixwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AnaTrixWindow w;
    w.show();
    return a.exec();
}
