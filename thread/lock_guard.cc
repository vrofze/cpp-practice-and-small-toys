/*
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;

void print_thread_id(int id)
{
    mtx.lock();
    std::lock_guard<std::mutex> lck(mtx);

    std::cout << "thread id:" << id << std::endl;
}

int main()
{
    std::thread threads[10];
    // spawn 10 threads
    for(size_t i = 0; i < 10; ++i)
        threads[i] = std::thread(print_thread_id, i + 1);

    for(auto &th : threads)
        th.join();

    return 0;
}
*/

/* // lock_guard
#include <iostream>
#include <mutex>
#include <thread>
#include <stdexcept>

std::mutex mtx;

void print_even(int n)
{
    if(n % 2 == 0)
        std::cout << n << " is a even" << std::endl;
    else
        throw(std::logic_error("not a even"));
}

void print_thread_id(int n)
{
    try{
        std::lock_guard<std::mutex> lck(mtx);
        print_even(n);
    }
    catch(std::logic_error&){
        std::cout << "[exception caught]" << std::endl;
    }
}

int main()
{
    std::thread threads[10];
    for(size_t i = 0; i < 10; ++i)
        threads[i] = std::thread(print_thread_id, i + 1);

    for(auto &th : threads)
        th.join();

    return 0;
}
*/

#include <iostream>
#include <mutex>
#include <thread>

std::mutex foo, bar;

void task_a()
{
    std::lock(foo, bar);
    std::unique_lock<std::mutex> lck1(foo, std::adopt_lock);
    std::unique_lock<std::mutex> lck2(bar, std::adopt_lock);

    std::cout << "task a" << std::endl;
}

void task_b()
{
    std::unique_lock<std::mutex> lck1, lck2;
    lck1 = std::unique_lock<std::mutex>(bar, std::defer_lock);
    lck2 = std::unique_lock<std::mutex>(foo, std::defer_lock);

    std::lock(lck1, lck2);
    std::cout << "task b" << std::endl;
}

int main()
{
    std::thread th1(task_a);
    std::thread th2(task_b);

    th1.join();
    th2.join();
    return 0;
}
