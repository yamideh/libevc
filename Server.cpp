#ifndef server_c
#define server_c

#include <map>
#include "./loop/Mainloop.h"
#include "./component/EventEmitter.cpp"

class Server:public EventEmitter
{   
    typedef void(* Callback)();
public:
    Mainloop ml;
    void create(int port,  Callback cb)
    {
        ml.start(port);
    }
};
#endif server_c