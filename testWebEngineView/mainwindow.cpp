#include <QWebEngineView>
#include <QNetworkConfigurationManager>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_webSplitter(new QSplitter(this))
{
    ui->setupUi(this);
    m_webSplitter->setMinimumSize(400,600);
    m_WebView = new MyWebEngineView(this);
    QString str = "https://www.baidu.com/baidu?tn=ubuntuu_cb&ie=utf-8&wd=王一博";
    QUrl url = QUrl(str.toLocal8Bit());
    m_WebView->setMinimumSize(QSize(500, 300));
    m_WebView->load(url);

    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(m_webSplitter->sizePolicy().hasHeightForWidth());
    m_webSplitter->setSizePolicy(sizePolicy);

    connect(m_WebView, &QWebEngineView::titleChanged, this , [=](const QString& title){
        qDebug() << "--------------------titleChanged" << title;
    });
    connect(m_WebView, &QWebEngineView::urlChanged, this ,[=](const QUrl& url){
        qDebug() << "--------------------urlChanged " << url;
    });
    connect(m_WebView, &QWebEngineView::selectionChanged, this ,[=]{
        qDebug() << "--------------------selectionChanged " << m_WebView->selectedText();
    });

    QNetworkConfigurationManager mgr;
    qDebug() << "是否联网:" << mgr.isOnline();
    connect(&mgr, &QNetworkConfigurationManager::onlineStateChanged,this, [=](bool isOnline){
        qDebug()<<"网络已经更改"<<isOnline;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    m_webSplitter->adjustSize();
    m_WebView->resize(this->width(), this->height());
}

MyWebEngineView::MyWebEngineView(QWidget *parent) : QWebEngineView(parent)
{
}

MyWebEngineView::~MyWebEngineView()
{
}

QWebEngineView* MyWebEngineView::createWindow(QWebEnginePage::WebWindowType type)
{
    qDebug() << "-----------------createWindow " << type;
    qDebug() << "-----------------createWindow url " << url();
    return this;
}
