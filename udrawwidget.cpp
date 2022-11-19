#include "udrawwidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPen>
#include <QString>
#include "ui_mainwindow.h"


UDrawWidget::UDrawWidget(QWidget *parent)
    : QWidget(parent)
{

}
void UDrawWidget::Print(Ui::MainWindow *ui)
{
    QString Ax = ui->leAx->text();
    QString Ay = ui->leAy->text();
    QString Bx = ui->leBx->text();
    QString By = ui->leBy->text();
    QString Cx = ui->leCx->text();
    QString Cy = ui->leCy->text();
    int W =  ui->widget->geometry().width();
    int H =  ui->widget->geometry().height();
    A_x = Ax.toDouble() + W/2;
    A_y = Ay.toDouble() + H/2;
    B_x = Bx.toDouble() + W/2;
    B_y = By.toDouble() + H/2;
    C_x = Cx.toDouble() + W/2;
    C_y = Cy.toDouble() + H/2;
}


void UDrawWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawLine(A_x, A_y, B_x, B_y);
    painter.setPen(Qt::red);
    painter.drawEllipse(A_x - 2.5, A_y - 2.5, 5.0, 5.0);
    painter.drawEllipse(B_x - 2.5, B_y - 2.5, 5, 5);
    painter.drawEllipse(C_x - 2.5, C_y - 2.5, 5, 5);
    painter.setPen(Qt::blue);
    painter.drawText(C_x + 5, C_y+5, "C");
    painter.drawText(A_x + 5, A_y+5, "A");
    painter.drawText(B_x + 5, B_y+5, "B");

}







