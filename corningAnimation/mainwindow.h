#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initUI();
    QWidget *mainWidget;

private Q_SLOTS:
    void onDropWindow();
    void onShakeWindow();
    void onOpacityWindow();
};
#endif // MAINWINDOW_H
