#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    double b = ui->input_B->text().toDouble();
    double c = ui->input_C->text().toDouble();
    double x = ui->input_X->text().toDouble();
    double a;
    if(b > 0 && c > 0 && x > 0 && x < 180)
    {
    if(ui->radioButton->isChecked())
        a = qSqrt(qPow(b,2) + qPow(c,2) - 2*b*c*qCos(x));
    else if(ui->radioButton_2->isChecked())
    {
        x = x * M_PI / 180;
        a = qSqrt(qPow(b,2) + qPow(c,2) - 2*b*c*qCos(x));
    }
    else a = NULL;

    if(a != NULL)
        QMessageBox::about(this,"Расчёт стороны треугольника", QString::number(a));
    else
        QMessageBox::about(this,"Расчёт стороны треугольника", "Вы не указали параметры угла!");
    } else
        QMessageBox::about(this,"Расчёт стороны треугольника", "Ошибка в вводе!");
}
