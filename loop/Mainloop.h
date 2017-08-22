
#ifndef mainloop_h
#define mainloop_h

#include <stdlib.h>
#include "../mio/EventUtil.h"
#include "./Mainloop.h"
#include "../component/Session.cpp"
#include "vector"


class Mainloop{
public:
    Mainloop();
    int start();
    int port;
    int sock;
    bool done = false ;
    vector<Session> vs;
};


#endif