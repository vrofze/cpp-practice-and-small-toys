#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

int counter(0);

std::mutex mtx;
std::timed_mutex timed_mtx;

void attempt_10k_increases()
{
    for(int i = 0; i < 10000; ++i){
        if(mtx.try_lock()){
            ++counter;
            mtx.unlock();
        }
    }
}

void increase(int n)
{
    mtx.lock();
    for(int i = 0; i < n; ++i)
        ++counter;
    mtx.unlock();
}

void fireworks(int n)
{
    while(!timed_mtx.try_lock_for(std::chrono::milliseconds(200))){
        std::cout << "-";
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "*" << "thread:" << n << std::endl;
    timed_mtx.unlock();
}

void dead_lock()
{
    mtx.lock();
    mtx.lock();
    mtx.unlock();
}

int main()
{
    std::thread threads[10];
    for(int i = 0; i < 10; ++i)
        // threads[i] = std::thread(attempt_10k_increases);
        threads[i] = std::thread(dead_lock);
    std::cout << "spawning all threads" << std::endl;

    for(auto &th : threads)
        th.join();

    std::cout << "all threads joined" << std::endl;
    std::cout << counter << " successful increases of the counter" << std::endl;

    return 0;
}
