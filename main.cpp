#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGuiApplication::setWindowIcon( QIcon( ":/killer-whale.ico" ) );
    MainWindow w;

    w.setWindowTitle("Killer Whale");
    w.show();
    return a.exec();
}

//change all the button name
//add thead for loop function to get the data or a request every 5 minutes
//auto update
//finish the golang api
