#include "mainwindow.h"
#include "menubar.h"
#include "statusbar.h"
#include "tabbar.h"
#include "defs.h"
#include "proc/systemview.h"
#include "processtablewidget.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QLayout>
#include <QTimer>
#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

namespace rpm {

MainWindow::MainWindow() : QMainWindow() {
    setupMenuBar();
    setupStatusBar();
    setupTabBar();

    setupLayout();

    // setup timer
    _system_view_refresh_timer = new QTimer(this);
    connect(_system_view_refresh_timer, SIGNAL(timeout()), this, SLOT(refreshSystemView()));
    _system_view_refresh_timer->start(1000);
}

void MainWindow::setupLayout() {
    _D("init main window: set layout");

    // set the window title
    this->setWindowTitle(tr(RPM_MAINWINDOW_TITLE));

    // set minimum and init size
    this->setMinimumSize(RPM_MAINWINDOW_MINIMUM_WIDTH, RPM_MAINWINDOW_MINIMUM_HEIGHT);
    this->resize(RPM_MAINWINDOW_MINIMUM_WIDTH, RPM_MAINWINDOW_MINIMUM_HEIGHT);

#ifndef _DEBUG
    // center the window
    // get the desktop size
    QDesktopWidget *desktop = QApplication::desktop();

    int screen_width = desktop->width();
    int screen_height = desktop->height();

    // center the window
    this->move((screen_width - RPM_MAINWINDOW_MINIMUM_WIDTH) / 2,
        (screen_height - RPM_MAINWINDOW_MINIMUM_HEIGHT) / 2);
#else // ifndef _DEBUG
    this->move(0, 0);
#endif // ifndef _DEBUG
}

void MainWindow::setupMenuBar() {
    _D("init main window: set menubar");

    _menu_bar = new MenuBar();
    this->setMenuBar(_menu_bar);

    // connect menu bar signals
    connect(_menu_bar, SIGNAL(help()), this, SLOT(showHelp()));
    connect(_menu_bar, SIGNAL(about()), this, SLOT(showAbout()));
    connect(_menu_bar, SIGNAL(aboutQt()), this, SLOT(showAboutQt()));
    connect(_menu_bar, SIGNAL(forkMeOnGithub()), this, SLOT(forkMeOnGithub()));
    connect(_menu_bar, SIGNAL(setRefreshRate(qint32)), this, SLOT(setRefreshRate(qint32)));
}

void MainWindow::setupStatusBar() {
    _D("init main window: set statusbar");

    _status_bar = new StatusBar();
    this->setStatusBar(_status_bar);
}

void MainWindow::setupTabBar() {
    _D("init main window: set tagbar");

    _tab_bar = new TabBar();
    this->setCentralWidget(_tab_bar);

    _process_table_widget = _tab_bar->processTableWidget();
}

void MainWindow::refreshSystemView() {
    _D("refreshing ...");

    SystemView::getSystemView()->refresh();
    _process_table_widget->refresh();
}

void MainWindow::showHelp() {
    _D("menubar: on help");
}

void MainWindow::showAbout() {
    _D("menubar: on about");

    QMessageBox::about(this, tr(RPM_DIALOG_ABOUT_TITLE),
        tr(RPM_DIALOG_ABOUT_CONTENT));
}

void MainWindow::showAboutQt() {
    _D("menubar: on about_qt");

    QMessageBox::aboutQt(this);
}

void MainWindow::forkMeOnGithub() {
    _D("menubar: on fork_me_on_github");

    if(! QDesktopServices::openUrl(QUrl(RPM_FORK_ME_ON_GITHUB_URL))) { // open url failed
        _W("menubar: on fork_me_on_github: open url failed");
    }
}

void MainWindow::setRefreshRate(qint32 interval) {
    this->_system_view_refresh_timer->setInterval(interval);
}

} // namespace rpm
