#ifndef event_h
#define event_h


class Event
{
public:
    Event(int fd,int (*read_cb)(void *),int (*write_cb)(void *));
    int fd;
    bool read;
    bool write;
    int (*read_cb)(void *arg);
    int (*write_cb)(void *arg);
    void *data;
};

#endif