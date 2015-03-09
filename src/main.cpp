#if defined _RPM_QT_WIDGET_VERSION
#include "widgets/MainWindow"

#elif defined _RPM_QT_QML_VERSIN
#include "qml-widgets/MainWindow"

#endif

#include <QApplication>
#include <QStyleFactory>
#include "defs.h"

int main(int argc, char *argv[]) {
    // create app
    QApplication *app = new QApplication(argc, argv);

    // set style
    app->setStyle(QStyleFactory::create(RPM_APP_STYLE));

    // run main window
    rpm::MainWindow *win = new rpm::MainWindow();
    win->show();

    // run app
    return app->exec();
}
