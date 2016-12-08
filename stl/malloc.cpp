#include <cstdlib>
#include <iostream>
#include <new>

#define output std::cout << "haha" << std::endl; std::cout << "haha again" << std::endl;

int main()
{
    void *p1 = malloc(1);
    void *p2 = malloc(1);
    std::cout << "sizeof p1:" << sizeof(p1) << std::endl;
    new(p1) int(1234567);
    std::cout << *(int *)p1 << std::endl;
    std::cout << "sizeof p2:" << sizeof(p2) << std::endl;
    std::cout << *(int *)p2 << std::endl;

    free(p1);

    p1 = 0;

    free(p1);

    p1 = new int();
    std::cout << *(int *)p2 << std::endl;

    output;

    enum Day {Fri = 100, The, Thu};
    enum {Fr = 8, Se};

    Day day1= The;

    std::cout << day1 << std::endl;
    std::cout << Fr << std::endl;

    return 0;
}
