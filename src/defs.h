#ifndef _RPM_DEFS_H
#define _RPM_DEFS_H 1

# include <iostream>

// the style of app
#define RPM_APP_STYLE "fusion"

// Debug info tool
#ifdef _DEBUG
# define _D(msg) std::cerr << "LINE " <<  __LINE__ << " in " << "`" __FILE__ "`: " << msg << std::endl;
#else
# define _D(msg)
#endif

// Warning info
#define _W(msg) std::cerr << "Warning: " << msg << std::endl;

// Error info
#define _E(msg) std::cerr << "ERROR: " << msg << std::endl;

// version, load from cmake
#define RPM_VERSION_MAJOR @RPM_VersionMajor@
#define RPM_VERSION_MINOR @RPM_VersionMinor@

// minimum size
#define RPM_MAINWINDOW_MINIMUM_WIDTH 600
#define RPM_MAINWINDOW_MINIMUM_HEIGHT 400

// the title of the window
#define RPM_MAINWINDOW_TITLE "RapiD's Process Mananger"

// the menubar settings
#define RPM_MENUBAR_HELP_MENU_TITLE "&help"
#define RPM_MENUBAR_HELP_MENU_HELP_TITLE "&Help"
#define RPM_MENUBAR_HELP_MENU_ABOUT_TITLE "&About"
#define RPM_MENUBAR_HELP_MENU_ABOUTQT_TITLE "About QT"
#define RPM_MENUBAR_HELP_MENU_FORK_TITLE "Fork me on github"
#define RPM_MENUBAR_SETTING_MENU_TITLE "&setting"
#define RPM_MENUBAR_SETTING_MENU_REFRESHRATE_TITLE "Refresh rate"
#define RPM_MENUBAR_SETTING_MENU_REFRESHRATE_100MS "100 ms"
#define RPM_MENUBAR_SETTING_MENU_REFRESHRATE_500MS "500 ms"
#define RPM_MENUBAR_SETTING_MENU_REFRESHRATE_1000MS "1 s"
#define RPM_MENUBAR_SETTING_MENU_REFRESHRATE_2000MS "2 s"

// About dialog
#define RPM_DIALOG_ABOUT_TITLE "About RapiD's Process Manager"
#define RPM_DIALOG_ABOUT_CONTENT "<p style=\"font-size: 24px\"><strong>Copyright</strong> rapidhere@gmail.com</p><p>A simple process manager woking on linux</p>"

// fork me on github
#define RPM_FORK_ME_ON_GITHUB_URL "https://github.com/rapidhere/rp-procman"

// process table tab bar
#define RPM_TABBAR_PROCESS_TABLE_TITLE "Overview"

#endif // ifndef _RPM_DEFS_H
