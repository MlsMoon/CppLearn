#include <thread>
#include <iostream>

class Param
{
public:
    Param() { std::cout << "Param Create" << std::endl; }

    Param(const Param& p)
    {
        this->name = p.name;
        std::cout << "Param Copy" << std::endl;
    }

    ~Param() { std::cout << "Param Destroy" << std::endl; }

    std::string name;
};

void Thread01(int in_int, float in_float, std::string in_string, Param* in_p)
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "thread 01: in_int:" << in_int << std::endl;
    std::cout << "thread 01: in_float:" << in_float << std::endl;
    std::cout << "thread 01: in_string:" << in_string << std::endl;
    std::cout << "thread 01: param name:" << in_p->name << std::endl;
}

int main(int argc, char* argv[])
{
    float var_test_float = 5.5f;
    int var_test_int = 1;
    std::string var_test_string = "Test";
    Param p;
    p.name = "test";

    std::cout << "Main Function Begin" << std::endl;

    std::thread th(Thread01, var_test_int, var_test_float, var_test_string, &p);

    var_test_float *= 2.2f;
    var_test_int *= 2;
    var_test_string = "modify";

    std::cout << "thread main: int:" << var_test_int << std::endl;
    std::cout << "thread main: float:" << var_test_float << std::endl;
    std::cout << "thread main: string:" << var_test_string << std::endl;

    th.join();
    return 0;
}
