#ifndef WINNER_TREE_H
#define WINNER_TREE_H

#include <iostream>

template<class T>
class WinnerTree
{
 public:
  virtual ~WinnerTree() { }
  // 初始化赢者树
  virtual void initialize(T *, int) = 0;
  // 返回最后赢者
  virtual size_t winner() = 0;
  // 在参赛者player的分数变化后重赛
  virtual void replay(size_t player) = 0;
};

template<class T>
class CompleteWinnerTree: public WinnerTree<T>
{
 public:
  CompleteWinnerTree(T *array, int num)
    {
      tree = nullptr;
      initialize(array, num);
    }
  ~CompleteWinnerTree() { delete[] tree; }
  void initialize(T*, int);
  size_t winner() { return tree[1]; }
  void replay(size_t);
 private:
  inline size_t max(size_t n, size_t m)
  {
    return player[n] >= player[m] ? n : m;
  }
  T *player;
  size_t *tree;
  size_t player_num;
};

template<class T>
void CompleteWinnerTree<T>::initialize(T *player, int num)
{
  player_num = num;
  this->player = player;
  tree = new size_t[2 * num];
  for(size_t i = 0; i < num; ++i) // 将参赛者的索引放在tree的num...2*num-1
    tree[num + i] = i;
  for(size_t i = num - 1; i >= 1; --i){ // 从num至1,比赛
    tree[i] = max(tree[2 * i], tree[2 * i + 1]);
  }
}

template<class T>
void CompleteWinnerTree<T>::replay(size_t player)
{
  size_t index = (player_num + player) / 2; // 将改动参赛者所在子树依次重赛
  while(index >= 1){
    tree[index] = max(tree[2 * index], tree[2 * index + 1]);
    index = index / 2;
  }
}

#endif
