#include <thread>
#include <iostream>
#include <mutex>

static std::mutex mux;
static std::timed_mutex timed_mutex;



void PrintToScreen(int i)
{
    float run_time = 0;
    while (run_time < 10000)
    {
        //检查锁，如果上锁则阻塞等待
        if (!mux.try_lock())
        {
            std::cout << "." << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            run_time += 100;
            continue;
        }
        std::cout << "=====================================================start" << ",Thread Index:" << i << std::endl;
        std::cout << "0" << std::endl;
        std::cout << "1" << std::endl;
        std::cout << "2" << std::endl;
        std::cout << "3" << std::endl;
        std::cout << "=====================================================end" << std::endl;
        mux.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        run_time += 1000;
    }
}

int main(int argc, char* argv[])
{
    for (int i = 0; i < 3; ++i)
    {
        std::thread th
        (
            [i]()
            {
                PrintToScreen(i);
            }
        );
        th.detach();
    }
    getchar();
    return 0;
}
