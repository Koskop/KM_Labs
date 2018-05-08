#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(86);
    ui->horizontalScrollBar->setRange(0,0);
    ui->verticalScrollBar->setRange(0,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    if(position < 4){
        ui->numberLine->setText(QString::number(position*3));
    }else{
        ui->numberLine->setText(QString::number((position-3)*12));
    }
    this->check_the_condition();
}

void MainWindow::on_toolButtonPlus_clicked()
{
    if(ui->numberLine->toPlainText().toInt() < 996){
        if(ui->numberLine->toPlainText().toInt() < 12){
            ui->numberLine->setText(QString::number(ui->numberLine->toPlainText().toInt() + 3));
        }else{
            ui->numberLine->setText(QString::number(ui->numberLine->toPlainText().toInt() + 12));
        }
        this->synchronization();
    }
}

void MainWindow::on_toolButtonMinus_clicked()
{
    if(ui->numberLine->toPlainText().toInt() > 0){
        if(ui->numberLine->toPlainText().toInt() < 13){
            ui->numberLine->setText(QString::number(ui->numberLine->toPlainText().toInt() - 3));
        }else{
            ui->numberLine->setText(QString::number(ui->numberLine->toPlainText().toInt() - 12));
        }
        this->synchronization();
    }
}

void MainWindow::synchronization()
{
    if(ui->numberLine->toPlainText().toInt() < 13){
        ui->horizontalSlider->setValue((int)((ui->numberLine->toPlainText().toInt())/3));
    }else{
        ui->horizontalSlider->setValue((int)((ui->numberLine->toPlainText().toInt())/12)+3);
    }
    this->check_the_condition();
}

void MainWindow::check_the_condition()
{
    ui->pushButton->setEnabled(false);
    if(ui->numberLine->toPlainText().toInt()%3 == 0 || ui->numberLine->toPlainText().toInt()%12 == 0){
        //enable
        ui->pushButton->setEnabled(true);
    }else{
        //disable
        ui->pushButton->setEnabled(false);
    }
}

void MainWindow::on_numberLine_textChanged()
{
    this->check_the_condition();
}

