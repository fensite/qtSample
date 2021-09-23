#include "ball.h"
#include <QPalette>
#include <QLabel>
#include <QHBoxLayout>
#include <QRect>

Ball::Ball(QWidget *parent) : QWidget(parent)
{
    //this->setStyleSheet("QWidget::Ball{background-color: rgb(225, 225, 225);border:2px groove gray;border-radius:10px;padding:2px 4px;border-style: outset;}");
    this->setFixedSize(40, 40);

    this->setWindowFlags(Qt::FramelessWindowHint);   //设置无边框窗口
    this->setStyleSheet("QWidget{background-color:red;border-top-left-radius:12px;border-top-right-radius:12px;"
                        "border-bottom-left-radius:12px;"
                        "border-bottom-right-radius:12px;}");

//    QHBoxLayout *mainLayout = new QHBoxLayout(this);
//    QLabel *label = new QLabel(this);
//    label->setText("测试");
//    mainLayout->addWidget(label);
}
