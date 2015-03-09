#include "processtablewidget.h"
#include "processtablemodel.h"

#include <QHeaderView>

namespace rpm {

ProcessTableWidget::ProcessTableWidget() : QTableView() {
    this->setModel(new ProcessTableModel());

    this->horizontalHeader()->setDefaultSectionSize(120);
    this->horizontalHeader()->setMinimumSectionSize(120);
    this->horizontalHeader()->setStretchLastSection(true);
}

void ProcessTableWidget::refresh() {
    (dynamic_cast<ProcessTableModel *>(this->model()))->refresh();
}

} // namespace rpm
