#ifndef session_h
#define session_h

#include <functional>
#include "Mainloop.h"

class Session : public EventEmitter
{
public:
    Session(int kfd):fd(kfd){}
    Session(int kfd , function<int<void *>> rc,function<int<void *>> wc):fd(kfd),read_cb(rc),write_cb(wc)
    {
        
    }
    int fd;
    function<int<void *>> read_cb;
    function<int<void *>> write_cb;
    bool onConnection(void *);
    void *data;
    Mainloop * mainloop;
};


#endif
