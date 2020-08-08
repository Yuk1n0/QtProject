#include <qapplication.h>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication qApplication(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return qApplication.exec();
}
