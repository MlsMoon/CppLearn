#pragma once
#include "../Global/MoonThreadBase.h"

class TestThread : MoonThreadBase
{
public:
    int age;
    std::string name;

    void start_thread() override;
    bool wait_thread() override;
    void thread_main() override;
    void stop_thread() override;
};
