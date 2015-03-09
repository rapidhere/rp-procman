#include "menubar.h"
#include "defs.h"

#include <QActionGroup>

namespace rpm {

MenuBar::MenuBar() : QMenuBar() {
    // add setting
    QMenu *m = this->addMenu(tr(RPM_MENUBAR_SETTING_MENU_TITLE));

    // setting -> refresh rate / 100ms / 500ms / 1000ms / 2000ms
    QMenu *sm = m->addMenu(tr(RPM_MENUBAR_SETTING_MENU_REFRESHRATE_TITLE));
    QActionGroup *am = new QActionGroup(this);
    am->setExclusive(true);

    QAction *a = am->addAction(tr(RPM_MENUBAR_SETTING_MENU_REFRESHRATE_100MS));
    a->setCheckable(true);
    connect(a, SIGNAL(triggered()), this, SLOT(refreshRate100ms()));
    sm->addAction(a);

    a = am->addAction(tr(RPM_MENUBAR_SETTING_MENU_REFRESHRATE_500MS));
    a->setCheckable(true);
    connect(a, SIGNAL(triggered()), this, SLOT(refreshRate500ms()));
    sm->addAction(a);

    a = am->addAction(tr(RPM_MENUBAR_SETTING_MENU_REFRESHRATE_1000MS));
    a->setCheckable(true);
    connect(a, SIGNAL(triggered()), this, SLOT(refreshRate1000ms()));
    a->setChecked(true);
    sm->addAction(a);

    a = am->addAction(tr(RPM_MENUBAR_SETTING_MENU_REFRESHRATE_2000MS));
    a->setCheckable(true);
    connect(a, SIGNAL(triggered()), this, SLOT(refreshRate2000ms()));
    sm->addAction(a);

    // add help
    m = this->addMenu(tr(RPM_MENUBAR_HELP_MENU_TITLE));

    // help -> help
    a = m->addAction(tr(RPM_MENUBAR_HELP_MENU_HELP_TITLE));
    connect(a, SIGNAL(triggered()), this, SIGNAL(help()));

    m->addSeparator();

    // help -> about
    a = m->addAction(tr(RPM_MENUBAR_HELP_MENU_ABOUT_TITLE));
    connect(a, SIGNAL(triggered()), this, SIGNAL(about()));

    // help -> about qt
    a = m->addAction(tr(RPM_MENUBAR_HELP_MENU_ABOUTQT_TITLE));
    connect(a, SIGNAL(triggered()), this, SIGNAL(aboutQt()));

    // help -> fork me on github
    a = m->addAction(tr(RPM_MENUBAR_HELP_MENU_FORK_TITLE));
    connect(a, SIGNAL(triggered()), this, SIGNAL(forkMeOnGithub()));
}

void MenuBar::refreshRate100ms() {
    emit setRefreshRate(100);
}

void MenuBar::refreshRate500ms() {
    emit setRefreshRate(500);
}

void MenuBar::refreshRate1000ms() {
    emit setRefreshRate(1000);
}

void MenuBar::refreshRate2000ms() {
    emit setRefreshRate(2000);
}

} // namespace rpm
