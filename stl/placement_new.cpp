#include <cstdlib>
#include <iostream>
#include <string>
#include <new>

using namespace std;

class X
{
public:
    X()
        {
            cout << "constructor of X " << endl;
        }
    ~X()
        {
            cout << "destructor of X" << endl;
        }

    void * operator new(size_t size)
        {
            cout << "operator new called " << size << endl;
            return ::operator new(size);
        }

    void * operator new(size_t size, void *p)
        {
            p = new X();
        }

    void * operator new(size_t size, string str)
        {
            cout << "operator new size " << size
                 << " with string " << str << endl;
            return ::operator new(size);
        }

    void * operator new(size_t size, string str1, string str2)
        {
            cout << "operator new size " << size
                 << "with string1 " << str1
                 << "and string2" << str2 << endl;
            return ::operator new(size);
        }

    void operator delete(void * pointer)
        {
            cout << "operator delete" << endl;
            return ::operator delete(pointer);
        }

private:
    int num;
};

int main()
{
    // X *px = new("A new class") X;
    X *px = new("&&&&&", "^^^^^") X;
    // X *spx = new X;
    delete px;
    // delete spx;

    X *p = (X *)malloc(sizeof(X));

    new(p) X();

    return 0;
}
