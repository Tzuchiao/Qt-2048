#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>
#include <fstream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setcolor();
    setlabel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setcolor()
{
    Pal.setColor(QPalette::Background,Qt::black);
    ui->centralWidget->setAutoFillBackground(true);
    ui->centralWidget->setPalette(Pal);
}
void MainWindow::readlowestScore()
{
    QFile file("score.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream streamread(&file);
    line = streamread.readAll();
    file.close();
    ui->scorelabel->setText(line);
}
void MainWindow::writelowest(int low)
{
    QFile file("score.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream out(&file);
    out << QString::number(low);
    file.close();
    ui->scorelabel->setText(QString::number(low));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Up:
                qDebug() << "UP";
                daobj.move(1);
                break;
        case Qt::Key_Down:
                qDebug() << "Down";
                daobj.move(2);
                break;
        case Qt::Key_Left:
                qDebug() << "Left";
                daobj.move(3);
                break;
        case Qt::Key_Right:
                qDebug() << "Right";
                daobj.move(4);
                break;
        case Qt::Key_R:
                daobj.final=1;
                break;
        case Qt::Key_A:
                qDebug() <<  "A";
                break;
    }
    int count = 0;
    daobj.create();
    qDebug() << "success!";
    for(int r=0;r<4;r++)
    {
        for(int c=0;c<4;c++)
        {
              if(daobj.arr[r][c]==0)
                    labels[count]->setText("");
                else
                {
                labels[count]->setText(QString::number(daobj.arr[r][c]));
                }
            count++;
        }
    }
    ui->lcdNumber->display(daobj.score);
    qDebug() << daobj.score;
    if(daobj.final==1)
    {
        qDebug() << "You got the point!";
        ui->label_2->show();
        if(daobj.score<line.toInt())
        {
            qDebug() << "lowest score!";
            writelowest(daobj.score);
        }
    }
}

void MainWindow::setlabel()
{
    int count = 0;
    QFont font;

    ui->label_2->hide();
    font.setPointSize(36);
    font.setBold(true);
    font.setWeight(75);
    daobj.init();
    readlowestScore();
    for(int r =0;r<4;r++)
    {
        for(int c = 0;c<4;c++)
        {
            labels.append(new QLabel);
            labels[count]->setStyleSheet("QLabel{background-color:gray;color:white}");
            labels[count]->setFont(font);
            labels[count]->setAlignment(Qt::AlignCenter);
            if(daobj.arr[r][c]==0)
                labels[count]->setText("");
            else
            {
            labels[count]->setText(QString::number(daobj.arr[r][c]));
            }
            ui->gridLayout->addWidget(labels[count],r,c);
            count++;
        }
    }
    ui->gridLayoutWidget->setLayout(ui->gridLayout);


}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "click";
    ui->label_2->hide();
    daobj.init();
     ui->lcdNumber->display(daobj.score);
    int count = 0;
    for(int r=0;r<4;r++)
    {
        for(int c=0;c<4;c++)
        {
            if(daobj.arr[r][c]==0)
                  labels[count]->setText("");
              else
              {
              labels[count]->setText(QString::number(daobj.arr[r][c]));
              }
            count++;
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QApplication::quit();
}
