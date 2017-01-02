#ifndef SINGLETON_H__
#define SINGLETON_H__

#include <mutex>

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
        }

    ~Lock()
        {
            mtx.unlock();
        }
private:
    std::mutex mtx;
};

#endif