void MainWindow::on_pushButton_clicked() //draw element
{
    this->on_pushButton_2_clicked(); //clear memory

    if(ui->numberLine->toPlainText().toInt() < 12){
        for(int i = 0; i < ui->numberLine->toPlainText().toInt()/3; i++){
            for(int j = 0; j < 3; j ++){
                int nl = 300; // зміщення на новий шар
                if(1){ //vertical
                    QPixmap tmp(100,50); // ширина, висота
                    tmp.fill(QColor(0,0,0,0));
                    QPainter painter(&tmp);
                    QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 5 );
                    painter.setPen(pen);
                    QFont f("Myriad Pro", 12);
                    f.setBold(true);
                    painter.setFont(f);
                    painter.drawText((int)tmp.size().width()/1.7, (int)tmp.size().height()-7, QString::number(1+j+3*i));
                    pen.setColor(Qt::black);
                    painter.setPen(pen);
                    painter.drawLine(0, tmp.size().height()-2.5, tmp.size().width(), 0);
                    painter.drawLine(tmp.size().width()-2.5, 5, tmp.size().width()-2.5, tmp.size().height());
                    painter.drawLine(0, tmp.size().height()-2.5, tmp.size().width()-2.5, tmp.size().height()-2.5);

                    this->vertical_triangle << new QLabel(ui->scrollAreaWidgetContents);
                    this->vertical_triangle.last()->setPixmap(tmp);
                    this->vertical_triangle.last()->move(10, 50+75*j+nl*i);
                    this->vertical_triangle.last()->show();
                    this->vertical_triangle_coords_Y << this->vertical_triangle.last()->geometry().y();
                    this->vertical_triangle_coords_X << this->vertical_triangle.last()->geometry().x();
                }

                if(1){ //horyzontal
                    QPixmap tmp(100,50); // ширина, висота
                    tmp.fill(QColor(0,0,0,0));
                    QPainter painter(&tmp);
                    QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 5 );
                    painter.setPen(pen);
                    QFont f("Myriad Pro", 12);
                    f.setBold(true);
                    painter.setFont(f);
                    painter.drawText(10, (int)tmp.size().height()-7, QString::number(3-j+3*i));
                    pen.setColor(Qt::black);
                    painter.setPen(pen);
                    painter.drawLine(2.5, 0, tmp.size().width()-2.5, tmp.size().height()-5);
                    painter.drawLine(2.5, 0, 2.5, tmp.size().height());
                    painter.drawLine(0, tmp.size().height()-2.5, tmp.size().width() + 5, tmp.size().height()-2.5);

                    this->horyzontal_triangle << new QLabel(ui->scrollAreaWidgetContents);
                    this->horyzontal_triangle.last()->setPixmap(tmp);
                    this->horyzontal_triangle.last()->move(250+100*j, 275 + nl*i);
                    this->horyzontal_triangle.last()->show();
                    this->horyzontal_triangle_coords_Y << this->horyzontal_triangle.last()->geometry().y();
                    this->horyzontal_triangle_coords_X << this->horyzontal_triangle.last()->geometry().x();
                }
                if(1){ //lines vertical
                    QPixmap tmp(5,30+75*j); // ширина, висота
                    tmp.fill(Qt::black);

                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    this->lines.last()->setPixmap(tmp);
                    this->lines.last()->move(250+100*j, 275 + nl*i - tmp.height());
                    this->lines.last()->show();
                    this->lines_coords_Y << this->lines.last()->geometry().y();
                    this->lines_coords_X << this->lines.last()->geometry().x();
                }
                if(1){ //lines horyzontal
                    QPixmap tmp(140+100*j,5); // ширина, висота
                    tmp.fill(Qt::black);

                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    this->lines.last()->setPixmap(tmp);
                    this->lines.last()->move(250+100*j - tmp.width(), 270 + nl*i-(25+75*j));
                    this->lines.last()->show();
                    this->lines_coords_Y << this->lines.last()->geometry().y();
                    this->lines_coords_X << this->lines.last()->geometry().x();
                }

                this->rl << new QLabel(ui->scrollAreaWidgetContents);
                this->rl.last()->setText("ПГ"+QString::number(i+1));
                this->rl.last()->move(200, 300 + nl*i);
                this->rl.last()->show();
                this->rl_coords_Y << this->rl.last()->geometry().y();
                this->rl_coords_X << this->rl.last()->geometry().x();

                this->rl << new QLabel(ui->scrollAreaWidgetContents);
                this->rl.last()->setText("0,3");
                this->rl.last()->move(10, 50+55+75*j+nl*i);
                this->rl.last()->show();
                this->rl_coords_Y << this->rl.last()->geometry().y();
                this->rl_coords_X << this->rl.last()->geometry().x();
                this->rl << new QLabel(ui->scrollAreaWidgetContents);
                this->rl.last()->setText("3,4");
                this->rl.last()->move(90, 50+55+75*j+nl*i);
                this->rl.last()->show();
                this->rl_coords_Y << this->rl.last()->geometry().y();
                this->rl_coords_X << this->rl.last()->geometry().x();

                this->rl << new QLabel(ui->scrollAreaWidgetContents);
                this->rl.last()->setText(QString::number(12+4*j));
                this->rl.last()->move(130, 50+25+75*j+nl*i);
                this->rl.last()->show();
                this->rl_coords_Y << this->rl.last()->geometry().y();
                this->rl_coords_X << this->rl.last()->geometry().x();

                this->rl << new QLabel(ui->scrollAreaWidgetContents);
                this->rl.last()->setText(QString::number(20.3-4*j));
                this->rl.last()->move(250+100*j, 325 + nl*i);
                this->rl.last()->show();
                this->rl_coords_Y << this->rl.last()->geometry().y();
                this->rl_coords_X << this->rl.last()->geometry().x();
                this->rl << new QLabel(ui->scrollAreaWidgetContents);
                this->rl.last()->setText(QString::number(23.4-4*j));
                this->rl.last()->move(325+100*j, 325 + nl*i);
                this->rl.last()->show();
                this->rl_coords_Y << this->rl.last()->geometry().y();
                this->rl_coords_X << this->rl.last()->geometry().x();
            }
        }
    }else{
        for(int i = 0; i < ui->numberLine->toPlainText().toInt()/12; i++){
            for(int j = 0; j < 12; j ++){
                int nl = 1000; // зміщення на новий шар
                if(1){ //vertical
                    QPixmap tmp(100,50); // ширина, висота
                    tmp.fill(QColor(0,0,0,0));
                    QPainter painter(&tmp);
                    QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 5);
                    painter.setPen(pen);
                    QFont f("Myriad Pro", 12);
                    f.setBold(true);
                    painter.setFont(f);
                    painter.drawText((int)tmp.size().width()/1.7, (int)tmp.size().height()-7, QString::number(1+j+12*i));
                    pen.setColor(Qt::black);
                    painter.setPen(pen);
                    painter.drawLine(0, tmp.size().height()-2.5, tmp.size().width(), 0);
                    painter.drawLine(tmp.size().width()-2.5, 5, tmp.size().width()-2.5, tmp.size().height());
                    painter.drawLine(0, tmp.size().height()-2.5, tmp.size().width()-2.5, tmp.size().height()-2.5);

                    this->vertical_triangle << new QLabel(ui->scrollAreaWidgetContents);
                    this->vertical_triangle.last()->setPixmap(tmp);
                    this->vertical_triangle.last()->move(10, 50+75*j+nl*i);
                    this->vertical_triangle.last()->show();
                    this->vertical_triangle_coords_Y << this->vertical_triangle.last()->geometry().y();
                    this->vertical_triangle_coords_X << this->vertical_triangle.last()->geometry().x();
                }

                if(1){ //horyzontal
                    QPixmap tmp(100,50); // ширина, висота
                    tmp.fill(QColor(0,0,0,0));
                    QPainter painter(&tmp);
                    QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 5 );
                    painter.setPen(pen);
                    QFont f("Myriad Pro", 12);
                    f.setBold(true);
                    painter.setFont(f);
                    painter.drawText(10, (int)tmp.size().height()-7, QString::number(12-j+12*i));
                    pen.setColor(Qt::black);
                    painter.setPen(pen);
                    painter.drawLine(2.5, 0, tmp.size().width()-2.5, tmp.size().height()-5);
                    painter.drawLine(2.5, 0, 2.5, tmp.size().height());
                    painter.drawLine(0, tmp.size().height()-2.5, tmp.size().width() + 5, tmp.size().height()-2.5);

                    this->horyzontal_triangle << new QLabel(ui->scrollAreaWidgetContents);
                    this->horyzontal_triangle.last()->setPixmap(tmp);
                    this->horyzontal_triangle.last()->move(250+100*j, 950 + nl*i);
                    this->horyzontal_triangle.last()->show();
                    this->horyzontal_triangle_coords_Y << this->horyzontal_triangle.last()->geometry().y();
                    this->horyzontal_triangle_coords_X << this->horyzontal_triangle.last()->geometry().x();
                }
                if(1){ //lines vertical
                    QPixmap tmp(5,30+75*j); // ширина, висота
                    tmp.fill(Qt::black);

                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    this->lines.last()->setPixmap(tmp);
                    this->lines.last()->move(250+100*j, 950 + nl*i - tmp.height());
                    this->lines.last()->show();
                    this->lines_coords_Y << this->lines.last()->geometry().y();
                    this->lines_coords_X << this->lines.last()->geometry().x();
                }
                if(1){ //lines horyzontal
                    QPixmap tmp(140+100*j,5); // ширина, висота
                    tmp.fill(Qt::black);

                    this->lines << new QLabel(ui->scrollAreaWidgetContents);
                    this->lines.last()->setPixmap(tmp);
                    this->lines.last()->move(250+100*j - tmp.width(), 945 + nl*i-(25+75*j));
                    this->lines.last()->show();
                    this->lines_coords_Y << this->lines.last()->geometry().y();
                    this->lines_coords_X << this->lines.last()->geometry().x();
                }

                this->rl << new QLabel(ui->scrollAreaWidgetContents);
                this->rl.last()->setText("ПГ "+QString::number(i+1));
                this->rl.last()->move(200, 975 + nl*i);
                this->rl.last()->show();
                this->rl_coords_Y << this->rl.last()->geometry().y();
                this->rl_coords_X << this->rl.last()->geometry().x();

                this->rl << new QLabel(ui->scrollAreaWidgetContents);
                this->rl.last()->setText("0,3");
                this->rl.last()->move(10, 50+55+75*j+nl*i);
                this->rl.last()->show();
                this->rl_coords_Y << this->rl.last()->geometry().y();
                this->rl_coords_X << this->rl.last()->geometry().x();
                this->rl << new QLabel(ui->scrollAreaWidgetContents);
                this->rl.last()->setText("3,4");
                this->rl.last()->move(90, 50+55+75*j+nl*i);
                this->rl.last()->show();
                this->rl_coords_Y << this->rl.last()->geometry().y();
                this->rl_coords_X << this->rl.last()->geometry().x();

                this->rl << new QLabel(ui->scrollAreaWidgetContents);
                this->rl.last()->setText(QString::number(108-4*j));
                this->rl.last()->move(130, 50+25+75*j+nl*i);
                this->rl.last()->show();
                this->rl_coords_Y << this->rl.last()->geometry().y();
                this->rl_coords_X << this->rl.last()->geometry().x();

                this->rl << new QLabel(ui->scrollAreaWidgetContents);
                this->rl.last()->setText(QString::number(104.3-4*j));
                this->rl.last()->move(250+100*j, 1000 + nl*i);
                this->rl.last()->show();
                this->rl_coords_Y << this->rl.last()->geometry().y();
                this->rl_coords_X << this->rl.last()->geometry().x();
                this->rl << new QLabel(ui->scrollAreaWidgetContents);
                this->rl.last()->setText(QString::number(107.4-4*j));
                this->rl.last()->move(325+100*j, 1000 + nl*i);
                this->rl.last()->show();
                this->rl_coords_Y << this->rl.last()->geometry().y();
                this->rl_coords_X << this->rl.last()->geometry().x();
            }

            if((i+1)%5 == 0){ // draw VG
                for(int ij = 0; ij < 5; ij++){
                    if(1){
                        QPixmap tmp(100,50); // ширина, висота
                        tmp.fill(QColor(0,0,0,0));
                        QPainter painter(&tmp);
                        QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 5);
                        painter.setPen(pen);
                        QFont f("Myriad Pro", 12);
                        f.setBold(true);
                        painter.setFont(f);
                        painter.drawText((int)tmp.size().width()/1.7, (int)tmp.size().height()-7, QString::number(5-ij+5*(((i+1)/5)-1)));
                        pen.setColor(Qt::black);
                        painter.setPen(pen);
                        painter.drawLine(0, tmp.size().height()-2.5, tmp.size().width(), 0);
                        painter.drawLine(tmp.size().width()-2.5, 5, tmp.size().width()-2.5, tmp.size().height());
                        painter.drawLine(0, tmp.size().height()-2.5, tmp.size().width()-2.5, tmp.size().height()-2.5);

                        this->horyzontal_triangle << new QLabel(ui->scrollAreaWidgetContents);
                        this->horyzontal_triangle.last()->setPixmap(tmp);
                        this->horyzontal_triangle.last()->move(1600+100*ij, 5050 + 5000*(((i+1)/5)-1));
                        this->horyzontal_triangle.last()->show();
                        this->horyzontal_triangle_coords_Y << this->horyzontal_triangle.last()->geometry().y();
                        this->horyzontal_triangle_coords_X << this->horyzontal_triangle.last()->geometry().x();
                    }
                    if(1){ //lines vertical
                        QPixmap tmp(5,50+1000*ij); // ширина, висота
                        tmp.fill(Qt::black);

                        this->lines << new QLabel(ui->scrollAreaWidgetContents);
                        this->lines.last()->setPixmap(tmp);
                        this->lines.last()->move(1695+100*ij, 5050 + 5000*(((i+1)/5)-1) - tmp.height());
                        this->lines.last()->show();
                        this->lines_coords_Y << this->lines.last()->geometry().y();
                        this->lines_coords_X << this->lines.last()->geometry().x();
                    }
                    if(1){ //lines horyzontal
                        QPixmap tmp(300+100*ij,5); // ширина, висота
                        tmp.fill(Qt::black);

                        this->lines << new QLabel(ui->scrollAreaWidgetContents);
                        this->lines.last()->setPixmap(tmp);
                        this->lines.last()->move(1700+100*ij - tmp.width(), 5020 + 5000*(((i+1)/5)-1)-(25+1000*ij));
                        this->lines.last()->show();
                        this->lines_coords_Y << this->lines.last()->geometry().y();
                        this->lines_coords_X << this->lines.last()->geometry().x();
                    }
                    this->rl << new QLabel(ui->scrollAreaWidgetContents);
                    this->rl.last()->setText(QString::number(540.3-4*ij));
                    this->rl.last()->move(1600+100*ij, 5100 + 5000*(((i+1)/5)-1));
                    this->rl.last()->show();
                    this->rl_coords_Y << this->rl.last()->geometry().y();
                    this->rl_coords_X << this->rl.last()->geometry().x();
                    this->rl << new QLabel(ui->scrollAreaWidgetContents);
                    this->rl.last()->setText(QString::number(551.4-4*ij));
                    this->rl.last()->move(1665+100*ij, 5100 + 5000*(((i+1)/5)-1));
                    this->rl.last()->show();
                    this->rl_coords_Y << this->rl.last()->geometry().y();
                    this->rl_coords_X << this->rl.last()->geometry().x();

                    this->rl << new QLabel(ui->scrollAreaWidgetContents);
                    this->rl.last()->setText(QString::number(612-48*ij));
                    this->rl.last()->move(1500, 5005 + 5000*(((i+1)/5)-1)-(25+1000*ij));
                    this->rl.last()->show();
                    this->rl_coords_Y << this->rl.last()->geometry().y();
                    this->rl_coords_X << this->rl.last()->geometry().x();
                }
                this->rl << new QLabel(ui->scrollAreaWidgetContents);
                this->rl.last()->setText("ВГ "+QString::number((i+1)/5));
                this->rl.last()->move(1575, 5055 + 5000*(((i+1)/5)-1));
                this->rl.last()->show();
                this->rl_coords_Y << this->rl.last()->geometry().y();
                this->rl_coords_X << this->rl.last()->geometry().x();


            }
            if((i+1)%25 == 0){ // draw TG
                for(int ijj = 0; ijj < 5; ijj++){
                    if(1){
                        QPixmap tmp(100,50); // ширина, висота
                        tmp.fill(QColor(0,0,0,0));
                        QPainter painter(&tmp);
                        QPen pen(QBrush (QColor(230,30,116), Qt::SolidPattern), 5);
                        painter.setPen(pen);
                        QFont f("Myriad Pro", 12);
                        f.setBold(true);
                        painter.setFont(f);
                        painter.drawText(15, (int)tmp.size().height()-7, QString::number(5-ijj+5*(((i+1)/25)-1)));
                        pen.setColor(Qt::black);
                        painter.setPen(pen);
                        painter.drawLine(2.5, 0, tmp.size().width()-2.5, tmp.size().height()-5);
                        painter.drawLine(2.5, 0, 2.5, tmp.size().height());
                        painter.drawLine(0, tmp.size().height()-2.5, tmp.size().width() + 5, tmp.size().height()-2.5);
                        this->horyzontal_triangle << new QLabel(ui->scrollAreaWidgetContents);
                        this->horyzontal_triangle.last()->setPixmap(tmp);
                        this->horyzontal_triangle.last()->move(2200+100*ijj, 5150 + 5000*(((i+1)/5)-1));
                        this->horyzontal_triangle.last()->show();
                        this->horyzontal_triangle_coords_Y << this->horyzontal_triangle.last()->geometry().y();
                        this->horyzontal_triangle_coords_X << this->horyzontal_triangle.last()->geometry().x();
                    }
                    if(1){ //lines vertical
                        QPixmap tmp(5,50+5000*ijj); // ширина, висота
                        tmp.fill(Qt::black);

                        this->lines << new QLabel(ui->scrollAreaWidgetContents);
                        this->lines.last()->setPixmap(tmp);
                        this->lines.last()->move(2200+100*ijj, 5150 + 5000*(((i+1)/5)-1) - tmp.height());
                        this->lines.last()->show();
                        this->lines_coords_Y << this->lines.last()->geometry().y();
                        this->lines_coords_X << this->lines.last()->geometry().x();
                    }
                    if(1){ //lines horyzontal
                        QPixmap tmp(300+100*ijj,5); // ширина, висота
                        tmp.fill(Qt::black);

                        this->lines << new QLabel(ui->scrollAreaWidgetContents);
                        this->lines.last()->setPixmap(tmp);
                        this->lines.last()->move(2205+100*ijj - tmp.width(), 25095 + 25000*(((i+1)/25)-1)-(5000*ijj));
                        this->lines.last()->show();
                        this->lines_coords_Y << this->lines.last()->geometry().y();
                        this->lines_coords_X << this->lines.last()->geometry().x();
                    }
                    this->rl << new QLabel(ui->scrollAreaWidgetContents);
                    this->rl.last()->setText(QString::number(1804.6-248*ijj));
                    this->rl.last()->move(2205+100*ijj, 5200 + 5000*(((i+1)/5)-1));
                    this->rl.last()->show();
                    this->rl_coords_Y << this->rl.last()->geometry().y();
                    this->rl_coords_X << this->rl.last()->geometry().x();
                    this->rl << new QLabel(ui->scrollAreaWidgetContents);
                    this->rl.last()->setText(QString::number(2103.7-128*ijj));
                    this->rl.last()->move(2265+100*ijj, 5200 + 5000*(((i+1)/5)-1));
                    this->rl.last()->show();
                    this->rl_coords_Y << this->rl.last()->geometry().y();
                    this->rl_coords_X << this->rl.last()->geometry().x();

                    this->rl << new QLabel(ui->scrollAreaWidgetContents);
                    this->rl.last()->setText(QString::number(2356-248*ijj));
                    this->rl.last()->move(2120, 5105 + 5000*(((i+1)/5)-1)-(25+1000*ijj));
                    this->rl.last()->show();
                    this->rl_coords_Y << this->rl.last()->geometry().y();
                    this->rl_coords_X << this->rl.last()->geometry().x();

                }
                this->rl << new QLabel(ui->scrollAreaWidgetContents);
                this->rl.last()->setText("ТГ "+QString::number((i+1)/25));
                this->rl.last()->move(2170, 5165 + 5000*(((i+1)/5)-1));
                this->rl.last()->show();
                this->rl_coords_Y << this->rl.last()->geometry().y();
                this->rl_coords_X << this->rl.last()->geometry().x();
            }
        }
    }

    ui->label_2->setText(QString::number(horyzontal_triangle.last()->geometry().bottom()));
    this->setVerticalScrollBarRange();
    this->setHorizontalScrollBarRange();
}

