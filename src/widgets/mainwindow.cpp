#include "mainwindow.h"
#include "menubar.h"
#include "statusbar.h"
#include "tabbar.h"
#include "defs.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QLayout>

namespace rpm {

MainWindow::MainWindow() : QMainWindow() {
    setupMenuBar();
    setupStatusBar();
    setupTabBar();

    setupLayout();
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

} // namespace rpm
