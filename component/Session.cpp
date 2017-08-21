#ifndef session_c
#define session_c

namespace component
{
    class Session 
    {     
    public:
        Session(int kfd):fd(kfd){}
        int fd;
        void (*read_cb)(string s);
    };
}

#endif