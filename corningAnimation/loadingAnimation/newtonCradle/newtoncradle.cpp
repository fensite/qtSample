#include "newtoncradle.h"
#include <QSlider>

NewtonCradle::NewtonCradle(QWidget *parent) : QWidget(parent)
{
    this->setAttribute(Qt::WA_TranslucentBackground, true);

}

NewtonCradle::paintEvent(QEvent *event)
{

}
