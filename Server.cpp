#ifndef server_c
#define server_c

#include <map>
#include "Mainloop.h"
#include "EventEmitter.cpp"

class Server:public EventEmitter
{   
    typedef void(* Callback)();
public:
    Mainloop ml = new Mainloop();
    void create(int port,  Callback cb)
    {
        ml.start(port);
    }
    virtual void close()
    {
        ml.exit();
        delete ml;
    }
    virtual ~Server()
    {
        delete ml;
    }
};
#endif server_c
