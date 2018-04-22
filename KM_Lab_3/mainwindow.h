#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QVector>
#include <QLabel>
#include <QPixmap>
#include <QPainter>

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
    void on_horizontalSlider_sliderMoved(int position);

    void on_toolButtonPlus_clicked();

    void on_toolButtonMinus_clicked();
    void on_numberLine_textChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_verticalScrollBar_sliderMoved(int position);

    void on_horizontalScrollBar_sliderMoved(int position);

private:
    Ui::MainWindow *ui;

    void synchronization();

    void check_the_condition();

    void setVerticalScrollBarRange();
    void setHorizontalScrollBarRange();

    QList<QLabel *> vertical_triangle;
    QVector<int> vertical_triangle_coords_Y;
    QVector<int> vertical_triangle_coords_X;

    QList<QLabel *> horyzontal_triangle;
    QVector<int> horyzontal_triangle_coords_Y;
    QVector<int> horyzontal_triangle_coords_X;

    QList<QLabel *> lines;
    QVector<int> lines_coords_Y;
    QVector<int> lines_coords_X;

    QList<QLabel *> rl;
    QVector<int> rl_coords_Y;
    QVector<int> rl_coords_X;

};

#endif // MAINWINDOW_H
