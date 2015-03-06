#include "processview.h"

namespace rpm {

ProcessView::ProcessView() {
}

ProcessView::~ProcessView() {
}

Pid ProcessView::pid() {
    return thePid;
}

QString *ProcessView::processName() {
    return theProcessName;
}

} // namespace rpm
