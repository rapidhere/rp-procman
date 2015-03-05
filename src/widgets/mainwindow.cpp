#include "mainwindow.h"
#include "menubar.h"
#include "../defs.h"

#include <QApplication>
#include <QDesktopWidget>

namespace rpm {

MainWindow::MainWindow() : QMainWindow() {
    setupLayout();
    setupMenuBar();
}

void MainWindow::setupLayout() {
    _D("init main window: set layout");

    // set the window title
    this->setWindowTitle(tr(RPM_MAINWINDOW_TITLE));

    // set minimum and init size
    this->setMinimumSize(RPM_MAINWINDOW_MINIMUM_WIDTH, RPM_MAINWINDOW_MINIMUM_HEIGHT);
    this->resize(RPM_MAINWINDOW_MINIMUM_WIDTH, RPM_MAINWINDOW_MINIMUM_HEIGHT);

    // center the window
    // get the desktop size
#ifndef _DEBUG
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

    this->setMenuBar(new MenuBar());
}

} // namespace rpm
