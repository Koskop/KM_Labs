#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDoubleValidator>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDoubleValidator* validator_entered_lenth =  new QDoubleValidator( 0, 1500.0, 2 );
    validator_entered_lenth->setNotation(QDoubleValidator::StandardNotation);
    ui->entered_lenth->setValidator(validator_entered_lenth);

    QIntValidator* validator_number_of_amplifier =  new QIntValidator( 0, 9);
    ui->entered_number_of_amplifier->setValidator(validator_number_of_amplifier);

    QDoubleValidator* validator_fractionr_of_amplifier =  new QDoubleValidator( 0, 1, 2 );
    validator_fractionr_of_amplifier->setNotation(QDoubleValidator::StandardNotation);
    ui->entered_fractionr_of_amplifier->setValidator(validator_fractionr_of_amplifier);

    ui->entered_lenth->setText("79");
    ui->entered_number_of_amplifier->setText("3");
    ui->entered_fractionr_of_amplifier->setText("0");
    ui->resault->setReadOnly(true);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_draw_scheme_clicked()
{
    for(int i = 0; i < this->labels.size(); i++){
        labels.at(i)->clear();
    }
    for(int i = 0; i < this->lines.size(); i++){
        lines.at(i)->clear();
    }
    this->lenth = ui->entered_lenth->text().toDouble();
    this->number_of_amplifier = ui->entered_number_of_amplifier->text().toInt();
    this->fractionr_of_amplifier = ui->entered_fractionr_of_amplifier->text().toDouble();

    QDoubleValidator* validator_double =  new QDoubleValidator( -1000.0, 1000.0, 2 );
    validator_double->setNotation(QDoubleValidator::StandardNotation);

    this->labels << new QLabel(this);
    this->labels.at(0)->setPixmap(QPixmap(":/res/main_a.png"));
    this->labels.at(0)->setGeometry(30, 150, QPixmap(":/res/main_a.png").width(), QPixmap(":/res/main_a.png").height());
    this->labels.at(0)->show();

    this->lines << new QLabel(this);
    this->lines.at(0)->setPixmap(QPixmap(":/res/line.png"));
    this->lines.at(0)->setGeometry(30 + QPixmap(":/res/main_a.png").width(), 200, QPixmap(":/res/line.png").width(), QPixmap(":/res/line.png").height());
    this->lines.at(0)->show();

    this->label_amplifier << new QLabel(this);
    this->label_amplifier.at(0)->move(this->labels.at(0)->geometry().right() + 40, 165);
    this->label_amplifier.at(0)->setText("S0");
    this->label_amplifier.at(0)->show();

    this->line_amplifier << new QLineEdit(this);
    this->line_amplifier.at(0)->setGeometry(this->labels.at(0)->geometry().right() + 10, 145, 80, 20);
    this->line_amplifier.at(0)->setValidator(validator_double);
    this->line_amplifier.at(0)->show();


    this->label_attenuation_factor << new QLabel(this);
    this->label_attenuation_factor.at(0)->move(this->labels.at(0)->geometry().right() + 40, 205);
    this->label_attenuation_factor.at(0)->setText("a0");
    this->label_attenuation_factor.at(0)->show();

    this->line_attenuation_factor << new QLineEdit(this);
    this->line_attenuation_factor.at(0)->setGeometry(this->labels.at(0)->geometry().right() + 10, 235, 80, 20);
    this->line_attenuation_factor.at(0)->setValidator(validator_double);
    this->line_attenuation_factor.at(0)->show();

    if(this->number_of_amplifier == 0){
        this->labels << new QLabel(this);
        this->labels.at(1)->setPixmap(QPixmap(":/res/main_b.png"));
        this->labels.at(1)->setGeometry(this->lines.at(0)->geometry().right(), 150, QPixmap(":/res/main_b.png").width(), QPixmap(":/res/main_b.png").height());
        this->labels.at(1)->show();
    }
    else{
        for(int i = 1; i < this->number_of_amplifier + 1; i++){
            if(i == this->number_of_amplifier){
                this->labels << new QLabel(this);
                this->labels.at(i)->setPixmap(QPixmap(":/res/PS.png"));
                this->labels.at(i)->setGeometry(this->lines.at(i-1)->geometry().right(), 175, QPixmap(":/res/PS.png").width(), QPixmap(":/res/PS.png").height());
                this->labels.at(i)->show();

                this->label_amplifier << new QLabel(this);
                this->label_amplifier.at(i)->move(this->labels.at(i)->geometry().right() + 40, 165);
                this->label_amplifier.at(i)->setText("S"+ QString::number(i));
                this->label_amplifier.at(i)->show();

                this->line_amplifier << new QLineEdit(this);
                this->line_amplifier.at(i)->setGeometry(this->labels.at(i)->geometry().right() + 10, 145, 80, 20);
                this->line_amplifier.at(i)->setValidator(validator_double);
                this->line_amplifier.at(i)->show();

                this->label_attenuation_factor << new QLabel(this);
                this->label_attenuation_factor.at(i)->move(this->labels.at(i)->geometry().right() + 40, 205);
                this->label_attenuation_factor.at(i)->setText("a"+ QString::number(i));
                this->label_attenuation_factor.at(i)->show();

                this->line_attenuation_factor << new QLineEdit(this);
                this->line_attenuation_factor.at(i)->setGeometry(this->labels.at(i)->geometry().right() + 10, 235, 80, 20);
                this->line_attenuation_factor.at(i)->setValidator(validator_double);
                this->line_attenuation_factor.at(i)->show();

                this->lines << new QLabel(this);
                this->lines.at(i)->setPixmap(QPixmap(":/res/line.png"));
                this->lines.at(i)->setGeometry(this->labels.at(i)->geometry().right(), 200, QPixmap(":/res/line.png").width(), QPixmap(":/res/line.png").height());
                this->lines.at(i)->show();

                this->labels << new QLabel(this);
                this->labels.at(i+1)->setPixmap(QPixmap(":/res/main_b.png"));
                this->labels.at(i+1)->setGeometry(this->lines.at(i)->geometry().right(), 150, QPixmap(":/res/main_b.png").width(), QPixmap(":/res/main_b.png").height());
                this->labels.at(i+1)->show();
            }
            else
            {
                this->labels << new QLabel(this);
                this->labels.at(i)->setPixmap(QPixmap(":/res/PS.png"));
                this->labels.at(i)->setGeometry(this->lines.at(i-1)->geometry().right(), 175, QPixmap(":/res/PS.png").width(), QPixmap(":/res/PS.png").height());
                this->labels.at(i)->show();

                this->label_amplifier << new QLabel(this);
                this->label_amplifier.at(i)->move(this->labels.at(i)->geometry().right() + 40, 165);
                this->label_amplifier.at(i)->setText("S"+ QString::number(i));
                this->label_amplifier.at(i)->show();

                this->line_amplifier << new QLineEdit(this);
                this->line_amplifier.at(i)->setGeometry(this->labels.at(i)->geometry().right() + 10, 145, 80, 20);
                this->line_amplifier.at(i)->setValidator(validator_double);
                this->line_amplifier.at(i)->show();

                this->label_attenuation_factor << new QLabel(this);
                this->label_attenuation_factor.at(i)->move(this->labels.at(i)->geometry().right() + 40, 205);
                this->label_attenuation_factor.at(i)->setText("a"+ QString::number(i));
                this->label_attenuation_factor.at(i)->show();

                this->line_attenuation_factor << new QLineEdit(this);
                this->line_attenuation_factor.at(i)->setGeometry(this->labels.at(i)->geometry().right() + 10, 235, 80, 20);
                this->line_attenuation_factor.at(i)->setValidator(validator_double);
                this->line_attenuation_factor.at(i)->show();

                this->lines << new QLabel(this);
                this->lines.at(i)->setPixmap(QPixmap(":/res/line.png"));
                this->lines.at(i)->setGeometry(this->labels.at(i)->geometry().right(), 200, QPixmap(":/res/line.png").width(), QPixmap(":/res/line.png").height());
                this->lines.at(i)->show();
            }
        }
    }
    return;
}

void MainWindow::on_draw_scheme_2_clicked()
{
    this->calculate();
    return;
}

void MainWindow::calculate(){
    ui->resault->clear();
    QString tmpstr = "Загальна довжина лінії СП: " + QString::number(this->lenth) + " Кілометрів" + "\n"
            + "Кількість підсилюючих ділянок: " + QString::number(this->number_of_amplifier + 1) + "\n"
            + "Довжина ланки між підсилювачами: " + QString::number(this->lenth/(this->number_of_amplifier + 1)) + " Кілометрів" + "\n";


    for(int i = 0; i < (this->number_of_amplifier + 1); i++){
        tmpstr += "Втрати ділянки " + QString::number(i)+ ": " + QString::number(this->label_amplifier.at(i)->text().toDouble() * (this->lenth/(this->number_of_amplifier + 1))) + "\n";
    }
    ui->resault->setText(tmpstr);
    return;
}
