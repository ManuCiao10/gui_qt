#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "popupmenu.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    setFixedSize(1070,622);
    ui->setupUi(this);
    PopupMenu* menu = new PopupMenu(ui->pushButton_3,this);
    menu ->addAction("Florence");
    menu ->addAction("Rome");
    ui->pushButton_3->setMenu(menu);

}

MainWindow::~MainWindow()
{
    delete ui;
}



