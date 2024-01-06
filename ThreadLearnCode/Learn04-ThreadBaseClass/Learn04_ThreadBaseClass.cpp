#include <thread>
#include <iostream>
#include "TestThread.h"

int main(int argc, char* argv[])
{
    TestThread thread;
    thread.name = "test thread";
    thread.age = 1;

    thread.start_thread();
    std::this_thread::sleep_for(std::chrono::seconds(3));
    thread.stop_thread();

    return 0;
}
