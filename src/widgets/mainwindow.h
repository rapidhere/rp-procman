#ifndef _RPM_MAINDOW_H
#define _RPM_MAINDOW_H 1

#include <QMainWindow>

namespace rpm {

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

private:
    void setupLayout();
    void setupMenuBar();
};

} // namespace rpm

#endif // ifndef _RPM_MAINDOW_H 
