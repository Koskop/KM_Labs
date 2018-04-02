#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QPen>

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
    void on_pushButton_clicked();

    void on_verticalScrollBar_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    void clear_Menory();

    QList<QLabel *> aip;
    QVector<int> aip_Y;

    QList<QLabel *> app;
    QVector<int> app_Y;

    QList<QLabel *> avp;
    QVector<int> avp_Y;

    QList<QLabel *> ac_oalp;
    QVector<int> ac_oalp_Y;

    QList<QLabel *> lines;
    QVector<int> lines_Y;

    QList<QLabel *> long_line;
    QVector<int> long_line_Y;


    QLabel * go;
    int go_Y = 0;
    int tmp = 0;
};

#endif // MAINWINDOW_H
