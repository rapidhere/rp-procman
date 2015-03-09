#ifndef _RPM_PROCESS_TABLE_MODEL_H
#define _RPM_PROCESS_TABLE_MODEL_H 1

#include <QAbstractTableModel>

namespace rpm {

class ProcessList;

class ProcessTableModel : public QAbstractTableModel {
    Q_OBJECT

public:
    ProcessTableModel();
    virtual ~ProcessTableModel();

    // reimplemented
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};

} // namespace rpm

#endif // ifndef _RPM_PROCSS_TABLE_MODEL_H
