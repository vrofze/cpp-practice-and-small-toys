//#include "ArrayList"
//#include "VectorList.h"
#include "LinkedList.h"

#include <iostream>

using namespace std;

int main()
{
  // ArrayList<int> list(20);
  // VectorList<int> list(20);
  LinkedList<int> list;

  if(list.empty())
    cout << "list is empty" << endl;
  list.insert(0, 10);
  list.insert(1, 20);
  cout << list << endl;
  cout << list.size() << endl;
  list.push_back(30);
  list.push_back(40);
  list.push_back(50);
  cout << list << endl;
  cout << list.empty() << endl;
  cout << list.indexOf(60) << endl;
  list.erase(0);
  cout << list << endl;
  cout << list.get(1) << endl;

  cout << "======" << endl;
  cout << (624%100)/10 << endl;
  // test iterator
  // for(auto it = list.begin(); it != list.end(); ++it)
  //   cout << *it << " ";
  // cout << endl;
  return 0;
}
