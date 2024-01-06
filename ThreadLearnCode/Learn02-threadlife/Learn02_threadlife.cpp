#include <thread>
#include <iostream>

#define DESTROY_THREAD_IN_RUN 0

bool static is_exit = false;

void Thread01()
{
    // distinguish thread? use thread id
    std::cout << "(Sub) Thread 01 ID:" << std::this_thread::get_id() << std::endl;

    // thread 01 code
    std::cout << "Thread 01 begin" << std::endl;

    //how to release sub thread cpu resource?
    for (int i = 0; i < 10; i++)
    {
        if(is_exit)
            break;
        
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

#if DESTROY_THREAD_IN_RUN
    // this will error , but sub thread is still run
    {
        // create a thread and run 
        std::thread th(Thread01);
    }
    return 0;
#endif
    
    // create a thread and run 
    std::thread th(Thread01);
    // 分离线程
    // 问题： 使用了分离线程后 ，如果主线程退出，子线程不一定退出
    // th.detach();

    // thread main code
    std::cout << "main thread begin" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    // 程序结束，退出
    std::cout << "main thread end" << std::endl;
    is_exit = true;
    // 通知子线程该退出了
    th.join();
    
    return 0;
}
