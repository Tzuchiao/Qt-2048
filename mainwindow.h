#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QtWidgets>
#include "data.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Data daobj;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *event);
    void setlabel();
    void setcolor();
    void readlowestScore();
    void writelowest(int low);
     QVector<QLabel*> labels;
     QLabel reslabel;
     QPalette Pal;
     QPalette labPal;
     QString line;


};

#endif // MAINWINDOW_H
