#include <cstdlib>
#include <iostream>
#include <new>

int main()
{
    void *p = malloc(sizeof(int));
    std::cout << "sizeof p:" << sizeof(p) << std::endl;
    new(p) int(10);
    std::cout << *(int *)p << std::endl;

    free(p);

    p = 0;

    free(p);

    p = new int();
    std::cout << *(int *)p << std::endl;

    return 0;
}
