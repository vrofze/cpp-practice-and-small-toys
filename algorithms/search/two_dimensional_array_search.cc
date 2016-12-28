#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int col = array[0].size();
        int i = row - 1, j = 0;
        while(i >=0 && j < col){
            if(array[i][j] > target)
                --i;
            else if(array[i][j] < target)
                ++j;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    vector<vector<int> > array = {{1, 2, 3, 10}, {4, 5, 6, 11}, {7, 8, 9, 12}};
    Solution sol;
    bool ret = sol.Find(10, array);
    cout << ret << endl;
    return 0;
}
