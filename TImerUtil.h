#ifndef timerutil_h
#define timerutil_h

#include <functional>
#include <memory>
#include <vector>
#include "Timer.h"

class TimerUtil
{
public:
    typedef std::function<void()> Callback;
    static void runAfter(Callback,long);
    static void runAt(Callback);
    static void runEvery();
};

struct TimeComparetor
{
    bool operator()(std::shared_ptr<Timer> &x,  std::shared_ptr<Timer> &y)
    {
        return x->time < y->time;
    }
};

class TimerHeap
{
public:
    static void push(std::shared_ptr<Timer>);
private:
    static vector<std::shared_ptr<Timer>> vt;
};


#endif
