#ifndef _RPM_MENUBAR_H
#define _RPM_MENUBAR_H 1

#include <QMenuBar>

namespace rpm {

class MenuBar : public QMenuBar {
    Q_OBJECT

public:
    MenuBar();

signals:
    void help();
    void about();
    void aboutQt();
    void forkMeOnGithub();
    void setRefreshRate(qint32);

private slots:
    void refreshRate100ms();
    void refreshRate500ms();
    void refreshRate1000ms();
    void refreshRate2000ms();
};

} // namespace rpm

#endif // ifndef _RPM_MENUBAR_H
