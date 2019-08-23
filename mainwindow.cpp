#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   long double a=ui->lineEdit->text().toFloat();
   long double b=ui->lineEdit_2->text().toFloat();
   long double c=ui->lineEdit_3->text().toFloat();
   long double dt=ui->lineEdit_4->text().toFloat();



   QLineSeries *series=new QLineSeries();

   for(int i=0;i<10000;i++)
   {
       double y=a+b*sin(i*0.0001*c);
       *series << QPointF(0.0001*i,y);
   }


   //создаем график и добавляем в него синусоиду
   QChart *chart=new QChart();
   chart->addSeries(series);
   chart->legend()->hide();
   chart->setTitle("Graphics");

   //настройка осей графика
   QValueAxis *axisX=new QValueAxis();
   axisX->setTitleText("t,c");
   axisX->setLabelFormat("%f");
   axisX->setTickCount(1);
   chart->addAxis(axisX,Qt::AlignBottom);
   series->attachAxis(axisX);
   //настройка осей графика
   QValueAxis *axisY=new QValueAxis();
   axisY->setTitleText("y,m");
   axisY->setLabelFormat("%i");
   axisY->setTickCount(5);
   chart->addAxis(axisY,Qt::AlignLeft);
series->attachAxis(axisY);
   //создаем представление графика


    ui->graphicsView->setChart(chart);


}
