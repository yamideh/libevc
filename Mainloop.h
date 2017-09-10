
#ifndef mainloop_h
#define mainloop_h

#include <stdlib.h>
#include <memory>
#include "EventUtil.h"
#include "Mainloop.h"
#include "Session.cpp"
#include "vector"


class Mainloop{
public:
    Mainloop();
    int start();
    int port;
    int sock;
    bool done = false ;
    vector<std::shared_ptr<Session>> vs;
};


#endif
