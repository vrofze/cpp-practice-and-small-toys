#include <iostream>
#include <thread>
#include <chrono>

void hello()
{
    std::cout << "hello concurrent world" << std::endl;
}

class background_task
{
public:
    void operator()() const
        {
            std::cout << "hello concurrent world" << std::endl;
        }
};

struct func
{
    int &i;
    int n;
    func(int &i_) : i(i_), n(0) { }

    void operator()()
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            for(size_t i = 0; i < 10000; ++i)
                ++n;
            std::cout << n << std::endl;
        }
};

int main()
{
    int local_state = 0;
    func my_func(local_state);
    std::thread t(my_func);

    t.detach();
    return 0;
}
