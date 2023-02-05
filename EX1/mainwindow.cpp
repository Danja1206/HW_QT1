#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Решение квадратных уравнений");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double a = ui->input_A->text().toDouble();
    double b = ui->input_B->text().toDouble();
    double c = ui->input_C->text().toDouble();
    double D = qPow(b, 2) - 4 * a * c;
    double x1,x2;
    QString outputString;
    if(D >= 0)
    {
     x1 = (-b + qSqrt(D))/(2*a);
     x2 = (-b - qSqrt(D))/(2*a);
     outputString = "x1 = " + QString::number(x1) + "\n" + "x2 = " + QString::number(x2);
    }
    else
    {
        x1 = -b/(2 * a );
        x2=sqrt ( fabs (D) ) /(2 * a );
        if ( x2>=0)
            outputString = "x1 = " +QString::number(x1) + " + " +QString::number(x2) + " i" + "\n" + "x2 = " +QString::number(x1) + " - " +QString::number(x2) + " i";
        else
            outputString = "x1 = " +QString::number(x1) + " - " +QString::number(abs ( x2 )) + " i" + "\n" + "x2 = " +QString::number(x1) + " + " +QString::number(abs ( x2 )) + " i";
    }
    QMessageBox::about(this,"Ответ",outputString);


}
