#ifndef SINGLETON_H__
#define SINGLETON_H__

#include <mutex>
#include <iostream>

class SingletonBase
{
public:
    static SingletonBase *GetInstence()
        {
            if(instence == nullptr){
                instence = new SingletonBase();
            }

            return instence;
        }

    static void DestoryInstence()
        {
            if(instence != nullptr){
                delete instence;
                instence = nullptr;
            }
        }

    int GetData()
        {
            return data;
        }

private:
    SingletonBase() { data = 10; }
    static SingletonBase *instence;

    int data;
};

SingletonBase *SingletonBase::instence = nullptr;

class Lock
{
public:
    Lock()
        {
            mtx.lock();
            std::cout << "locked" << std::endl;
        }

    ~Lock()
        {
            mtx.unlock();
            std::cout << "unlock" << std::endl;
        }
private:
    std::mutex mtx;
};

class SingletonLock
{
public:
    static SingletonLock *GetInstence()
        {
            if(instence == nullptr){ // 双检锁
                mtx.lock();
                if(instence == nullptr){
                    instence = new SingletonLock();
                }
                mtx.unlock();
            }

            return instence;
        }

    static void DestoryInstence()
        {
            if(instence != nullptr){
                delete instence;
                instence = nullptr;
            }
        }

    int GetData()
        {
            return data;
        }


private:
    SingletonLock() { data = 10; }

    static SingletonLock *instence;
    int data;

    static std::mutex mtx;
};

SingletonLock *SingletonLock::instence = nullptr;
std::mutex SingletonLock::mtx;

#endif
