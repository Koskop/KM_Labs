#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->BtnCalc->setDisabled(true);
    ui->horizontalScrollBar->setRange(0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnDraw_clicked()
{
    this->clearMemory();
    if(1) // draw elements
    {
        {
            QPixmap tmp(100,100); // ширина, висота
            tmp.fill(QColor(0,0,0,0));
            QPainter painter(&tmp);
            QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 5 );
            painter.setPen(pen);
            QFont f("Myriad Pro", 20);
            f.setBold(true);
            painter.setFont(f);
            QTextOption textOption;
            textOption.setAlignment(Qt::AlignCenter);
            painter.drawText(QRectF(0,0,100,100), "ОС",textOption);
            pen.setColor(Qt::black);
            painter.setPen(pen);
            painter.drawLine(2.5, 2.5, 97.5, 2.5);
            painter.drawLine(2.5, 2.5, 2.5, 97.5);
            painter.drawLine(97.5, 2.5, 97.5, 97.5);
            painter.drawLine(2.5, 97.5, 97.5, 97.5);

            this->elements << new QLabel(ui->scrollAreaWidgetContents);
            this->elements.last()->setPixmap(tmp);
            this->elements.last()->move(50, 50);
            this->elements.last()->show();
            this->elements_x << this->elements.last()->geometry().x();
        }
        for(int i = 0; i < ui->NumberZoneAmplifier->text().toInt()-1; i++)
        {
            QPixmap tmp(100,100); // ширина, висота
            tmp.fill(QColor(0,0,0,0));
            QPainter painter(&tmp);
            QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 5 );
            painter.setPen(pen);
            QFont f("Myriad Pro", 20);
            f.setBold(true);
            painter.setFont(f);
            QTextOption textOption;
            textOption.setAlignment(Qt::AlignCenter);
            painter.drawText(QRectF(0,0,100,100), "УП" + QString::number(i+1), textOption);
            pen.setColor(Qt::black);
            painter.setPen(pen);
            painter.drawLine(2.5, 2.5, 97.5, 2.5);
            painter.drawLine(2.5, 2.5, 2.5, 97.5);
            painter.drawLine(97.5, 2.5, 97.5, 97.5);
            painter.drawLine(2.5, 97.5, 97.5, 97.5);

            this->elements << new QLabel(ui->scrollAreaWidgetContents);
            this->elements.last()->setPixmap(tmp);
            this->elements.last()->move(250+200*i, 50);
            this->elements.last()->show();
            this->elements_x << this->elements.last()->geometry().x();
        }
        {
            QPixmap tmp(100,100); // ширина, висота
            tmp.fill(QColor(0,0,0,0));
            QPainter painter(&tmp);
            QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 5 );
            painter.setPen(pen);
            QFont f("Myriad Pro", 20);
            f.setBold(true);
            painter.setFont(f);
            QTextOption textOption;
            textOption.setAlignment(Qt::AlignCenter);
            painter.drawText(QRectF(0,0,100,100), "ОС",textOption);
            pen.setColor(Qt::black);
            painter.setPen(pen);
            painter.drawLine(2.5, 2.5, 97.5, 2.5);
            painter.drawLine(2.5, 2.5, 2.5, 97.5);
            painter.drawLine(97.5, 2.5, 97.5, 97.5);
            painter.drawLine(2.5, 97.5, 97.5, 97.5);

            this->elements << new QLabel(ui->scrollAreaWidgetContents);
            this->elements.last()->setPixmap(tmp);
            this->elements.last()->move(this->elements_x.last() + 200, 50);
            this->elements.last()->show();
            this->elements_x << this->elements.last()->geometry().x();
        }

        if(elements_x.last()+100 > 850)
            ui->horizontalScrollBar->setRange(0,elements_x.last()-800);
    }
    if(1) // draw lines
    {
        for(int i = 0; i < ui->NumberZoneAmplifier->text().toInt(); i++)
        {
            {
                QPixmap tmp(100,5); // ширина, висота
                tmp.fill(QColor(0,0,0,255));

                this->lines << new QLabel(ui->scrollAreaWidgetContents);
                this->lines.last()->setPixmap(tmp);
                this->lines.last()->move(this->elements_x.at(i)+100, 99.5);
                this->lines.last()->show();
                this->lines_x << this->lines.last()->geometry().x();
            }
            {
                QPixmap tmp(5,400); // ширина, висота
                tmp.fill(QColor(0,0,0,255));

                this->lines << new QLabel(ui->scrollAreaWidgetContents);
                this->lines.last()->setPixmap(tmp);
                this->lines.last()->move(this->elements_x.at(i)+100-5, 99.5);
                this->lines.last()->show();
                this->lines_x << this->lines.last()->geometry().x();
            }
            {
                QPixmap tmp(5,400); // ширина, висота
                tmp.fill(QColor(0,0,0,255));

                this->lines << new QLabel(ui->scrollAreaWidgetContents);
                this->lines.last()->setPixmap(tmp);
                this->lines.last()->move(this->elements_x.at(i+1), 99.5);
                this->lines.last()->show();
                this->lines_x << this->lines.last()->geometry().x();
            }
        }
        for(int i = 0; i < ui->NumberZoneAmplifier->text().toInt()-1; i++)
        {
            {
                QPixmap tmp(100,200); // ширина, висота
                tmp.fill(QColor(0,0,0,0));
                QPainter painter(&tmp);
                QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 5 );
                painter.setPen(pen);
                pen.setColor(Qt::black);
                painter.setPen(pen);
                painter.drawLine(0, 200, 100, 0);

                this->lines << new QLabel(ui->scrollAreaWidgetContents);
                this->lines.last()->setPixmap(tmp);
                this->lines.last()->move(this->elements_x.at(i+1), 250);
                this->lines.last()->show();
                this->lines_x << this->lines.last()->geometry().x();
            }
        }
        for(int i = 0; i < ui->NumberZoneAmplifier->text().toInt(); i++)
        {
            QPixmap tmp(110,200); // ширина, висота
            tmp.fill(QColor(0,0,0,0));
            QPainter painter(&tmp);
            QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 5 );
            painter.setPen(pen);
            pen.setColor(Qt::black);
            painter.setPen(pen);
            painter.drawLine(2.5, 2.5, 110, 200);

            this->lines << new QLabel(ui->scrollAreaWidgetContents);
            this->lines.last()->setPixmap(tmp);
            this->lines.last()->move(this->elements_x.at(i)+95, 250);
            this->lines.last()->show();
            this->lines_x << this->lines.last()->geometry().x();
        }
    }
    if(1) // draw Sn:
    {
        for(int i = 0; i < ui->NumberZoneAmplifier->text().toInt()-1; i++)
        {
            this->Sn_Label << new QLabel(ui->scrollAreaWidgetContents);
            this->Sn_Label.last()->setText("S" + QString::number(i+1) + ":");
            this->Sn_Label.last()->move(this->elements_x.at(i+1), 25);
            this->Sn_Label.last()->show();
            this->Sn_Label_x << this->Sn_Label.last()->geometry().x();

            this->Sn_Line << new QLineEdit(ui->scrollAreaWidgetContents);
            this->Sn_Line.last()->setFixedSize(60, 25);
            this->Sn_Line.last()->move(this->elements_x.at(i+1)+37, 25);
            this->Sn_Line.last()->show();
            this->Sn_Line_x << this->Sn_Line.last()->geometry().x();
        }
    }
    if(1) // draw An:
    {
        for(int i = 0; i < ui->NumberZoneAmplifier->text().toInt(); i++)
        {
            this->An_Label << new QLabel(ui->scrollAreaWidgetContents);
            this->An_Label.last()->setText("а" + QString::number(i+1)+ ":");
            this->An_Label.last()->move(this->elements_x.at(i)+100, 70);
            this->An_Label.last()->show();
            this->An_Label_x << this->An_Label.last()->geometry().x();

            this->An_Line << new QLineEdit(ui->scrollAreaWidgetContents);
            this->An_Line.last()->setFixedSize(60, 25);
            this->An_Line.last()->move(this->elements_x.at(i)+137, 70);
            this->An_Line.last()->show();
            this->An_Line_x << this->An_Line.last()->geometry().x();
        }
    }
    ui->BtnCalc->setDisabled(false);
}

