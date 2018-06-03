#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QList>
#include <QVector>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_BtnDraw_clicked();

    void on_BtnClear_clicked();

    void on_BtnCalc_clicked();

    void on_horizontalScrollBar_sliderMoved(int position);

private:
    void clearMemory();
    void clearCalculateMemory();

    Ui::MainWindow *ui;

    QList<QLabel *> elements;
    QVector<int> elements_x;

    QList<QLabel *> lines;
    QVector<int> lines_x;

    QList<QLabel *> Sn_Label;
    QList<QLineEdit *> Sn_Line;
    QVector<int> Sn_Label_x;
    QVector<int> Sn_Line_x;

    QList<QLabel *> An_Label;
    QList<QLineEdit *> An_Line;
    QVector<int> An_Label_x;
    QVector<int> An_Line_x;

    QList<QLabel *> calculatesData;
    QVector<int> calculatesData_x;

    QVector<double> calcLenth;
    QVector<double> calcData;

};

#endif // MAINWINDOW_H
