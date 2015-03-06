#ifndef _RPM_PROCESSVIEW_H
#define _RPM_PROCESSVIEW_H 1

#include "unistd.h"
#include "sys/types.h"

#include <QString>
#include <QVector>

namespace rpm {

typedef pid_t Pid;

class ProcessView {
public:
    ProcessView();
    virtual ~ProcessView();

    Pid pid();
    QString *processName();

private:
    Pid thePid;
    QString *theProcessName;
};

} // namespace rpm

#endif // infndef _RPM_PROCESSVIEW_H
