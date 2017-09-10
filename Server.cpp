#ifndef server_c
#define server_c

#include <map>
#include <functional>
#include "Mainloop.h"
#include "EventEmitter.cpp"

class Server:public EventEmitter
{   
    typedef void(* Callback)();
public:
    void create(int port,  Callback cb):accept_cb(cb)
    {
        Mainloop.get().start(port);
    }
    virtual void close()
    {
        Mainloop.get().exit();
        delete ml;
    }
    virtual ~Server()
    {
    }
    std::function<void(Session *)> accept_cb;
};
#endif server_c
