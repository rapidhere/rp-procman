#include "processtablewidget.h"
#include "processtablemodel.h"


namespace rpm {

ProcessTableWidget::ProcessTableWidget() : QTableView() {
    this->setModel(new ProcessTableModel());
}

} // namespace rpm
