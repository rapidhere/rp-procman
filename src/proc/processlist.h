#ifndef _RPM_PROCESSLIST_H
#define _RPM_PROCESSLIST_H 1

#include <QVector>

#include "processview.h"

namespace rpm {

class ProcessList : public QVector<ProcessView*> {
public:
    ProcessList();
    virtual ~ProcessList();

    void refresh();
    virtual void clear();

private:
    static bool isDigit(const char *);
};

} // namespace rpm

#endif // ifndef _RPM_PROCESSLIST_H
