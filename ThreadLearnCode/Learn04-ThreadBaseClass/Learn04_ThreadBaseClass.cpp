#include <thread>
#include <iostream>
#include "../Global/MoonThreadBase.h"

class TestThread:MoonThreadBase
{
public:
    int age;

    void start_thread() override;
};

int main(int argc, char* argv[])
{
    TestThread moon_thread;
    moon_thread.age = 1;
    moon_thread.name = "test thread 1";
    std::thread th(&MoonThreadBase::thread_main, &moon_thread);

    int input = getchar();
    
    th.join();
    return 0;
}
