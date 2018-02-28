#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <Qlabel>
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
    void on_draw_scheme_clicked();

    void on_draw_scheme_2_clicked();

private:
    Ui::MainWindow *ui;

    QList<QLabel *> labels;
    QList<QLabel *> lines;

    QList<QLineEdit *> line_attenuation_factor;
    QList<QLabel *> label_attenuation_factor;

    QList<QLineEdit *> line_amplifier;
    QList<QLabel *> label_amplifier;

    double lenth = 0;
    int number_of_amplifier = 0;
    double fractionr_of_amplifier = 0;
    double lenth_track_amplifier = 0;

    void calculate();
    void clear_memory();
    void read_entered_data_for_build_scheme();

};

#endif // MAINWINDOW_H
