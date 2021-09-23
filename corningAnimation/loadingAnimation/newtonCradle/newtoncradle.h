#ifndef NEWTONCRADLE_H
#define NEWTONCRADLE_H

#include <QWidget>

class NewtonCradle : public QWidget
{
    Q_OBJECT
public:
    explicit NewtonCradle(QWidget *parent = nullptr);

protected:
    void paintEvent(QEvent *event) override;

signals:

};

#endif // NEWTONCRADLE_H
