#ifndef UDRAWWIDGET_H
#define UDRAWWIDGET_H


#include <QObject>
#include <QWidget>
#include <QPainter>
#include "mainwindow.h"
//#include <boost/Multiprecision/cpp_dec_float.hpp>
//#include <boost/math/constants/constants.hpp>
//using boost::multiprecision::cpp_dec_float_100;


class UDrawWidget : public QWidget
{
    Q_OBJECT


public:
    explicit UDrawWidget(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event);
    void Print(Ui::MainWindow *ui);
    int A_x = 0, A_y = 0, B_x = 0, B_y = 0, C_x = 0, C_y = 0;

signals:

};

#endif // UDRAWWIDGET_H
