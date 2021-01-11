#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebEngineHistory>
#include <QWebEnginePage>
#include <QSplitter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWindow *ui;
    QSplitter *m_webSplitter;
    QWebEngineView *m_WebView;
};

class MyWebEngineView : public QWebEngineView
{
    Q_OBJECT
public:
    MyWebEngineView(QWidget *parent = nullptr);
    ~MyWebEngineView();

protected:
    QWebEngineView *createWindow(QWebEnginePage::WebWindowType type) override;
};

#endif // MAINWINDOW_H
