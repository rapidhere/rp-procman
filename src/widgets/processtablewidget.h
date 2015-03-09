#ifndef _RPM_PROCESS_TABLE_WIDGET_H
#define _RPM_PROCESS_TABLE_WIDGET_H 1

#include <QTableView>

namespace rpm {

class ProcessTableWidget : public QTableView {
    Q_OBJECT

public:
    ProcessTableWidget();

    void refresh();
};

} // namespace rpm

#endif // ifndef _RPM_PROCESS_TABLE_WIDGET_H
