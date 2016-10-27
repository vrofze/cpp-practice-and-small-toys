#include "linked_binary_tree.h"

#include <iostream>
#include <queue>
#include <vector>


class cmp
{
public:
  bool operator()(const int n, const int m)
  {
    return n < m;
  }
};

template<class T>
struct HuffmanNode
{
  HuffmanNode(LinkedBinaryTree<size_t> *ptree, T weight)
  {
    this->tree = ptree;
    this->weight = weight;
  }
  ~HuffmanNode()
  {
    delete this->tree;
  }
  LinkedBinaryTree<size_t> tree;
  T weight;
};

template<class T>
LinkedBinaryTree<int>* BuildHuffmanTree(const T weight[], size_t n)
{
  std::vector<HuffmanNode<T> *> pnode;

  // 将weight[] 构建为n棵树
  for(size_t i = 0; i < n; ++i)
    pnode.push(new HuffmanNode<T>(new LinkedBinaryTree<size_t>(i, nullptr, nullptr), weight[i]));

  // 将n棵树放入最小堆
  std::priority_queue<HuffmanNode<T>, std::vector<HuffmanNode<T>>, cmp> heap;
  for(size_t i = 0; i < n; ++i)
    heap.push(pnode[i]);

  HuffmanNode<T> w, x, y;
  for(size_t i = 0; i < n; ++i){
    x = heap.top();
    heap.pop();
    y = heap.top();
    heap.pop();

    w = new HuffmanNode<T>(new LinkedBinaryTree<size_t>(0, x->tree, y->tree),
                           x->weight + y->weight) ;
    heap.push(w);
    x.~HuffmanNode();
    y.~HuffmanNode();
  }

  return heap.top().tree;
}

int main()
{
  std::priority_queue<int, std::vector<int>, cmp> q;
  q.push(10);
  q.push(20);
  q.push(100);
  q.push(1);
  std::cout << q.top() << std::endl;
  return 0;
}
