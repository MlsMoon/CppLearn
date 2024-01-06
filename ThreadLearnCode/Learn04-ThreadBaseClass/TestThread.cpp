#include "TestThread.h"
#include <iostream>

void TestThread::start_thread()
{
    MoonThreadBase::start_thread();
    std::cout << "(Test Thread) Start" << std::endl;
    std::cout << "(Test Thread) Name:" << name << std::endl;
    std::cout << "(Test Thread) Age:" << age << std::endl;
}

bool TestThread::wait_thread()
{
    return MoonThreadBase::wait_thread();
}

void TestThread::thread_main()
{
    while (!is_exit())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "." << std::flush;
    }
}

void TestThread::stop_thread()
{
    MoonThreadBase::stop_thread();
}
