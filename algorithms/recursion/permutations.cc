#include <iostream>
#include <iterator>
#include <algorithm>

template<typename T>
void permutations(T list[], int k, int m)
{
  if(k == m){
    copy(list, list+m+1, std::ostream_iterator<T>(std::cout, ""));
    std::cout << std::endl;
  }
  else
    for(int i = k; i <= m; i++){
      std::swap(list[k], list[i]);
      permutations(list, k+1, m);
      std::swap(list[k], list[i]);
    }
}

int main()
{
  char list[]{'a', 'b', 'c', 'd'};
  permutations(list, 0, 3);
  std::cout << "net permutations:";
  std::next_permutation(list, list + 3);
  copy(list, list+4, std::ostream_iterator<char>(std::cout, ""));
}
