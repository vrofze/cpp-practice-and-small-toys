#include <iostream>
#include <climits>

int p[] = {30, 35, 15, 5, 10, 20, 25 };

void martix_chain_order(int **m, int **r, int n)
{
    for(int i = 0; i <= n; ++i) // init m[,]
        m[i][i] = 0;

    for(int l = 2; l <= n; ++l)
        for(int i = 1; i <= n - l + 1; ++i){
            int j = i + l - 1; // end
            m[i][j] = INT_MAX;
            int q;
            for(int k = i; k < j; ++k){
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    r[i][j] = k;
                }
            }
        }
}

void print_optimal_parens(int **s, int i, int j)
{
    if(i == j)
        std::cout << "A" << i;
    else{
        std::cout << "(";
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j] + 1, j);
        std::cout << ")";
    }
}

void martix()
{
    const int n = 6;
    int **m = new int*[n + 1];
    for(int i = 0; i <= n; ++i)
        m[i] = new int[n + 1];
    int **r = new int*[n + 1];
    for(int i = 0; i <= n; ++i)
        r[i] = new int[n + 1];
    martix_chain_order(m, r, n);
    std::cout << m[1][n] << std::endl;
    print_optimal_parens(r, 1, n);
    std::cout << std::endl;
}

int main()
{
    martix();
    return 0;
}
