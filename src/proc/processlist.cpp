#include "processlist.h"

namespace rpm {

ProcessList::ProcessList() : QVector<ProcessView*>() {
}

ProcessList::~ProcessList() {
    // destroy all process view
    for(size_t i = 0;i < this->size();i ++) {
        delete this->at(i);
    }
}

} // namespace rpm
