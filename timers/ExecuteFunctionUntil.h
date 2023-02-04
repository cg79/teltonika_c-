#include<iostream>
using namespace std;

ExecuteFunctionUntil::ExecuteFunctionUntil()
{
	
}

ExecuteFunctionUntil::~ExecuteFunctionUntil()
{
	
}

void timer_start(std::function<void(void)> func, unsigned int interval, std::function<bool(void)> shouldStopFunc)
{
    std::thread([func, interval, shouldStopFunc]() {
		bool shouldStop = shouldStopFunc();

        while (!shouldStop)
        {
            func();
            std::this_thread::sleep_for(std::chrono::milliseconds(interval));
        }
    }).detach();
}

void do_something()
{
    std::cout << "I am doing something" << std::endl;
}

bool shouldStopTimer() {
	return false;
}

void triggerIntervalFunction(std::function<void(void)> func, unsigned int interval, std::function<bool(void)> shouldStopFunc) {
    timer_start(func, interval, shouldStopFunc);

    while(true);
}




