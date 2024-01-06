#include "MoonThreadBase.h"

void MoonThreadBase::start_thread()
{
    is_exit_ = false;
    th_ = std::thread(&MoonThreadBase::thread_main, this);
}

bool MoonThreadBase::wait_thread()
{
    if (!th_.joinable())
        return false;
    th_.join();
    return true;
}

void MoonThreadBase::stop_thread()
{
    is_exit_ = true;
    wait_thread();
}

bool MoonThreadBase::is_exit() const
{
    return is_exit_;
}
