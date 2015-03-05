#ifndef _RPM_TABBAR_H
#define _RPM_TABBAR_H 1

#include <QTabWidget>

namespace rpm {

class ProcessTableWidget;

class TabBar : public QTabWidget {
    Q_OBJECT

public:
    TabBar();

    ProcessTableWidget *processTableWidget();

private:
    ProcessTableWidget *theProcessTableWidget;
};

}

#endif // ifndef _RPM_TABBAR_H
