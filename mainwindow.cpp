#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QString>
#include <QMessageBox>
#include <boost/Multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
using boost::multiprecision::cpp_dec_float_100;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), A(0,0), B(0, 0), C(0, 0)

{
    ui->setupUi(this);
    ui->leAx->setText(QString::number(0));
    ui->leAy->setText(QString::number(0));
    ui->leBx->setText(QString::number(0));
    ui->leBy->setText(QString::number(0));
    ui->leCx->setText(QString::number(0));
    ui->leCy->setText(QString::number(0));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    {
        bool ok;
        ui->leAx->text().toDouble(&ok);
        if(ok)
        {
            A.x = cpp_dec_float_100 (ui->leAx->text().toStdString());
            if (abs(A.x) > (ui->widget->geometry().width())/2)
            {
                QMessageBox::warning(this, "Предупреждение", "Координата x точки A выходит за пределы области");
            }
        }
        else//
        {
            QMessageBox::warning(this, "Ошибка ввода", "Неправильный ввод");
            ui->leAx->setText(QString::number(0));
        }
    }
    {
        bool ok;
        ui->leAy->text().toDouble(&ok);
        if(ok)
        {
            A.y = cpp_dec_float_100 (ui->leAy->text().toStdString());
            if (abs(A.y) > (ui->widget->geometry().height())/2)
            {
                QMessageBox::warning(this, "Предупреждение", "Координата y точки A выходит за пределы области");
            }
        }

        else
        {
            QMessageBox::warning(this, "Ошибка ввода", "Неправильный ввод");
            ui->leAy->setText(QString::number(0));
        }
    }

    {
        bool ok;
        ui->leBx->text().toDouble(&ok);
        if(ok)
        {
            B.x = cpp_dec_float_100 (ui->leBx->text().toStdString());
            if (abs(B.x) > (ui->widget->geometry().width())/2)
            {
                QMessageBox::warning(this, "Предупреждение", "Координата x точки B выходит за пределы области");
            }
        }
        else
        {
            QMessageBox::warning(this, "Ошибка ввода", "Неправильный ввод");
            ui->leBx->setText(QString::number(0));
        }
    }
    {
        bool ok;
        ui->leBy->text().toDouble(&ok);
        if(ok)
        {
            B.y = cpp_dec_float_100 (ui->leBy->text().toStdString());
            if (abs(B.y) > (ui->widget->geometry().height())/2)
            {
                QMessageBox::warning(this, "Предупреждение", "Координата y точки B выходит за пределы области");
            }
        }
        else
        {
            QMessageBox::warning(this, "Ошибка ввода", "Неправильный ввод");
            ui->leBy->setText(QString::number(0));
        }
    }
    {
        bool ok;
        ui->leCx->text().toDouble(&ok);
        if(ok)
        {
            C.x = cpp_dec_float_100 (ui->leCx->text().toStdString());
            if (abs(C.x) > (ui->widget->geometry().width())/2)
            {
                QMessageBox::warning(this, "Предупреждение", "Координата x точки C выходит за пределы области");
            }
        }
        else
        {
            QMessageBox::warning(this, "Ошибка ввода", "Неправильный ввод");
            ui->leCx->setText(QString::number(0));
        }
    }
    {
        bool ok;
        ui->leCy->text().toDouble(&ok);
        if(ok)
        {
            C.y = cpp_dec_float_100 (ui->leCy->text().toStdString());
            if (abs(C.y) > (ui->widget->geometry().height())/2)
            {
                QMessageBox::warning(this, "Предупреждение", "Координата y точки C выходит за пределы области");
            }

        }
        else
        {
            QMessageBox::warning(this, "Ошибка ввода", "Неправильный ввод");
            ui->leCy->setText(QString::number(0));
        }
    }


    //предикат

     double k = double((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
     double l = double((B.x - A.x) * (C.y - A.y));
     double r = double((C.x - A.x) * (B.y - A.y));
     double e = (abs(l) + abs( r)) * std::numeric_limits<double>::epsilon() * 4;
    if (k > e)
    {
        ui->label_result->setText("cправа по направлению от A к B");
    }
    else if (k < -e)
    {
        ui->label_result->setText("cлева по направлению от A к B");
    }
    else
    {
        cpp_dec_float_100 k = (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
        if (k > 0)
        {
            ui->label_result->setText("cправа по направлению от A к B");
        }
        else if (k < 0)
        {
            ui->label_result->setText("cлева по направлению от A к B");
        }
        else if (k ==0 && ((C.x<A.x) || (C.x>B.x)))
        {
            ui->label_result->setText("на прямой, содержащей отрезок");
        }
        else
        {
            ui->label_result->setText("на отрезке");
        }
    }
    ui->widget->Print(ui);
    ui->widget->repaint();
}

void MainWindow::on_pushButton_2_clicked()
{
    cpp_dec_float_100 Ax = 3.0, Ay = 5.0, Bx = -3.0, By = -5.0, Cx = 3.0*(1LL<<52), Cy = 5.0*(1LL<<52);
    ui->leAx->setText(QString::fromStdString(Ax.str()));
    ui->leBx->setText(QString::fromStdString(Bx.str()));
    ui->leAy->setText(QString::fromStdString(Ay.str()));
    ui->leBy->setText(QString::fromStdString(By.str()));
    ui->leCx->setText(QString::fromStdString(Cx.str()));
    ui->leCy->setText(QString::fromStdString(Cy.str()));
    on_pushButton_clicked();
}


