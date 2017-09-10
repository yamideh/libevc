#ifndef mainloop_c
#define mainloop_c
#define MAX_BACK_LOG 32

Mainloop::Mainloop()
{
    this.sock = EventUtil.create();
}
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
    std::shared_ptr<Session> listener_session(new Session(listener,this));
    vs.push_back(listener_session);
    EventUtil.add(listener_session->fd, this.sock,listener_session.get());
    this.tick();
}
void Mainloop::tick()
{
    while(!done)
    {
        // 清除定时器时间
        // epoll_wait阻塞 
        // 检查定时器时间并运行
        // 运行到期的定时器
        // 运行wait中触发的回调
    }
}

Mainloop & Mainloop::get()
{
    if(_instance == nullptr)
    {
        _instance = new Mainloop();
    }
    return *_istance ;
}

#endif