void MainWindow::setVerticalScrollBarRange()
{
    if(!this->vertical_triangle_coords_Y.isEmpty())
        if(this->vertical_triangle_coords_Y.last() > 300)
            ui->verticalScrollBar->setRange(0,this->vertical_triangle_coords_Y.last() - 300);
        else
            ui->verticalScrollBar->setRange(0,0);
    else
        ui->horizontalScrollBar->setRange(0,0);
}

void MainWindow::setHorizontalScrollBarRange()
{
    if(!this->horyzontal_triangle_coords_X.isEmpty())
        if(this->horyzontal_triangle_coords_X.last() > 300)
            ui->horizontalScrollBar->setRange(0,this->horyzontal_triangle_coords_X.last()+500);
        else
            ui->horizontalScrollBar->setRange(0,0);
    else
        ui->horizontalScrollBar->setRange(0,0);
}

void MainWindow::on_pushButton_2_clicked() //clear memory
{
    for(auto i : this->vertical_triangle) delete i;
    this->vertical_triangle.clear();
    this->vertical_triangle_coords_X.clear();
    this->vertical_triangle_coords_Y.clear();

    for(auto i : horyzontal_triangle) delete i;
    this->horyzontal_triangle.clear();
    this->horyzontal_triangle_coords_X.clear();
    this->horyzontal_triangle_coords_Y.clear();

    for(auto i : this->lines) delete i;
    this->lines.clear();
    this->lines_coords_X.clear();
    this->lines_coords_Y.clear();

    for(auto i : this->rl) delete i;
    this->rl.clear();
    this->rl_coords_X.clear();
    this->rl_coords_Y.clear();
}

