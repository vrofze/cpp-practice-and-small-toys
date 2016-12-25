#include <iostream>
#include <climits>

int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };

inline int max(int m, int n)
{
    return m >= n ? m : n;
}

int *cut = new int[51];

int cut_rod(int n)
{
    int max = 0;
    int temp = 0;
    if(n == 0)
        return 0;
    else{
        for(int i = 1; i <= n; ++i){
            if(cut[n - i] < 0)
                cut[n - i] = cut_rod(n - i);
            temp = p[i] + cut[n - i];
            if(temp > max)
                max = temp;
        }
        return max;
    }
}

int main()
{
    for(int i = 0; i <= 10; ++i)
        cut[i] = INT_MIN;
    std::cout << cut_rod(4) << std::endl; //cut_rod(n) n can't greater than 10
    return 0;
}
