#ifndef _RPM_APPLICATION_H
#define _RPM_APPLICATION_H 1

#include <QApplication>
#include "../defs.h"

namespace rpm {

class Application : public QApplication {
public:
    Application(int argc, char *argv[]);
};

} // namespace rpm

#endif // ifndef _RPM_APPLICATION_H
