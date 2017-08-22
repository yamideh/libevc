#ifndef session_c
#define session_c

#include "./EventEmitter.cpp"

class Session : public EventEmitter
{     
public:
    Session(int kfd):fd(kfd){}
    int fd;
};


#endif