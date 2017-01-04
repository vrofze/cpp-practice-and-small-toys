#include <iostream>

class Base
{
public:
    void foo() { };
    void bar() { };

public:
    int i;
    double d;
};

typedef void (Base::*CLASS_FUNC)();

int main()
{
    Base base;

    std::cout << "class address:" << &base << std::endl;

    std::cout << "class var i's address:" << &(base.i) << std::endl;

    std::cout << "class var d's address:" << &(base.d) << std::endl;

    std::cout << "class var i size:" << sizeof(base.i) << std::endl;

    std::cout << "class var d szie:" << sizeof(base.d) << std::endl;

    CLASS_FUNC p_func = &Base::foo;
    unsigned int * tmp = (unsigned int*)&p_func;

    std::cout << "class func foo address:" << std::hex << *tmp << std::endl;

    p_func = &Base::bar;
    tmp = (unsigned int*)&p_func;

    std::cout << "class func bar address:" << std::hex << *tmp << std::endl;

    return 0;
}
