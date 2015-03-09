#include "systemview.h"
#include "processlist.h"

namespace rpm {

SystemView::SystemView() {
    pl = new ProcessList();
}

SystemView::~SystemView() {
    delete pl;
}

SystemView *SystemView::_systemView = NULL;

void SystemView::refresh() {
    return this->pl->refresh();
}

SystemView* SystemView::getSystemView() {
    if(! _systemView) {
        _systemView = new SystemView();
    }

    return _systemView;
}

ProcessList *SystemView::processList() {
    return this->pl;
}

} // namespace rpm
