#include <iostream>
#include <climits>

int p[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };

inline int max(int m, int n)
{
    return m >= n ? m : n;
}

int memoized_cut_rod_aux(int n, int *r)
{
    if(r[n] >= 0)
        return r[n];
    int q;
    if(n == 0)
        q = 0;
    else{
        q = INT_MIN;
        for(int i = 1; i <= n; ++i){
            q = max(q, p[i] + memoized_cut_rod_aux(n - i, r));
        }
    }
    r[n] = q; // assert q to r[n]
    return q;
}

int memoized_cut_rod(int n)
{
    int *r = new int[n + 1];
    for(int i = 0; i <= n; ++i){
        r[i] = INT_MIN;
    }
    return memoized_cut_rod_aux(n, r);
}

int bottom_up_cut_rod(int n)
{
    int *r = new int[n + 1];
    r[0] = 0; // init the first element

    // int q = 0;
    // for(int i = 1; i <= n; ++i){
    //     q = max(q, p[i] + r[n - i]);
    //     r[i] = q;
    // }  // child problem is not the best

    for(int i = 1; i <= n; ++i){
        int q = INT_MIN;
        for(int j = 1; j <= i; ++j)
            q = max(q, p[j] + r[i - j]);
        r[i] = q; // r[i] not r[n]; caculate best 1..n
    }
    int result = r[n];
    delete[] r;
    return result;
}

int main()
{
    // std::cout << memoized_cut_rod(10) << std::endl; // n can't greater than 10
    std::cout << bottom_up_cut_rod(4) << std::endl;
    return 0;
}
