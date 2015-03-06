#include "tabbar.h"
#include "processtablewidget.h"
#include "defs.h"

namespace rpm {

TabBar::TabBar() : QTabWidget() {
    this->theProcessTableWidget = new ProcessTableWidget();
    this->theProcessTableWidget->setParent(this);

    this->addTab(theProcessTableWidget, RPM_TABBAR_PROCESS_TABLE_TITLE);
}

ProcessTableWidget *TabBar::processTableWidget() {
    return this->theProcessTableWidget;
}

} // namespace rpm
