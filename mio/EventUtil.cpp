#ifndef event_util_c
#define event_util_c
#include "EventUtil.h"

int EventUtil::create()
{
    return kqueue();
}
int EventUtil::close(int kfd)
{
    close(kfd);
}
int EventUtil::add(int kfd, int sock,void *ud)
{
    struct kevent ke;
    EV_SET(&ke, sock, EVFILT_READ, EV_ADD, 0, 0, ud);
    if (kevent(kfd, &ke, 1, NULL, 0, NULL) == -1) {
        return 1;
    }
    EV_SET(&ke, sock, EVFILT_WRITE, EV_ADD, 0, 0, ud);
    if (kevent(kfd, &ke, 1, NULL, 0, NULL) == -1) {
        EV_SET(&ke, sock, EVFILT_READ, EV_DELETE, 0, 0, NULL);
        kevent(kfd, &ke, 1, NULL, 0, NULL);
        return 1;
    }
    EV_SET(&ke, sock, EVFILT_WRITE, EV_DISABLE, 0, 0, ud);
    if (kevent(kfd, &ke, 1, NULL, 0, NULL) == -1) {
        del(kfd, sock);
        return 1;
    }
    return 0;
}
int EventUtil::del(int kfd, int sock)
{
    struct kevent ke;
    EV_SET(&ke, sock, EVFILT_READ, EV_DELETE, 0, 0, NULL);
    kevent(kfd, &ke, 1, NULL, 0, NULL);
    EV_SET(&ke, sock, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
    kevent(kfd, &ke, 1, NULL, 0, NULL);
}
int EventUtil::set_nonblocking(int kfd)
{
    int flag = fcntl(fd, F_GETFL, 0);
    if ( -1 == flag ) {
        return;
    }
    fcntl(fd, F_SETFL, flag | O_NONBLOCK);
}
int EventUtil::wait(int kfd, vector<Event> e, int max)
{
    struct kevent ev[max];
    int n = kevent(kfd, NULL, 0, ev, max, NULL);

    int i = 0;
    for( ; i<n ; ++i)
    {
        e[i].s = ev[i].data;
        unsigned filter = ev[i].filter ;
        e[i].write = (filter == EVFILT_WRITE);
        e[i].read = (filter == EVFILT_READ);
    }
}


#endif