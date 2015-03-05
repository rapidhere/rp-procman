#ifndef _RPM_STATUSBAR_H
#define _RPM_STATUSBAR_H 1

#include <QStatusBar>

namespace rpm {

class StatusBar : public QStatusBar {
    Q_OBJECT

public:
    StatusBar();
};

} // namespace rpm

#endif // ifndef _RPM_STATUSBAR_H