void MainWindow::on_verticalScrollBar_sliderMoved(int p)
{
    for(int i = 0; i < this->vertical_triangle.size(); i++){
        this->vertical_triangle.at(i)->move(this->vertical_triangle.at(i)->geometry().x(), this->vertical_triangle_coords_Y.at(i)-p);
    }
    for(int i = 0; i < this->horyzontal_triangle.size(); i++){
        this->horyzontal_triangle.at(i)->move(this->horyzontal_triangle.at(i)->geometry().x(), this->horyzontal_triangle_coords_Y.at(i)-p);
    }
    for(int i = 0; i < this->lines.size(); i++){
        this->lines.at(i)->move(this->lines.at(i)->geometry().x(), this->lines_coords_Y.at(i)-p);
    }
    for(int i = 0; i < this->rl.size(); i++){
        this->rl.at(i)->move(this->rl.at(i)->geometry().x(), this->rl_coords_Y.at(i)-p);
    }
}

void MainWindow::on_horizontalScrollBar_sliderMoved(int p)
{
    for(int i = 0; i < this->vertical_triangle.size(); i++){
        this->vertical_triangle.at(i)->move(this->vertical_triangle_coords_X.at(i)-p, this->vertical_triangle.at(i)->geometry().y());
    }
    for(int i = 0; i < this->horyzontal_triangle.size(); i++){
        this->horyzontal_triangle.at(i)->move(this->horyzontal_triangle_coords_X.at(i)-p, this->horyzontal_triangle.at(i)->geometry().y());
    }
    for(int i = 0; i < this->lines.size(); i++){
        this->lines.at(i)->move(this->lines_coords_X.at(i)-p, this->lines.at(i)->geometry().y());
    }
    for(int i = 0; i < this->rl.size(); i++){
        this->rl.at(i)->move(this->rl_coords_X.at(i)-p, this->rl.at(i)->geometry().y());
    }
}
