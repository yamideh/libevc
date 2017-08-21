#ifndef event_util_h
#define event_util_h

#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/event.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <vector>
#include "./Event.h"

namespace mio
{
    class EventUtil
    {
    public :
        static int create();
        static int add(int kfd, int sock,void *ud);
        static int del(int kfd, int sock);
        static int close(int kfd);
        static int wait(int kfd, vector<Event> e,int max);
        static int set_nonblocking(int kfd);
    private:
        EventUtil(){};
    };
}

#endif