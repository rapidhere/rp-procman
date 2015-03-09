#include "processtablemodel.h"
#include "proc/systemview.h"
#include "proc/processlist.h"
#include "proc/processview.h"
#include "defs.h"

namespace rpm {

ProcessTableModel::ProcessTableModel() : QAbstractTableModel() {
}

ProcessTableModel::~ProcessTableModel() {
}

int ProcessTableModel::rowCount(const QModelIndex & /*parent*/) const {
    return SystemView::getSystemView()->processList()->size();
}

int ProcessTableModel::columnCount(const QModelIndex & /*parent*/) const {
    return 5;
}

QVariant ProcessTableModel::data(const QModelIndex &index, int role) const {
    if(role == Qt::DisplayRole) {
        // get process view
        ProcessView *pv = SystemView::getSystemView()->processList()->at(index.row());

        switch(index.column()) {
        case 0: return pv->pid();
        case 1: return pv->processName();
        case 2: return QChar(pv->state());
        case 3: return pv->virtualMemomrySize();
        case 4:
            if(pv->hasCommandLine())
                return pv->commandLine();
            else
                return QString("[ %1 ]").arg(pv->processName());
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
            case 3: return QString("Virtual Memomry");
            case 4: return QString("Command Line");
            }
        } else {
        }
    }

    return QVariant();
}

void ProcessTableModel::refresh() {
    emit layoutAboutToBeChanged();
    emit layoutChanged();
}

} // namespace rpm
