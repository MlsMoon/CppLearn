#include <thread>
#include <iostream>

void Thread01()
{
    // distinguish thread? use thread id
    std::cout << "(Sub) Thread 01 ID:" << std::this_thread::get_id() << std::endl;

    // thread 01 code
    std::cout << "begin Thread 01" << std::endl;

    //how to release sub thread cpu resource?
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Thread 01:" << i << std::endl;
    }

    std::cout << "end Thread 01" << std::endl;
}

int main(int argc, char* argv[])
{
    // thread main code
    std::cout << "Main Begin" << std::endl;
    
    // distinguish thread? use thread id
    std::cout << "(Main) Thread ID:" << std::this_thread::get_id() << std::endl;

    // create a thread and run 
    std::thread th(Thread01);

    // thread main code
    std::cout << "wait sub thread 01" << std::endl;

    //block and wait th exit
    th.join();

    return 0;
}
