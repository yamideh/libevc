#ifndef timer_h
#define timer_h

class Timer
{
public:
    Timer(std::function<void()> t, long time):cb(t),interval(time){}
    void run();
private:
    std::function<void()> cb;
    Timer(){}
};

#endif
