#ifndef server_c
#define server_c

#include <map>
#include "./loop/Mainloop.h"
using namespace mio;
using namespace loop;
class Server
{   
public:
    Mainloop ml;
    void listen(int port,void (* listen_cb)())
    {
        ml.start(port);
    }
    void on(string route,void (* cb)(string));
    void emit(string route,string msg);
};
#endif server_c