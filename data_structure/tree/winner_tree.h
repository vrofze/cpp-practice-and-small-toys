#ifndef WINNER_TREE_H
#define WINNER_TREE_H

template<class T>
class WinnerTree
{
 public:
  virtual ~WinnerTree() { }
  // 初始化赢者树
  virtual void initialize(T *player, int player_num) = 0;
  // 返回最后赢者
  virtual int winner() = 0;
  // 在参赛者player的分数变化后重赛
  virtual void replay(int player) = 0;
};

#endif
