#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLogValueAxis>
#include <QLineSeries>
#include <QValueAxis>
#include <QChart>
#include <QChartView>
#include <math.h>
#include <thread>
#include <chrono>
#include <mutex>
using namespace QtCharts;
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    //функции,хранящие значения A,B,C
    double threatA();
    double threatB();
    double threatC();
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

};

struct Sinus
{
    double a;
    double b;
    double c;

    double getA();
    double getB();
    double getC();
};

#endif // MAINWINDOW_H
