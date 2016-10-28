#include "linked_binary_tree.h"

#include <iostream>
#include <queue>
#include <vector>

template<class T>
struct HuffmanNode
{
  HuffmanNode()
  {
    this->tree = nullptr;
    this->weight = 0;
  }
  HuffmanNode(LinkedBinaryTree<size_t> *ptree, T weight)
  {
    this->tree = ptree;
    this->weight = weight;
  }
  LinkedBinaryTree<size_t>* tree;
  T weight;
};

template<class T>
class cmp
{
public:
  bool operator()(const HuffmanNode<T> n, const HuffmanNode<T> m)
  {
    return n.weight < m.weight;
  }
};

template<class T>
LinkedBinaryTree<size_t>* BuildHuffmanTree(const T weight[], size_t n)
{
  std::vector<HuffmanNode<T>> nodev;

  // 将weight[] 构建为n棵树
  for(size_t i = 0; i < n; i++){
    HuffmanNode<T> huff(new LinkedBinaryTree<size_t>(i, nullptr, nullptr), weight[i]);
    nodev.push_back(huff);
  }

  // 将n棵树放入最小堆
  std::priority_queue<HuffmanNode<T>, std::vector<HuffmanNode<T>>, cmp<T>> heap;
  for(size_t i = 0; i < n; ++i)
    {
      heap.push(nodev[i]);
      std::cout << "i:" << i << std::endl;
    }

  HuffmanNode<T> w, x, y;
  LinkedBinaryTree<size_t> *z;
  for(size_t i = 0; i < n - 1; ++i){
    // 将堆中最小的两棵树取出合并
    x = heap.top();
    heap.pop();
    y = heap.top();
    heap.pop();

    // 将两棵树合并
    z = new LinkedBinaryTree<size_t>((size_t)0, x.tree, y.tree);
    w.tree = z;
    w.weight = x.weight + y.weight;

    // 合并的树推入最小堆
    heap.push(w);
  }

  std::cout << heap.size() << std::endl;
  return heap.top().tree;
}

int main()
{
  int weight[] = {6, 2, 3, 3, 4, 9 };
  LinkedBinaryTree<size_t>* huffman_tree = BuildHuffmanTree(weight, 6);
  huffman_tree->PreOrderOutput();
  return 0;
}
