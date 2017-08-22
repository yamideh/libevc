#ifndef event_c
#define event_c
#include "event.h"

Event::Event(int fd,int (*read_cb)(void *),int (*write_cb)(void *))
{
    this.fd = fd ;
}


#endif