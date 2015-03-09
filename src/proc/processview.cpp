#include "processview.h"
#include "defs.h"

#include <QFile>
#include <QIODevice>
#include <QTextStream>

#define PROC_CMD_LINE_FILE "cmdline"
#define PROC_STAT_FILE "stat"
#define PROC_STATM_FILE "statm"

namespace rpm {

ProcessView::ProcessView() {
}

ProcessView::~ProcessView() {
}

int ProcessView::pid() const {
    return _pid;
}

QString ProcessView::processName() const {
    return _process_name;
}

QString ProcessView::commandLine() const {
    return _command_line;
}

bool ProcessView::hasCommandLine() const {
    return _command_line.length() != 0;
}

quint64 ProcessView::virtualMemomrySize() const {
    return _m_size;
}

ProcessView::ProcessState ProcessView::state() const {
    return _state;
}

ProcessView *ProcessView::fromProcFile(const QString &p) {
    ProcessView *ret = new ProcessView();

    // get cmdline
    ret->_command_line = parseCommandLine(p);

    // get other info
    parseStatFile(p, ret);
    parseStatmFile(p, ret);

    return ret;
}

QString ProcessView::parseCommandLine(const QString &p) {
    QString ret;
    QFile f(p + ("/" PROC_CMD_LINE_FILE));
    f.open(QIODevice::ReadOnly);

    ret = f.readAll();
    ret = ret.trimmed();

    f.close();

    return ret;
}

void ProcessView::parseStatFile(const QString &p, ProcessView *pv) {
    // open file
    QFile f(p + ("/" PROC_STAT_FILE));
    f.open(QIODevice::ReadOnly);

    // build stream
    QTextStream ts(f.readAll());

    // close file
    f.close();

    // parse
    QString pv_state_buff;

    ts >> pv->_pid
       >> pv->_process_name
       >> pv_state_buff
       >> pv->_ppid
       >> pv->_pgrp
       >> pv->_session
       >> pv->_tty_nr
       >> pv->_tpgid
       >> pv->_flags
       >> pv->_minflt
       >> pv->_cminflt
       >> pv->_majflt
       >> pv->_cmajflt
       >> pv->_utime
       >> pv->_stime
       >> pv->_cutime
       >> pv->_cstime
       >> pv->_priority
       >> pv->_nice
       >> pv->_num_threads
       >> pv->_itrealvalue
       >> pv->_start_time
       >> pv->_vsize
       >> pv->_rss
       >> pv->_rsslim
       >> pv->_startcode
       >> pv->_endcode
       >> pv->_startstack
       >> pv->_kstkesp
       >> pv->_kstkeip
       >> pv->_signal
       >> pv->_blocked
       >> pv->_sigignore
       >> pv->_sigcatch
       >> pv->_wchan
       >> pv->_nswap
       >> pv->_cnswap
       >> pv->_exit_signal
       >> pv->_processor
       >> pv->_rt_priority
       >> pv->_policy
       >> pv->_delayacct_blkio_ticks
       >> pv->_guest_time
       >> pv->_cguest_time;

    // remove parness
    pv->_process_name = pv->_process_name.mid(1);
    pv->_process_name.chop(1);

    // set pv state
    pv->_state = pv_state_buff.at(0).toLatin1();
}

void ProcessView::parseStatmFile(const QString &p, ProcessView *pv) {
    // open file
    QFile f(p + ("/" PROC_STATM_FILE));
    f.open(QIODevice::ReadOnly);

    // build stream
    QTextStream ts(f.readAll());

    // close file
    f.close();

    // parse
    ts >> pv->_m_size
       >> pv->_m_resisdent
       >> pv->_m_share
       >> pv->_m_text
       >> pv->_m_lib
       >> pv->_m_data
       >> pv->_m_dt;
}

} // namespace rpm

#undef PROC_CMD_LINE_FILE
#undef PROC_STAT_FILE
#undef PROC_STATM_FILE
