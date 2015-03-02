#if defined _RPM_QT_WIDGET_VERSION
#include "widgets/Application.h"

#elif defined _RPM_QT_QML_VERSIN
#include "qml-widgets/Appllication.h"

#endif

int main(int argc, char *argv[]) {
    rpm::Application *app = new rpm::Application(argc, argv);
    return app->exec();
}
