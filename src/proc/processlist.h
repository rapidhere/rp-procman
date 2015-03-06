#ifndef _RPM_PROCESSLIST_H
#define _RPM_PROCESSLIST_H 1

#include <QVector>

#include "processview.h"

namespace rpm {

class ProcessList : public QVector<ProcessView*> {
public:
    ProcessList();
    virtual ~ProcessList();
};

} // namespace rpm

#endif // ifndef _RPM_PROCESSLIST_H
