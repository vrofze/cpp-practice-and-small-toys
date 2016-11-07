#include "binary_search_tree.h"
#include <iostream>

int main()
{
    BinarySearchTree<int, int> bts;
    bts.insert(std::pair<int, int>(30, 30));
    bts.insert(std::pair<int, int>(5, 5));
    bts.insert(std::pair<int, int>(2, 2));
    bts.insert(std::pair<int, int>(40, 40));
    bts.insert(std::pair<int, int>(35, 35));
    bts.insert(std::pair<int, int>(80, 80));
    bts.insert(std::pair<int, int>(32, 32));
    bts.erase(5);
    std::cout << bts.find(80) << std::endl;
    bts.ascend();

    return 0;
}
