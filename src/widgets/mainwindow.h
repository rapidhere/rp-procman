#ifndef _RPM_MAINDOW_H
#define _RPM_MAINDOW_H 1

#include <QMainWindow>

namespace rpm {

class MenuBar;
class StatusBar;
class TabBar;
class ProcessTableWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

private:
    void setupLayout();
    void setupMenuBar();
    void setupStatusBar();
    void setupTabBar();

private:
    MenuBar *theMenuBar;
    StatusBar *theStatusBar;
    TabBar *theTabBar;
    ProcessTableWidget *theProcessTableWidget;
};

} // namespace rpm

#endif // ifndef _RPM_MAINDOW_H
