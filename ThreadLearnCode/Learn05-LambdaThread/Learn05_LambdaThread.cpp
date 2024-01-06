#include <thread>
#include <iostream>

int main(int argc, char* argv[])
{
    std::thread th
    (
        [](int i)
        {
            std::cout << "(Sub Thread) lambda test val :" << i << std::endl;
        },
        123
    );
    th.join();

    return 0;
}
