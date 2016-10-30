#include "winner_tree.h"

#include <iostream>

int main()
{
  int player[] = {4, 6, 5, 9, 8, 2, 3, 7};
  CompleteWinnerTree<int> tree(player, 8);
  std::cout << player[tree.winner()] << std::endl;
  player[7] = 1;
  tree.replay(7);
  std::cout << player[tree.winner()] << std::endl;
  return 0;
}
