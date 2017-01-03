#include "singleton.h"

#include <iostream>

int main()
{
    SingletonBase *p_singleton = SingletonBase::GetInstence();

    std::cout << p_singleton->GetData() << std::endl;

    SingletonBase::DestoryInstence();

    SingletonLock *p_singleton_lock = SingletonLock::GetInstence();
    std::cout << p_singleton_lock->GetData() << std::endl;
    p_singleton_lock->~SingletonLock();

    return 0;
}
