#ifndef mainloop_c
#define mainloop_c
#define MAX_BACK_LOG 32

#include "./Mainloop.h"
namespace loop
{
    int Mainloop::start(int port)
    {
        int listener = socket(AF_INET,SOCK_STREAM,0); 
        struct sockaddr_in sin;
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = 0;
        sin.sin_port = htons(this.port);
        if(bind(listener,(struct sockaddr *)&sin ,sizeof(n)) <0)
        {
            perror("bind some error");
            return -1;
        }
        if(listen(listener,MAX_BACK_LOG)<0)
        {
            perror("listen error");
            return -1;
        }
        EventUtil.set_nonblocking(listener);
        
    }
    
}
#endif