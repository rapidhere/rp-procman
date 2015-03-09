#include "processview.h"
#include "defs.h"

#include <QFile>
#include <QIODevice>
#include <QTextStream>

#define PROC_CMD_LINE_FILE "cmdline"
#define PROC_COMM_FILE "comm"
#define PROC_STATUS_FILE "status"

#define PROC_STATUS_FILE_KEY_PID "Pid"
#define PROC_STATUS_FILE_KEY_VMSIZE "VmSize"
#define PROC_STATUS_FILE_KEY_STATE "State"

namespace rpm {

ProcessView::ProcessView() {
    _pid = 0;
    _vm_size = 0;
}

ProcessView::~ProcessView() {
}

ProcessView::Pid ProcessView::pid() const {
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

int ProcessView::virtualMemomrySize() const {
    return _vm_size;
}

ProcessView::ProcessState ProcessView::state() const {
    return _state;
}

ProcessView *ProcessView::fromProcFile(const QString &p) {
    ProcessView *ret = new ProcessView();

    // get process name
    ret->_process_name = parseProcessName(p);

    // get cmdline
    ret->_command_line = parseCommandLine(p);

    // get other info
    parseStatusFile(p, ret);

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

QString ProcessView::parseProcessName(const QString &p) {
    QString ret;
    QFile f(p + ("/" PROC_COMM_FILE));
    f.open(QIODevice::ReadOnly);

    ret = f.readLine();
    ret = ret.trimmed();

    f.close();

    return ret;
}

void ProcessView::parseStatusFile(const QString &p, ProcessView *pv) {
    QFile f(p + ("/" PROC_STATUS_FILE));
    f.open(QIODevice::ReadOnly);

    QTextStream ts(f.readAll());

    // parse the status file by line
    while(! ts.atEnd()) {
        QString line = ts.readLine().trimmed();
        int sp = line.indexOf(':');

        QString key = line.mid(0, sp);
        QString val = line.mid(sp + 1).trimmed();

        if(key == PROC_STATUS_FILE_KEY_PID) {
            pv->_pid = val.toInt();
        } else if(key == PROC_STATUS_FILE_KEY_VMSIZE) {
            val.chop(3);
            pv->_vm_size = val.toInt();
        } else if(key == PROC_STATUS_FILE_KEY_STATE) {
            pv->_state = val.at(0).toLatin1();
        }
    }

    f.close();
}

} // namespace rpm

#undef PROC_CMD_LINE_FILE
#undef PROC_COMM_FILE
#undef PROC_STATUS_FILE
#undef PROC_STATUS_FILE_KEY_PID
#undef PROC_STATUS_FILE_KEY_VMSIZE
#undef PROC_STATUS_FILE_KEY_STATE
