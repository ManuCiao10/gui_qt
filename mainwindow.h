#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QTimer>
#include <QLabel>
#include <QSettings>
#include <iostream>
#include <QJsonDocument>

#include <QNetworkAccessManager>
#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void save_settings(QString city, QString bo);
    void read_settings();
    void on_pushButton_3_pressed();
    void on_pushButton_5_clicked();

    void panic(const std::string& msg);

    void readData();
    void finishReading();
private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *netManager;
    QNetworkReply *netReply;
    QNetworkReply *repoReply;
    QByteArray dataBuffer;
};
#endif // MAINWINDOW_H
