#include "MoonThreadBase.h"
#include <iostream>

void MoonThreadBase::start_thread()
{
    th_ = std::thread(&MoonThreadBase::thread_main,this);
}