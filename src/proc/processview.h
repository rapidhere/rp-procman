#ifndef _RPM_PROCESSVIEW_H
#define _RPM_PROCESSVIEW_H 1

#include "unistd.h"
#include "sys/types.h"

#include <QString>
#include <QVector>

namespace rpm {


class ProcessView {
public:
    typedef pid_t Pid;
    typedef char ProcessState;

    const static ProcessState StateSleep = 'S';
    const static ProcessState StateZombie = 'Z';
    const static ProcessState StateRunning = 'R';

public:
    virtual ~ProcessView();

    Pid pid() const;
    QString processName() const;
    QString commandLine() const;
    bool hasCommandLine() const;
    int virtualMemomrySize() const;
    ProcessState state() const;

    static ProcessView *fromProcFile(const QString &);

private:
    ProcessView();

    Pid thePid;
    QString theProcessName;
    QString theCommandLine;
    int theVmSize;
    ProcessState theState;

    static QString parseCommandLine(const QString &);
    static QString parseProcessName(const QString &);
    static void parseStatusFile(const QString &, ProcessView *);
};

} // namespace rpm

#endif // infndef _RPM_PROCESSVIEW_H
