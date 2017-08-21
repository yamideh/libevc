
#ifndef mainloop_h
#define mainloop_h

#include <stdlib.h>
#include "./mio/EventUtil.h"
namespace loop
{
    class Mainloop{
    using namespace mio;
    public:
        Mainloop(int port);
        int start();
        int port;
    };
}

#endif