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

    int screenWidth = desktop->width();
    int screenHeight = desktop->height();

    // center the window
    this->move((screenWidth - RPM_MAINWINDOW_MINIMUM_WIDTH) / 2,
        (screenHeight - RPM_MAINWINDOW_MINIMUM_HEIGHT) / 2);
#else // ifndef _DEBUG
    this->move(0, 0);
#endif // ifndef _DEBUG
}

void MainWindow::setupMenuBar() {
    _D("init main window: set menubar");

    theMenuBar = new MenuBar();
    this->setMenuBar(theMenuBar);
}

void MainWindow::setupStatusBar() {
    _D("init main window: set statusbar");

    theStatusBar = new StatusBar();
    this->setStatusBar(theStatusBar);
}

void MainWindow::setupTabBar() {
    _D("init main window: set tagbar");

    theTabBar = new TabBar();
    this->setCentralWidget(theTabBar);

    theProcessTableWidget = theTabBar->processTableWidget();
}

} // namespace rpm
