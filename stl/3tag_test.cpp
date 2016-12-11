#include <iostream>

using namespace std;

struct B { };
struct D1: public B{ };
struct D2: public D1{ };

template<class I>
void func(I &p, B)
{
    cout << "B version" << endl;
}

template<class I>
void func(I &p, D1)
{
    cout << "D1 version" << endl;
}

int main()
{
    int *p;
    func(p, B());
    func(p, D1());
    func(p, D2());
}
