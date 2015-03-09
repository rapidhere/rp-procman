#include "tabbar.h"
#include "processtablewidget.h"
#include "defs.h"

namespace rpm {

TabBar::TabBar() : QTabWidget() {
    this->_process_table_widget = new ProcessTableWidget();
    this->_process_table_widget->setParent(this);

    this->addTab(_process_table_widget, RPM_TABBAR_PROCESS_TABLE_TITLE);
}

ProcessTableWidget *TabBar::processTableWidget() const {
    return this->_process_table_widget;
}

} // namespace rpm
