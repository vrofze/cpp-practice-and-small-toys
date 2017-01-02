#include "singleton.h"

#include <iostream>

int main()
{
    SingletonBase *p_singleton = SingletonBase::GetInstence();

    std::cout << p_singleton->GetData() << std::endl;

    SingletonBase::DestoryInstence();

    return 0;
}
