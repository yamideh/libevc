
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
    static Mainloop & get();
    vector<std::shared_ptr<Session>> vs;
private:
    Mainloop *_instance = nullptr ;
};


#endif
