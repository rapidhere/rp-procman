#include "processtablemodel.h"
#include "proc/processlist.h"
#include "proc/processview.h"
#include "defs.h"

namespace rpm {

ProcessTableModel::ProcessTableModel() : QAbstractTableModel() {
    pl = new ProcessList();

    pl->refresh();
}

ProcessTableModel::~ProcessTableModel() {
    delete pl;
}

int ProcessTableModel::rowCount(const QModelIndex & /*parent*/) const {
    return pl->size();
}

int ProcessTableModel::columnCount(const QModelIndex & /*parent*/) const {
    return 5;
}

QVariant ProcessTableModel::data(const QModelIndex &index, int role) const {
    if(role == Qt::DisplayRole) {
        // get process view
        ProcessView *pv = pl->at(index.row());

        switch(index.column()) {
        case 0: return pv->pid();
        case 1: return pv->processName();
        case 2: return QChar(pv->state());
        case 3:
            if(pv->hasCommandLine())
                return pv->commandLine();
            else
                return QString("[ %1 ]").arg(pv->processName());
        case 4: return pv->virtualMemomrySize();
        }
    }

    return QVariant();
}

QVariant ProcessTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole) {
        if(orientation == Qt::Horizontal) {
            switch(section) {
            case 0: return QString("Pid");
            case 1: return QString("Process Name");
            case 2: return QString("State");
            case 3: return QString("Command Line");
            case 4: return QString("Virtual Memomry");
            }
        } else {
        }
    }

    return QVariant();
}

void ProcessTableModel::refresh() {
    pl->refresh();
}

} // namespace rpm