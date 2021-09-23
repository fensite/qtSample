#include <QBoxLayout>
#include <QPushButton>
#include <QPropertyAnimation>
#include <QDesktopWidget>
#include <QApplication>
#include <QTimer>

#include "mainwindow.h"

#include "loadingAnimation/newtonCradle/ball.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(600,400);
    initUI();
}

MainWindow::~MainWindow()
{
}

void MainWindow::initUI()
{
    mainWidget = new QWidget(this);
    QVBoxLayout *mainLaout = new QVBoxLayout(mainWidget);
    mainLaout->setContentsMargins(0, 0, 0, 0);

    QPushButton *pb_drop = new QPushButton(mainWidget);
    pb_drop->setText("下坠效果");
    connect(pb_drop, &QPushButton::clicked, this, &MainWindow::onDropWindow);

    QPushButton *pb_shake = new QPushButton(mainWidget);
    pb_shake->setText("抖动效果");
    connect(pb_shake, &QPushButton::clicked, this, &MainWindow::onShakeWindow);


    QPushButton *pb_opacity = new QPushButton(mainWidget);
    pb_opacity->setText("透明度效果");
    connect(pb_opacity, &QPushButton::clicked, this, &MainWindow::onOpacityWindow);

    Ball *ball = new Ball(mainWidget);

    mainLaout->addWidget(pb_drop, Qt::AlignCenter);
    mainLaout->addWidget(pb_shake, Qt::AlignCenter);
    mainLaout->addWidget(pb_opacity, Qt::AlignCenter);
    mainLaout->addWidget(ball, Qt::AlignCenter);
    mainWidget->adjustSize();
    mainWidget->setGeometry(width()/2 - mainWidget->width()/2, this->height()/2 - mainWidget->height()/2,
                            mainWidget->width(), mainWidget->height());
}

void MainWindow::onDropWindow()
{
    QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "geometry");

    QDesktopWidget *pDesktopWidget = QApplication::desktop();
    int x = (pDesktopWidget->availableGeometry().width() - width()) / 2;
    int y = (pDesktopWidget->availableGeometry().height() - height()) / 2;

    pAnimation->setDuration(5000);
    pAnimation->setStartValue(QRect(x, 0, width(), height()));
    pAnimation->setEndValue(QRect(x, y, width(), height()));
    pAnimation->setEasingCurve(QEasingCurve::OutElastic);
    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    QTimer::singleShot(500,this, [=]{
        pAnimation->stop();
    });
}

void MainWindow::onShakeWindow()
{
    QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "pos");
    pAnimation->setDuration(1000);
    pAnimation->setLoopCount(2);
    pAnimation->setKeyValueAt(0, QPoint(geometry().x() - 3, geometry().y() - 3));
    pAnimation->setKeyValueAt(0.1, QPoint(geometry().x() + 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(0.2, QPoint(geometry().x() - 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(0.3, QPoint(geometry().x() + 6, geometry().y() - 6));
    pAnimation->setKeyValueAt(0.4, QPoint(geometry().x() - 6, geometry().y() - 6));
    pAnimation->setKeyValueAt(0.5, QPoint(geometry().x() + 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(0.6, QPoint(geometry().x() - 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(0.7, QPoint(geometry().x() + 6, geometry().y() - 6));
    pAnimation->setKeyValueAt(0.8, QPoint(geometry().x() - 6, geometry().y() - 6));
    pAnimation->setKeyValueAt(0.9, QPoint(geometry().x() + 6, geometry().y() + 6));
    pAnimation->setKeyValueAt(1, QPoint(geometry().x() - 3, geometry().y() - 3));
    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::onOpacityWindow()
{
    QPropertyAnimation *pAnimation = new QPropertyAnimation(this, "windowOpacity");
    pAnimation->setDuration(1000);
    pAnimation->setKeyValueAt(0, 1);
    pAnimation->setKeyValueAt(0.5, 0);
    pAnimation->setKeyValueAt(1, 1);
    pAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}


