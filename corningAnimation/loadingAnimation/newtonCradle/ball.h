#ifndef BALL_H
#define BALL_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class Ball : public QWidget
{
    Q_OBJECT
public:
    explicit Ball(QWidget *parent = nullptr);

signals:

};

#endif // BALL_H
