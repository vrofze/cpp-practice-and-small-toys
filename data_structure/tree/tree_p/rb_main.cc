#include "red_black_tree.h"

#include <iostream>

using namespace std;

int main()
{
    RedBlackTree<int, int> tree;
    tree.insert(pair<int, int>(41, 41));
    tree.insert(pair<int, int>(38, 38));
    tree.insert(pair<int, int>(31, 31));
    tree.insert(pair<int, int>(12, 12));
    tree.insert(pair<int, int>(19, 19));
    tree.insert(pair<int, int>(8, 8));
    tree.tree_delete(8);
    cout << tree.size() << endl;
    tree.PreOrderOutput();
}
