#include <winsock2.h>
#include <iostream>

#include "paper2.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Paper2 w;
    w.show();
    a.exec();
    return 0;
}
