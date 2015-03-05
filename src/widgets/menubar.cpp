#include "menubar.h"
#include "../defs.h"

#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

namespace rpm {

MenuBar::MenuBar() : QMenuBar() {
    // add help
    QMenu *m = this->addMenu(tr(RPM_MENUBAR_HELP_MENU_TITLE));

    // help -> help
    QAction *a = m->addAction(tr(RPM_MENUBAR_HELP_MENU_HELP_TITLE));
    connect(a, SIGNAL(triggered()), this, SLOT(help()));

    m->addSeparator();

    // help -> about
    a = m->addAction(tr(RPM_MENUBAR_HELP_MENU_ABOUT_TITLE));
    connect(a, SIGNAL(triggered()), this, SLOT(about()));

    // help -> about qt
    a = m->addAction(tr(RPM_MENUBAR_HELP_MENU_ABOUTQT_TITLE));
    connect(a, SIGNAL(triggered()), this, SLOT(aboutQt()));

    // help -> fork me on github
    a = m->addAction(tr(RPM_MENUBAR_HELP_MENU_FORK_TITLE));
    connect(a, SIGNAL(triggered()), this, SLOT(forkMeOnGithub()));

}

void MenuBar::help() {
    _D("menubar: on help");
}

void MenuBar::about() {
    _D("menubar: on about");

    QMessageBox::about(this, tr(RPM_DIALOG_ABOUT_TITLE),
        tr(RPM_DIALOG_ABOUT_CONTENT));
}

void MenuBar::aboutQt() {
    _D("menubar: on about_qt");

    QMessageBox::aboutQt(this);
}

void MenuBar::forkMeOnGithub() {
    _D("menubar: on fork_me_on_github");

    if(! QDesktopServices::openUrl(QUrl(RPM_FORK_ME_ON_GITHUB_URL))) { // open url failed
        _W("menubar: on fork_me_on_github: open url failed");
    }
}

} // namespace rpm
