#ifndef _RPM_PROCESSVIEW_H
#define _RPM_PROCESSVIEW_H 1

#include <QString>
#include <QVector>

namespace rpm {

class ProcessView {
public:
    typedef char ProcessState;

    const static ProcessState StateSleeping = 'S';
    const static ProcessState StateZombie = 'Z';
    const static ProcessState StateRunning = 'R';
    const static ProcessState StateUninterruptibleSleeping = 'D';
    const static ProcessState StateStopped = 'T';
    const static ProcessState StatePaging = 'W';

public:
    virtual ~ProcessView();

    qint32 pid() const;
    QString processName() const;
    QString commandLine() const;
    bool hasCommandLine() const;
    quint64 virtualMemomrySize() const;
    ProcessState state() const;

    static ProcessView *fromProcFile(const QString &);

private:
    ProcessView();

    // /proc/[pid]/cmdline
    QString         _command_line;

    // /proc/[pid]/stat
    qint32          _pid;
    QString         _process_name;
    ProcessState    _state;
    qint32          _ppid;
    qint32          _pgrp;
    qint32          _session;
    qint32          _tty_nr;
    qint32          _tpgid;
    quint32         _flags;
    quint64         _minflt;
    quint64         _cminflt;
    quint64         _majflt;
    quint64         _cmajflt;
    quint64         _utime;
    quint64         _stime;
    qint64          _cutime;
    qint64          _cstime;
    qint64          _priority;
    qint64          _nice;
    qint64          _num_threads;
    qint64          _itrealvalue;
    quint64         _start_time;
    quint64         _vsize;
    qint64          _rss;
    quint64         _rsslim;
    quint64         _startcode;
    quint64         _endcode;
    quint64         _startstack;
    quint64         _kstkesp;
    quint64         _kstkeip;
    quint64         _signal;
    quint64         _blocked;
    quint64         _sigignore;
    quint64         _sigcatch;
    quint64         _wchan;
    quint64         _nswap;
    quint64         _cnswap;
    qint32          _exit_signal;
    qint32          _processor;
    quint32         _rt_priority;
    quint32         _policy;
    quint64         _delayacct_blkio_ticks;
    quint64         _guest_time;
    quint64         _cguest_time;

    // /proc/[pid]/statm
    quint64         _m_size;
    quint64         _m_resisdent;
    quint64         _m_share;
    quint64         _m_text;
    quint64         _m_lib;
    quint64         _m_data;
    quint64         _m_dt;
    
    // parsers
    static QString parseCommandLine(const QString &);
    static void parseStatFile(const QString &, ProcessView *);
    static void parseStatmFile(const QString &, ProcessView *);
};

} // namespace rpm

#endif // ifndef _RPM_PROCESSVIEW_H
