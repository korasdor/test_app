#include "mainwindow.h"

#include <QCoreApplication>
#include <QApplication>
#include <QWebFrame>
#include <QDesktopWidget>
#include <QFileInfo>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::AcceleratedCompositingEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::WebGLEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::CSSRegionsEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::CSSGridLayoutEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::ScrollAnimatorEnabled, true);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::WebAudioEnabled, true);

    web = new QWebView(this);
    web->setRenderHint(QPainter::Antialiasing, true);
    web->setRenderHint(QPainter::SmoothPixmapTransform, true);
    web->resize(QApplication::desktop()->screenGeometry(0).size());
    web->page()->mainFrame()->setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
    web->page()->mainFrame()->setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
    web->showFullScreen();

    QString path = "/gui_kenoboom/bin/html5/bin/index.html";
    web->load(QUrl::fromLocalFile(QCoreApplication::applicationDirPath() + path));




}

MainWindow::~MainWindow()
{

}
