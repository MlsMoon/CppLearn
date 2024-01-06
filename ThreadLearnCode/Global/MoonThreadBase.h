#pragma once
#include <string>
#include <thread>

class MoonThreadBase
{
public:
    std::string name;
    int age;

    virtual void start_thread();
    virtual bool wait_thread();
    virtual void stop_thread();
    virtual void thread_main() = 0;

protected:
    bool is_exit() const;

private:
    std::thread th_;
    bool is_exit_ = false;
};
