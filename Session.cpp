#ifndef session_c
#define session_c

#include "Session.h"
bool Session::onConnection(void *data)
{
    int kfd = static_cast<int>(*data);
    
}

#endif
