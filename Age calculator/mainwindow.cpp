#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <windows.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //sets the current date using system infomation date.
    ui->setupUi(this);
    current = QDate::currentDate();
    ui->dateEdit_2->setDate(current);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //Sets the current data , if user has changed , and sets the inputted data.
    QDate date;
    QString temp;
    date = ui->dateEdit->date();
    temp = date.QDate::toString("dd.MM.yyyy");
    current = ui->dateEdit_2->date();
    //how long it takes to complete the calculation
    int howlong = 1000;
    for (int i = 0;i<=100;i++)
    {
        ui->progressBar->setValue(i);
        Sleep(howlong/100);
    }
    //365 because 365 days in a year.
    int age = date.daysTo(current) / 365;
    if (age==69)
    {
        QMessageBox::information(this,tr("69 years old"), tr("Damm.You are 69 years old.You must be a meme lord."));
    }
    //display the age
    ui->label_3->setText("You are "+QString::number(age)+" Years old");

}
