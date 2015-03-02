#include "Application.h"

#include <QLabel>

namespace rpm {

Application::Application(int argc, char *argv[]) : QApplication(argc, argv) {
    QLabel *label = new QLabel("Hello World!");
    label->show();
}

} // namespace rpm
