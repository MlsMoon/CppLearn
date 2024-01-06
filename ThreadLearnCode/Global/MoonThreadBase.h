#pragma once
#include <string>
#include <thread>

class MoonThreadBase
{
public:
    std::string name;
    int age;

    virtual void start_thread();
    virtual void thread_main() = 0;

private:
    std::thread th_;
};


