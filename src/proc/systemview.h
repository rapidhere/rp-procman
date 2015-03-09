#ifndef _RPM_SYSTEMVIEW_H
#define _RPM_SYSTEMVIEW_H 1

namespace rpm {

class ProcessList;

class SystemView {
public:
    ~SystemView();

    static SystemView *getSystemView();
    
    void refresh();
    ProcessList *processList();
private:
    SystemView();

    ProcessList *pl;
    static SystemView *_systemView;
};

} // namesapce rpm

#endif // ifndef _RPM_SYSTEMVIEW_H