void MainWindow::on_BtnClear_clicked()
{
    this->clearMemory();
}

void MainWindow::on_BtnCalc_clicked()
{
    this->clearCalculateMemory();
    for(int i = 0; i < ui->NumberZoneAmplifier->text().toInt(); i++)
    {
        this->calculatesData << new QLabel(ui->scrollAreaWidgetContents);
        this->calcLenth << (ui->Lenth->text().toDouble()/ui->NumberZoneAmplifier->text().toInt())*this->An_Line.at(i)->text().toDouble();
        this->calculatesData.last()->setText(QString::number(calcLenth.last()));
        this->calculatesData.last()->move(this->elements_x.at(i)+110, 110);
        this->calculatesData.last()->show();
        this->calculatesData_x << this->calculatesData.last()->geometry().x();
    }

    {
        this->calcData << ui->StartLevel->text().toDouble();
        QPixmap tmp(100,20); // ширина, висота
        tmp.fill(QColor(255, 255, 255, 255));
        QPainter painter(&tmp);
        QPen pen(QBrush (QColor(0, 0, 0, 255), Qt::SolidPattern), 5 );
        painter.setPen(pen);
        QFont f("Myriad Pro", 14);
        f.setBold(true);
        painter.setFont(f);
        QTextOption textOption;
        textOption.setAlignment(Qt::AlignCenter);
        painter.drawText(QRectF(0,0,100,20), QString::number(calcData.last()),textOption);

        this->calculatesData << new QLabel(ui->scrollAreaWidgetContents);
        this->calculatesData.last()->setPixmap(tmp);
        this->calculatesData.last()->move(this->elements_x.at(0)+50, 230);
        this->calculatesData.last()->show();
        this->calculatesData_x << this->calculatesData.last()->geometry().x();
    }
    for(int i = 0; i < ui->NumberZoneAmplifier->text().toInt(); i++)
    {
        {
            this->calcData << calcData.at(calcData.length()-1)-this->calcLenth.at(i);

            QPixmap tmp(100,20); // ширина, висота
            tmp.fill(QColor(255, 255, 255, 255));
            QPainter painter(&tmp);
            QPen pen(QBrush (QColor(0, 0, 0, 255), Qt::SolidPattern), 5 );
            painter.setPen(pen);
            QFont f("Myriad Pro", 14);
            f.setBold(true);
            painter.setFont(f);
            QTextOption textOption;
            textOption.setAlignment(Qt::AlignCenter);
            painter.drawText(QRectF(0,0,100,20), QString::number(calcData.last()),textOption);

            this->calculatesData << new QLabel(ui->scrollAreaWidgetContents);
            this->calculatesData.last()->setPixmap(tmp);
            this->calculatesData.last()->move(this->elements_x.at(i+1)-50, 450);
            this->calculatesData.last()->show();
            this->calculatesData_x << this->calculatesData.last()->geometry().x();
        }
        if(i != ui->NumberZoneAmplifier->text().toInt()-1){
            this->calcData << calcData.at(calcData.length()-1)+this->Sn_Line.at(i)->text().toDouble();

            QPixmap tmp(100,20); // ширина, висота
            tmp.fill(QColor(255, 255, 255, 255));
            QPainter painter(&tmp);
            QPen pen(QBrush (QColor(0, 0, 0, 255), Qt::SolidPattern), 5 );
            painter.setPen(pen);
            QFont f("Myriad Pro", 14);
            f.setBold(true);
            painter.setFont(f);
            QTextOption textOption;
            textOption.setAlignment(Qt::AlignCenter);
            painter.drawText(QRectF(0,0,100,20), QString::number(calcData.last()),textOption);

            this->calculatesData << new QLabel(ui->scrollAreaWidgetContents);
            this->calculatesData.last()->setPixmap(tmp);
            this->calculatesData.last()->move(this->elements_x.at(i+1)+50, 230);
            this->calculatesData.last()->show();
            this->calculatesData_x << this->calculatesData.last()->geometry().x();
        }
    }
}

