#ifndef timerutil_c
#define timerutil_c

static void TimerUtil::runAfter(Callback cb,long time)
{
    std::shared_ptr<Timer> timer(new Timer(cb,time));
    TimerHeap.push(timer);
}

static void TimerHeap::push(std::shared_ptr<Timer> &x)
{
    vt.push_back(x);
    std::push_heap(vt.begin(),vt.end(),TimeComparetor());
}

static std::shared_ptr<Timer> TimerHeap::pop()
{
    std::pop_heap(vt.begin(),vt.end(),TimeComparetor());
    return vt.pop_back();
}

#endif
