#ifndef _RPM_MENUBAR_H
#define _RPM_MENUBAR_H 1

#include <QMenuBar>

namespace rpm {

class MenuBar : public QMenuBar {
    Q_OBJECT

public:
    MenuBar();

private slots:
    void help();
    void about();
    void aboutQt();
    void forkMeOnGithub();
};

} // namespace rpm

#endif // ifndef _RPM_MENUBAR_H
