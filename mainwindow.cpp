#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "popupmenu.h"
#include <QTimer>
#include <QLabel>


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


void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton_4->setStyleSheet("background-color: rgb(86, 91, 117);border-color: rgb(95, 98, 111);border-style: solid;border-width:1px;border-radius:1px;");
    qDebug() << ui->pushButton_3->text();
    qDebug() << ui->spinBox->text();

    QLabel *label = new QLabel(this);
    label->setText("successfully saved...");
    QPoint point = ui->pushButton_4->pos();
    label->move(point.x()+20,point.y()+80);
    label->resize(200,20);
    label->setStyleSheet("background-color: rgb(40, 42, 53);");
    label->show();
    QTimer::singleShot(1000, label, SLOT(hide()));

}


void MainWindow::on_pushButton_3_pressed()
{

    qDebug() << ui->pushButton_3->text();

    //get the value selected in the spinBox

}

