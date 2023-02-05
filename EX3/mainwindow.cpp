#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_inputText_button_clicked()
{
    ui->plainTextEdit_2->setPlainText(ui->plainTextEdit->toPlainText());
}

void MainWindow::on_changeText_button_clicked()
{
    QString firstText = ui->plainTextEdit->toPlainText();
    QString secondText = ui->plainTextEdit_2->toPlainText();
    ui->plainTextEdit->setPlainText(secondText);
    ui->plainTextEdit_2->setPlainText(firstText);
}

void MainWindow::on_inputHtmlText_button_clicked()
{
    QString x = "<font color='red'>Hello</font>";
    ui->textEdit->setHtml(x);
}
