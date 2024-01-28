#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "popupmenu.h"

#include <QJsonObject>

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
    netManager = new QNetworkAccessManager(this);
    netReply = nullptr;
    repoReply = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::panic(const std::string& msg)
{
    std::cerr << msg << std::endl;
    exit(1);
}

void MainWindow::readData()
{
    dataBuffer.assign(netReply->readAll());
    // qDebug() << dataBuffer;
}

void MainWindow::finishReading()
{
    if(netReply->error() != QNetworkReply::NoError){
        qDebug() << "Error : " << netReply->errorString();
        panic("to-implement error handling in case of failure");
        return;
    }

    //CONVERT THE DATA FROM A JSON DOC TO A JSON OBJECT
    QJsonObject respJsonInfo = QJsonDocument::fromJson(dataBuffer).object();
    QString login = respJsonInfo.value("login").toString();
    qDebug() << login;

    //assign the value to the box UI
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton_4->setStyleSheet("background-color: rgb(86, 91, 117);border-color: rgb(95, 98, 111);border-style: solid;border-width:1px;border-radius:1px;");

    save_settings(ui->pushButton_3->text(),ui->spinBox->text());

    QLabel *label = new QLabel(this);
    label->setText("successfully saved...");

    QPoint point = ui->pushButton_4->pos();
    label->move(point.x()+20,point.y()+120);
    label->resize(200,20);
    label->setStyleSheet("background-color: rgb(40, 42, 53);");
    label->show();
    QTimer::singleShot(800, label, SLOT(hide()));
}

void MainWindow::save_settings(QString city, QString bo)
{
    qDebug() << "saving settings";
    qDebug() << city;
    qDebug() << bo;

    QSettings settings("matrix","killer whale");
    settings.beginGroup("settings");

    settings.setValue("city",city);
    settings.setValue("bo",bo);

    settings.endGroup();
}

void MainWindow::read_settings()
{
    QSettings settings("matrix","killer whale");
    settings.beginGroup("settings");

    const auto city = settings.value("city").toString();
    const auto bo = settings.value("bo").toString();
    qDebug() << city;
    qDebug() << bo;

    settings.endGroup();
}


void MainWindow::on_pushButton_3_pressed()
{
    qDebug() << ui->pushButton_3->text();
    panic("to-implement");

    //get the value selected in the spinBox
}

bool FIRST_RUN = true;

void MainWindow::on_pushButton_5_clicked()
{
    if (FIRST_RUN) {
        QLabel *label = new QLabel(this);
        QPoint point = ui->widget_3->pos();

        label->setText("monitoring new houses...");
        label->move(point.x()+20,point.y()+50);
        label->resize(200,20);
        label->setStyleSheet("background-color: rgb(40, 42, 53);");
        label->show();

        FIRST_RUN = false;
    }


    auto username = "manuciao10";

    QNetworkRequest req{QUrl(QString("https://api.github.com/users/%1").arg(username))};
    netReply = netManager->get(req);
    connect(netReply,&QNetworkReply::readyRead,this,&MainWindow::readData);
    connect(netReply,&QNetworkReply::finished,this,&MainWindow::finishReading);
}

