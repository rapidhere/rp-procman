#include "processlist.h"
#include "defs.h"

#include <QString>

extern "C" {

#include <dirent.h>
#include <sys/types.h>

} // extern "C"

#define PROC_DIR "/proc"

namespace rpm {

ProcessList::ProcessList() : QVector<ProcessView*>() {
}

ProcessList::~ProcessList() {
    clear();
}

void ProcessList::refresh() {
    // the path string
    QString pfilePath;

    // clear previous list
    clear();

    // open /proc dir
    DIR* procd = opendir(PROC_DIR);
    if(! procd) {
        _E("Open proc directory '" PROC_DIR "' failed");
        return ;
    }

    // list the dir
    struct dirent *ent;

    while((ent = readdir(procd))) {
        if(! isDigit(ent->d_name))
            continue;

        pfilePath.clear();
        pfilePath.append(PROC_DIR "/");
        pfilePath.append(ent->d_name);

        this->push_back(ProcessView::fromProcFile(pfilePath));
    }

    // close the dir
    closedir(procd);
}

void ProcessList::clear() {
    for(size_t i = 0;i < this->size();i ++)
        delete this->at(i);

    QVector<ProcessView*>::clear();
}

bool ProcessList::isDigit(const char *str) {
    char ch;

    while((ch = *str)) {
        if(ch < '0' || ch > '9')
            return false;

        str ++;
    }

    return true;
}

} // namespace rpm

#undef PROC_DIR
