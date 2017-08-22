#ifndef eventemitter_cpp
#define eventemitter_cpp

#include <map>
 
class EventEmitter 
{     
    typedef void(*Callback)(); 
public:
    multimap<string,Callback> map_cb;
    void on(string s,Callback cb)
    {
        mm.insert(make_pair(s,cb));
    }
    void emit(string s,...)
    {
        int k = 0 ;
        multimap<string,Callbck>::iterator m = map_cb.find(s);
        for(; k!=map_cb.count(s); ++k ,++m)
        {
            m->second(...);
        }
    }
};


#endif