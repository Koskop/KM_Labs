#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIntValidator* validator =  new QIntValidator( 0, 900);
    ui->lineEdit->setValidator(validator);
    this->go = new QLabel(ui->scrollAreaWidgetContents);
    //    this->go = new QLabel(this);
    ui->verticalScrollBar->setRange(0,0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clear_Menory(){
    ui->verticalScrollBar->setRange(0,0);

    for(auto i : this->aip) delete i;
    this->aip.clear();
    this->aip_Y.clear();

    for(auto i : this->app) delete i;
    this->app.clear();
    this->app_Y.clear();

    for(auto i : this->avp) delete i;
    this->avp.clear();
    this->avp_Y.clear();

    for(auto i : this->ac_oalp) delete i;
    this->ac_oalp.clear();
    this->ac_oalp_Y.clear();

    for(auto i : this->long_line) delete i;
    this->long_line.clear();
    this->long_line_Y.clear();

    this->go->hide();
    this->go_Y = 0;

    for(auto i : this->lines) delete i;
    this->lines.clear();
    this->lines_Y.clear();
}

void MainWindow::on_pushButton_clicked()
{
    this->clear_Menory();

    if(ui->lineEdit->text().toInt() %3 == 0)
    {
        if(ui->lineEdit->text().toInt() < 13){
            for(int i = 0; i < ui->lineEdit->text().toInt(); i++){
                this->long_line << new QLabel(ui->scrollAreaWidgetContents);
                this->long_line.at(i)->setPixmap(QPixmap(":/res/long_line.png"));
                this->long_line.at(i)->setGeometry(60, 165 + 33 * i + (10*(int)(i/3)), QPixmap(":/res/long_line.png").width(), QPixmap(":/res/long_line.png").height());
                this->long_line_Y << this->long_line.at(i)->geometry().y();
                this->long_line.at(i)->show();
            }
            for(int i = 0; i < ui->lineEdit->text().toInt(); i++){
                this->long_line << new QLabel(ui->scrollAreaWidgetContents);
                this->long_line.last()->setText("N" + QString::number(i+1));
                this->long_line.last()->move(60, 140 + 33 * i + (10*(int)(i/3)));
                this->long_line_Y << this->long_line.last()->geometry().y();
                this->long_line.last()->show();
            }

            for(int i = 0; i < (int)ui->lineEdit->text().toInt()/3; i++){
                this->aip << new QLabel(ui->scrollAreaWidgetContents);
                this->aip.at(i)->setPixmap(QPixmap(":/res/aip_x3.png"));
                this->aip.at(i)->setGeometry(90, 150 + (QPixmap(":/res/aip_x3.png").height() + 10) * i, QPixmap(":/res/aip_x3.png").width(), QPixmap(":/res/aip_x3.png").height());
                this->aip_Y << this->aip.at(i)->geometry().y();
                this->aip.at(i)->show();
            }

            // draw go
            if(this->aip.length() != 0){
                // go
                this->go->setPixmap(QPixmap(":/res/go_x3.png"));
                if(this->long_line_Y.last() + 5 > this->aip.last()->geometry().bottom()){
                    this->go->setGeometry(130, this->long_line_Y.last() + 15, QPixmap(":/res/go_x3.png").width(), QPixmap(":/res/go_x3.png").height());
                    this->go_Y = this->long_line_Y.last() + 15;
                }else{
                    this->go->setGeometry(130, this->aip.last()->geometry().bottom() + 22, QPixmap(":/res/go_x3.png").width(), QPixmap(":/res/go_x3.png").height());
                    this->go_Y = this->aip.last()->geometry().bottom() + 10;
                }
                //                this->go->show();
                // way to go from aip
                // horizontal
                for(int i = 0; i < this->aip.length(); i++)
                {
                    for(int j = 0; j < i+2; j++){
                        this->lines << new QLabel(ui->scrollAreaWidgetContents);
                        this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                        this->lines.last()->setGeometry(this->aip.at(i)->geometry().right() + QPixmap(":/res/line_horizontal.png").width() * j, this->aip.at(i)->geometry().center().y() + 10, QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                        this->lines_Y << this->lines.last()->geometry().y();
                        this->lines.last()->show();
                    }
                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    QPixmap tmp(5, this->go->geometry().y() - this->aip.at(i)->geometry().center().y()-10);
                    tmp.fill(Qt::black);
                    this->lines.last()->setPixmap(tmp);
                    this->lines.last()->setGeometry(this->lines.at(this->lines.length()-2)->geometry().right()-4, this->lines.at(this->lines.length()-2)->geometry().bottom(), tmp.width(), tmp.height());
                    this->lines_Y << this->lines.last()->geometry().y();
                    this->lines.last()->show();

                    QPixmap tmp1(this->go->geometry().right() - 130, 5);
                    tmp1.fill(Qt::black);
                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    this->lines.last()->setPixmap(tmp1);
                    this->lines.last()->setGeometry(140, this->aip.at(i)->geometry().center().y()-2, tmp1.width(), tmp1.height());
                    this->lines_Y << this->lines.last()->geometry().y();
                    this->lines.last()->show();
                }
                this->aip << new QLabel(ui->scrollAreaWidgetContents);
                this->aip.last()->setPixmap(QPixmap(":/res/as_x3.png"));
                this->aip.last()->setGeometry(this->lines.last()->geometry().right(), 150, QPixmap(":/res/as_x3.png").width(), QPixmap(":/res/as_x3.png").height());
                this->aip_Y << this->aip.last()->geometry().y();
                this->aip.last()->show();

                if (1)
                {
                    QPixmap tmp1(this->go->geometry().right() - 130, 5);
                    tmp1.fill(Qt::black);
                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    this->lines.last()->setPixmap(tmp1);
                    this->lines.last()->setGeometry(this->aip.last()->geometry().right(), this->aip.last()->geometry().center().y()-2, tmp1.width(), tmp1.height());
                    this->lines_Y << this->lines.last()->geometry().y();
                    this->lines.last()->show();
                }

                this->aip << new QLabel(ui->scrollAreaWidgetContents);
                this->aip.last()->setPixmap(QPixmap(":/res/oalp_x3.png"));
                this->aip.last()->setGeometry(this->lines.last()->geometry().right(), 150, QPixmap(":/res/oalp_x3.png").width(), QPixmap(":/res/oalp_x3.png").height());
                this->aip_Y << this->aip.last()->geometry().y();
                this->aip.last()->show();

                if (1)
                {
                    QPixmap tmp1(this->aip.last()->geometry().right() - this->aip.first()->geometry().left(), 50);
                    tmp1.fill(QColor(0,40,76,0));
                    QPainter p(&tmp1);
                    QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 10 );
                    p.setPen(pen);
                    QFont f("Myriad Pro", 12);
                    f.setBold(true);
                    p.setFont(f);
                    p.drawText((int)tmp1.size().width()/2 - 6, (int)tmp1.size().height()/2, "ГО");
                    pen.setColor(Qt::black);
                    p.setPen(pen);
                    p.drawLine(0, 0, 0, tmp1.size().height());
                    p.drawLine(tmp1.size().width(), 0, tmp1.size().width(), tmp1.size().height());
                    p.drawLine(0, 0, tmp1.size().width(), 0);
                    p.drawLine(0, tmp1.size().height(), tmp1.size().width(), tmp1.size().height());

                    this->go->setPixmap(tmp1);
                    this->go->setGeometry(this->aip.first()->geometry().left(), this->aip.last()->geometry().bottom() + 15, tmp1.width(), tmp1.height());
                    this->go_Y = this->go->geometry().y();
                    this->go->show();
                }

                if (1)
                {
                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    QPixmap tmp(5, this->go->geometry().y() - this->aip.last()->geometry().bottom()+5);
                    tmp.fill(Qt::black);
                    this->lines.last()->setPixmap(tmp);
                    this->lines.last()->setGeometry( aip.at(this->aip.length()-2)->geometry().center().x(), aip.at(this->aip.length()-2)->geometry().bottom() , tmp.width(), tmp.height());
                    this->lines_Y << this->lines.last()->geometry().y();
                    this->lines.last()->show();

                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    this->lines.last()->setPixmap(tmp);
                    this->lines.last()->setGeometry( aip.last()->geometry().center().x(), aip.last()->geometry().bottom() , tmp.width(), tmp.height());
                    this->lines_Y << this->lines.last()->geometry().y();
                    this->lines.last()->show();
                }

                for(int i = 0; i < ui->lineEdit->text().toInt()/3; i++)
                {
                    for(int j = 0; j < i+2; j++){
                        this->lines << new QLabel(ui->scrollAreaWidgetContents);
                        this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                        this->lines.last()->setGeometry(this->aip.at(i)->geometry().right() + QPixmap(":/res/line_horizontal.png").width() * j, this->aip.at(i)->geometry().center().y() + 10, QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                        this->lines_Y << this->lines.last()->geometry().y();
                        this->lines.last()->show();
                    }
                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    QPixmap tmp(5, this->go->geometry().y() - this->aip.at(i)->geometry().center().y()-10);
                    tmp.fill(Qt::black);
                    this->lines.last()->setPixmap(tmp);
                    this->lines.last()->setGeometry(this->lines.at(this->lines.length()-2)->geometry().right()-4, this->lines.at(this->lines.length()-2)->geometry().bottom(), tmp.width(), tmp.height());
                    this->lines_Y << this->lines.last()->geometry().y();
                    this->lines.last()->show();
                }
            }
        }else{
            if (ui->lineEdit->text().toInt() %12 == 0)
            {
                for(int i = 0; i < ui->lineEdit->text().toInt(); i++){
                    this->long_line << new QLabel(ui->scrollAreaWidgetContents);
                    this->long_line.at(i)->setPixmap(QPixmap(":/res/long_line.png"));
                    this->long_line.at(i)->setGeometry(60, 165 + 33 * i + (10*(int)(i/12)), QPixmap(":/res/long_line.png").width(), QPixmap(":/res/long_line.png").height());
                    this->long_line_Y << this->long_line.at(i)->geometry().y();
                    this->long_line.at(i)->show();
                }
                for(int i = 0; i < ui->lineEdit->text().toInt(); i++){
                    this->long_line << new QLabel(ui->scrollAreaWidgetContents);
                    this->long_line.last()->setText("N" + QString::number(i+1));
                    this->long_line.last()->move(60, 140 + 33 * i + (10*(int)(i/12)));
                    this->long_line_Y << this->long_line.last()->geometry().y();
                    this->long_line.last()->show();
                }

                for(int i = 0; i < (int)ui->lineEdit->text().toInt()/12; i++){
                    this->aip << new QLabel(ui->scrollAreaWidgetContents);
                    this->aip.at(i)->setPixmap(QPixmap(":/res/aip_x12.png"));
                    this->aip.at(i)->setGeometry(90, 150 + (QPixmap(":/res/aip_x12.png").height() + 10) * i, QPixmap(":/res/aip_x12.png").width(), QPixmap(":/res/aip_x12.png").height());
                    this->aip_Y << this->aip.at(i)->geometry().y();
                    this->aip.at(i)->show();
                }

                if(this->aip.length() != 0){
                    // way to go from aip
                    // horizontal
                    for(int i = 0; i < this->aip.length(); i++){
                        for(int j = 0; j < i+2; j++){
                            this->lines << new QLabel(ui->scrollAreaWidgetContents);
                            this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                            this->lines.last()->setGeometry(this->aip.at(i)->geometry().right() + QPixmap(":/res/line_horizontal.png").width() * j, this->aip.at(i)->geometry().center().y() + 20, QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                            this->lines_Y << this->lines.last()->geometry().y();
                            this->lines.last()->show();
                        }
                        this->lines << new QLabel(ui->scrollAreaWidgetContents);
                        QPixmap tmp(5, this->aip.last()->geometry().bottom() + 15 - this->aip.at(i)->geometry().center().y()-20);
                        tmp.fill(Qt::black);
                        this->lines.last()->setPixmap(tmp);
                        this->lines.last()->setGeometry(this->lines.at(this->lines.length()-2)->geometry().right()-4, this->lines.at(this->lines.length()-2)->geometry().bottom(), tmp.width(), tmp.height());
                        this->lines_Y << this->lines.last()->geometry().y();
                        this->lines.last()->show();
                    }

                    tmp = lines.last()->geometry().right() + 5;

                    for(int i = 0; i < this->aip.length(); i++){
                        QPixmap tmp1(tmp - 130, 5);
                        tmp1.fill(Qt::black);
                        this->lines << new QLabel(ui->scrollAreaWidgetContents);
                        this->lines.last()->setPixmap(tmp1);
                        this->lines.last()->setGeometry(140, this->aip.at(i)->geometry().center().y()-2, tmp1.width(), tmp1.height());
                        this->lines_Y << this->lines.last()->geometry().y();
                        this->lines.last()->show();
                    }


                    if(aip.length() >= 5)
                    {
                        QPixmap tmp1(50, this->aip.at(4)->geometry().bottom() - this->aip.first()->geometry().top());
                        tmp1.fill(QColor(0,200,0,150));
                        QPainter p(&tmp1);
                        QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 10 );
                        p.setPen(pen);
                        QFont f("Myriad Pro", 12);
                        f.setBold(true);
                        p.setFont(f);
                        p.drawText((int)tmp1.size().width()/2 - 18, (int)tmp1.size().height()/2, "АПП");
                        pen.setColor(Qt::black);
                        p.setPen(pen);
                        p.drawLine(0, 0, 0, tmp1.size().height());
                        p.drawLine(50, 0, 50, tmp1.size().height());
                        p.drawLine(0, 0, 50, 0);
                        p.drawLine(0, tmp1.size().height(), 50, tmp1.size().height());
                        //                        for (int i = 0; i < (int)aip.length(); i++){


                        for (int i = 0; i < (int)aip.length()/5; i++)
                        {
                            this->app << new QLabel(ui->scrollAreaWidgetContents);
                            this->app.last()->setPixmap(tmp1);
                            this->app.last()->setGeometry(this->lines.last()->geometry().right(), 150 + (tmp1.height() + 11) * i, tmp1.width(), tmp1.height());
                            this->app_Y << this->app.last()->geometry().y();
                            this->app.last()->show();
                        }
                        //                        }
                    }

                    for(int i = 0; i < app.length(); i++)
                    {
                        this->lines << new QLabel(ui->scrollAreaWidgetContents);
                        this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                        this->lines.last()->setGeometry(this->app.at(i)->geometry().right()+1, this->app.at(i)->geometry().center().y(), QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                        this->lines_Y << this->lines.last()->geometry().y();
                        this->lines.last()->show();
                        for(int j = 0; j < app.length()+2; j++){
                            this->lines << new QLabel(ui->scrollAreaWidgetContents);
                            this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                            this->lines.last()->setGeometry(lines.at(lines.length()-2)->geometry().right()+1, this->app.at(i)->geometry().center().y(), QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                            this->lines_Y << this->lines.last()->geometry().y();
                            this->lines.last()->show();
                        }

                    }

                    if(app.length() >= 5)
                    {
                        QPixmap tmp1(50, this->app.at(4)->geometry().bottom() - this->app.first()->geometry().top());
                        tmp1.fill(QColor(0,150,255,150));
                        QPainter p(&tmp1);
                        QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 10 );
                        p.setPen(pen);
                        QFont f("Myriad Pro", 12);
                        f.setBold(true);
                        p.setFont(f);
                        p.drawText((int)tmp1.size().width()/2 - 18, (int)tmp1.size().height()/2, "АВП");
                        pen.setColor(Qt::black);
                        p.setPen(pen);
                        p.drawLine(0, 0, 0, tmp1.size().height());
                        p.drawLine(50, 0, 50, tmp1.size().height());
                        p.drawLine(0, 0, 50, 0);
                        p.drawLine(0, tmp1.size().height(), 50, tmp1.size().height());

                        for (int i = 0; i < (int)app.length()/5; i++){
                            this->avp << new QLabel(ui->scrollAreaWidgetContents);
                            this->avp.last()->setPixmap(tmp1);
                            this->avp.last()->setGeometry(this->app.last()->geometry().right() + 30 + 10 * app.length(), 150 + (tmp1.height() + 11) * i, tmp1.width(), tmp1.height());
                            this->avp_Y << this->avp.last()->geometry().y();
                            this->avp.last()->show();
                        }
                    }

                    for(int i = 0; i < avp.length(); i++)
                    {
                        this->lines << new QLabel(ui->scrollAreaWidgetContents);
                        this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                        this->lines.last()->setGeometry(this->avp.at(i)->geometry().right()+1, this->avp.at(i)->geometry().center().y(), QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                        this->lines_Y << this->lines.last()->geometry().y();
                        this->lines.last()->show();
                        for(int j = 0; j < avp.length()+2; j++){
                            this->lines << new QLabel(ui->scrollAreaWidgetContents);
                            this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                            this->lines.last()->setGeometry(lines.at(lines.length()-2)->geometry().right()+1, this->avp.at(i)->geometry().center().y(), QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                            this->lines_Y << this->lines.last()->geometry().y();
                            this->lines.last()->show();
                        }
                    }

                    if (1)
                    {
                        QPixmap tmp1(50, this->aip.last()->geometry().bottom() - this->aip.first()->geometry().top());
                        tmp1.fill(QColor(160,150,20,150));
                        QPainter p(&tmp1);
                        QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 10 );
                        p.setPen(pen);
                        QFont f("Myriad Pro", 12);
                        f.setBold(true);
                        p.setFont(f);
                        p.drawText((int)tmp1.size().width()/2 - 12, (int)tmp1.size().height()/2, "AC");
                        pen.setColor(Qt::black);
                        p.setPen(pen);
                        p.drawLine(0, 0, 0, tmp1.size().height());
                        p.drawLine(50, 0, 50, tmp1.size().height());
                        p.drawLine(0, 0, 50, 0);
                        p.drawLine(0, tmp1.size().height(), 50, tmp1.size().height());

                        if (!avp.empty())
                        {
                            this->ac_oalp << new QLabel(ui->scrollAreaWidgetContents);
                            this->ac_oalp.last()->setPixmap(tmp1);
                            this->ac_oalp.last()->setGeometry(this->avp.last()->geometry().right() + 30 + 10 * avp.length(), 150, tmp1.width(), tmp1.height());
                            this->ac_oalp_Y << this->ac_oalp.last()->geometry().y();
                            this->ac_oalp.last()->show();
                        }
                        else if (!app.empty())
                        {
                            this->ac_oalp << new QLabel(ui->scrollAreaWidgetContents);
                            this->ac_oalp.last()->setPixmap(tmp1);
                            this->ac_oalp.last()->setGeometry(this->app.last()->geometry().right() + 27 + 10 * app.length(), 150, tmp1.width(), tmp1.height());
                            this->ac_oalp_Y << this->ac_oalp.last()->geometry().y();
                            this->ac_oalp.last()->show();
                        }
                        else if (!aip.empty())
                        {
                            this->ac_oalp << new QLabel(ui->scrollAreaWidgetContents);
                            this->ac_oalp.last()->setPixmap(tmp1);
                            this->ac_oalp.last()->setGeometry(this->aip.last()->geometry().right() + 20 + 10 * aip.length(), 150, tmp1.width(), tmp1.height());
                            this->ac_oalp_Y << this->ac_oalp.last()->geometry().y();
                            this->ac_oalp.last()->show();
                        }
                    }

                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                    this->lines.last()->setGeometry(this->ac_oalp.last()->geometry().right()+1, this->ac_oalp.last()->geometry().center().y(), QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                    this->lines_Y << this->lines.last()->geometry().y();
                    this->lines.last()->show();

                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                    this->lines.last()->setGeometry(lines.at(lines.length()-2)->geometry().right()+1, this->ac_oalp.last()->geometry().center().y(), QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                    this->lines_Y << this->lines.last()->geometry().y();
                    this->lines.last()->show();

                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                    this->lines.last()->setGeometry(lines.at(lines.length()-2)->geometry().right()+1, this->ac_oalp.last()->geometry().center().y(), QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                    this->lines_Y << this->lines.last()->geometry().y();
                    this->lines.last()->show();

                    if (1)
                    {
                        QPixmap tmp1(50, this->aip.last()->geometry().bottom() - this->aip.first()->geometry().top());
                        tmp1.fill(QColor(57,73,80,150));
                        QPainter p(&tmp1);
                        QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 10 );
                        p.setPen(pen);
                        QFont f("Myriad Pro", 10);
                        f.setBold(true);
                        p.setFont(f);
                        p.drawText(6, (int)tmp1.size().height()/2, "ОAЛП");
                        pen.setColor(Qt::black);
                        p.setPen(pen);
                        p.drawLine(0, 0, 0, tmp1.size().height());
                        p.drawLine(50, 0, 50, tmp1.size().height());
                        p.drawLine(0, 0, 50, 0);
                        p.drawLine(0, tmp1.size().height(), 50, tmp1.size().height());

                        this->ac_oalp << new QLabel(ui->scrollAreaWidgetContents);
                        this->ac_oalp.last()->setPixmap(tmp1);
                        this->ac_oalp.last()->setGeometry(this->ac_oalp.at(0)->geometry().right() + 30, 150, tmp1.width(), tmp1.height());
                        this->ac_oalp_Y << this->ac_oalp.last()->geometry().y();
                        this->ac_oalp.last()->show();
                    }

                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                    this->lines.last()->setGeometry(this->ac_oalp.last()->geometry().right()+1, this->ac_oalp.last()->geometry().center().y(), QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                    this->lines_Y << this->lines.last()->geometry().y();
                    this->lines.last()->show();

                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                    this->lines.last()->setGeometry(lines.at(lines.length()-2)->geometry().right()+1, this->ac_oalp.last()->geometry().center().y(), QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                    this->lines_Y << this->lines.last()->geometry().y();
                    this->lines.last()->show();

                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                    this->lines.last()->setGeometry(lines.at(lines.length()-2)->geometry().right()+1, this->ac_oalp.last()->geometry().center().y(), QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                    this->lines_Y << this->lines.last()->geometry().y();
                    this->lines.last()->show();

                    if (1)
                    {
                        QPixmap tmp1(this->ac_oalp.last()->geometry().right() - this->aip.last()->geometry().left(), 50);
                        tmp1.fill(QColor(0,40,76,150));
                        QPainter p(&tmp1);
                        QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 10 );
                        p.setPen(pen);
                        QFont f("Myriad Pro", 12);
                        f.setBold(true);
                        p.setFont(f);
                        p.drawText((int)tmp1.size().width()/2 - 6, (int)tmp1.size().height()/2, "ГО");
                        pen.setColor(Qt::black);
                        p.setPen(pen);
                        p.drawLine(0, 0, 0, tmp1.size().height());
                        p.drawLine(tmp1.size().width(), 0, tmp1.size().width(), tmp1.size().height());
                        p.drawLine(0, 0, tmp1.size().width(), 0);
                        p.drawLine(0, tmp1.size().height(), tmp1.size().width(), tmp1.size().height());

                        this->go->setPixmap(tmp1);
                        this->go->setGeometry(this->aip.last()->geometry().left(), this->aip.last()->geometry().bottom() + 15, tmp1.width(), tmp1.height());
                        this->go_Y = this->go->geometry().y();
                        this->go->show();
                    }
                    for(int i = 0; i < 2; i++)
                    {
                        this->lines << new QLabel(ui->scrollAreaWidgetContents);
                        QPixmap tmp(5, this->go->geometry().y() - this->ac_oalp.at(i)->geometry().bottom());
                        tmp.fill(Qt::black);
                        this->lines.last()->setPixmap(tmp);
                        this->lines.last()->setGeometry(this->ac_oalp.at(i)->geometry().center().x()-2, this->ac_oalp.at(i)->geometry().bottom(), tmp.width(), tmp.height());
                        this->lines_Y << this->lines.last()->geometry().y();
                        this->lines.last()->show();
                    }


                    if (!avp.empty())
                    {
                        for(int i = 0; i < this->avp.length(); i++){
                            for(int j = 0; j < i+2; j++){
                                this->lines << new QLabel(ui->scrollAreaWidgetContents);
                                this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                                this->lines.last()->setGeometry(this->avp.at(i)->geometry().right() + QPixmap(":/res/line_horizontal.png").width() * j, this->avp.at(i)->geometry().center().y() + 20, QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                                this->lines_Y << this->lines.last()->geometry().y();
                                this->lines.last()->show();
                            }
                            this->lines << new QLabel(ui->scrollAreaWidgetContents);
                            QPixmap tmp(5, this->aip.last()->geometry().bottom() + 15 - this->avp.at(i)->geometry().center().y()-20);
                            tmp.fill(Qt::black);
                            this->lines.last()->setPixmap(tmp);
                            this->lines.last()->setGeometry(this->lines.at(this->lines.length()-2)->geometry().right()-4, this->lines.at(this->lines.length()-2)->geometry().bottom(), tmp.width(), tmp.height());
                            this->lines_Y << this->lines.last()->geometry().y();
                            this->lines.last()->show();
                        }
                    }

                    if (!app.empty())
                    {
                        for(int i = 0; i < this->app.length(); i++){
                            for(int j = 0; j < i+2; j++){
                                this->lines << new QLabel(ui->scrollAreaWidgetContents);
                                this->lines.last()->setPixmap(QPixmap(":/res/line_horizontal.png"));
                                this->lines.last()->setGeometry(this->app.at(i)->geometry().right() + QPixmap(":/res/line_horizontal.png").width() * j, this->app.at(i)->geometry().center().y() + 20, QPixmap(":/res/line_horizontal.png").width(), QPixmap(":/res/line_horizontal.png").height());
                                this->lines_Y << this->lines.last()->geometry().y();
                                this->lines.last()->show();
                            }
                            this->lines << new QLabel(ui->scrollAreaWidgetContents);
                            QPixmap tmp(5, this->aip.last()->geometry().bottom() + 15 - this->app.at(i)->geometry().center().y()-20);
                            tmp.fill(Qt::black);
                            this->lines.last()->setPixmap(tmp);
                            this->lines.last()->setGeometry(this->lines.at(this->lines.length()-2)->geometry().right()-4, this->lines.at(this->lines.length()-2)->geometry().bottom(), tmp.width(), tmp.height());
                            this->lines_Y << this->lines.last()->geometry().y();
                            this->lines.last()->show();
                        }
                    }

                    if(this->aip.length() %5 != 0)
                    {
                        for(int i = 0; i < aip.length() %5; i++)
                        {
                            this->lines << new QLabel(ui->scrollAreaWidgetContents);
                            QPixmap tmp(this->ac_oalp.at(0)->geometry().left() - this->aip.at(aip.length() - 1 - i)->geometry().right(), 5);
                            tmp.fill(Qt::black);
                            this->lines.last()->setPixmap(tmp);
                            this->lines.last()->setGeometry(this->aip.at(aip.length() - 1 - i)->geometry().right(), this->aip.at(aip.length() - 1 - i)->geometry().center().y() - 2, tmp.width(), tmp.height());
                            this->lines_Y << this->lines.last()->geometry().y();
                            this->lines.last()->show();
                        }
                    }

                    if(this->app.length() %5 != 0)
                    {
                        for(int i = 0; i < aip.length() %5; i++)
                        {
                            this->lines << new QLabel(ui->scrollAreaWidgetContents);
                            QPixmap tmp(this->ac_oalp.at(0)->geometry().left() - this->app.at(app.length() - 1 - i)->geometry().right(), 5);
                            tmp.fill(Qt::black);
                            this->lines.last()->setPixmap(tmp);
                            this->lines.last()->setGeometry(this->app.at(app.length() - 1 - i)->geometry().right(), this->app.at(app.length() - 1 - i)->geometry().center().y(), tmp.width(), tmp.height());
                            this->lines_Y << this->lines.last()->geometry().y();
                            this->lines.last()->show();
                        }
                    }

                }
            }
        }
        if(this->aip.last()->geometry().bottom() > 400)
            ui->verticalScrollBar->setRange(0,this->aip.last()->geometry().bottom() - 150);

    }

}

void MainWindow::on_verticalScrollBar_sliderMoved(int p)
{
    if(!aip.empty())
        for(int i = 0; i < this->aip.length(); i++){
            this->aip.at(i)->move(this->aip.at(i)->geometry().x(), this->aip_Y.at(i) - p);
        }

    if(!app.empty())
        for(int i = 0; i < this->app.length(); i++){
            this->app.at(i)->move(this->app.at(i)->geometry().x(), this->app_Y.at(i) - p);
        }

    if(!avp.empty())
        for(int i = 0; i < this->avp.length(); i++){
            this->avp.at(i)->move(this->avp.at(i)->geometry().x(), this->avp_Y.at(i) - p);
        }

    if(!ac_oalp.empty())
        for(int i = 0; i < this->ac_oalp.length(); i++){
            this->ac_oalp.at(i)->move(this->ac_oalp.at(i)->geometry().x(), this->ac_oalp_Y.at(i) - p);
        }

    if(!long_line.empty())
        for(int i = 0; i < this->long_line.length(); i++){
            this->long_line.at(i)->move(this->long_line.at(i)->geometry().x(), this->long_line_Y.at(i) - p);
        }

    this->go->move(this->go->geometry().x(), this->go_Y - p);

    if(!lines.empty())
        for(int i = 0; i < this->lines.length(); i++){
            this->lines.at(i)->move(this->lines.at(i)->geometry().x(), this->lines_Y.at(i) - p);
        }
}
