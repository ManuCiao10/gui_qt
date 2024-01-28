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
//add thead for gettin the data
//add for loop function get_data_from_api