void MainWindow::clearMemory()
{
    for(auto i : this->elements) delete i;
    this->elements.clear();
    this->elements_x.clear();

    for(auto i : this->lines) delete i;
    this->lines.clear();
    this->lines_x.clear();

    for(auto i : this->Sn_Label) delete i;
    this->Sn_Label.clear();
    this->Sn_Label_x.clear();
    for(auto i : this->Sn_Line) delete i;
    this->Sn_Line.clear();
    this->Sn_Line_x.clear();


    for(auto i : this->An_Label) delete i;
    this->An_Label.clear();
    this->An_Label_x.clear();
    for(auto i : this->An_Line) delete i;
    this->An_Line.clear();
    this->An_Line_x.clear();


    this->clearCalculateMemory();
}

void MainWindow::clearCalculateMemory()
{
    for(auto i : this->calculatesData) delete i;
    this->calculatesData.clear();
    this->calculatesData_x.clear();

    this->calcLenth.clear();

    this->calcData.clear();
}

void MainWindow::on_horizontalScrollBar_sliderMoved(int p)
{
    for(int i = 0; i < this->elements.length(); i++)
    {
        this->elements.at(i)->move(this->elements_x.at(i)-p, this->elements.at(i)->geometry().y());
    }

    for(int i = 0; i < this->lines.length(); i++)
    {
        this->lines.at(i)->move(this->lines_x.at(i)-p, this->lines.at(i)->geometry().y());
    }

    for(int i = 0; i < this->Sn_Label.length(); i++)
    {
        this->Sn_Label.at(i)->move(this->Sn_Label_x.at(i)-p, this->Sn_Label.at(i)->geometry().y());
    }

    for(int i = 0; i < this->Sn_Label.length(); i++)
    {
        this->Sn_Line.at(i)->move(this->Sn_Line_x.at(i)-p, this->Sn_Line.at(i)->geometry().y());
    }

    for(int i = 0; i < this->An_Label.length(); i++)
    {
        this->An_Label.at(i)->move(this->An_Label_x.at(i)-p, this->An_Label.at(i)->geometry().y());
    }

    for(int i = 0; i < this->An_Line.length(); i++)
    {
        this->An_Line.at(i)->move(this->An_Line_x.at(i)-p, this->An_Line.at(i)->geometry().y());
    }

    for(int i = 0; i < this->calculatesData.length(); i++)
    {
        this->calculatesData.at(i)->move(this->calculatesData_x.at(i)-p, this->calculatesData.at(i)->geometry().y());
    }
}
