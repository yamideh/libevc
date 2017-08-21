# libevc
A library used for building socket server like nodejs . 
After viewing libevent source code ,i found nodejs-tcp-server is really much easier to use.
I decide to write a lib to build simple server in C++ .So the user doesn't need to understand
event and bufferevent. Event will be implement in a absoute way. 
here is a very simple echo server:

    #include <string>
    #include "server.cpp"

    void accept_cb(Handler h)
    {
        h.on("data",read_cb);
    }
    void read_cb(Handler h,string s)
    {
        h.write(s);
    }
    int main()
    {
        Server *s = new Server();
        s->create(8080,acceprt_cb);
        s.on("error",error_cb);
        s.on("close",close_cb);
    }   
