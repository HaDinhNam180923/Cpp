#include <bits/stdc++.h>
using namespace std;

// Line 1: n (1 <=  n <= 10^6)
// Line 2: a0, . . . ,an-1 ( 1  <=  ai <= 10^6)
// Line 3: m (1  <= m <= 10^6)
// Line k+3 (k=1, . . ., m): ik, jk (0  <=  ik < jk < n)
// rmq(i1,j1) = min {A[i1], ..., A[j1]} = rmq1 
// Q =  rmq1 + rmq2 + ... + rmqm 
int n, M[23][1000009], A[1000009];
// M[j][i] la chi so cua phan tu co gia tri nho nhat trong doan co do dai 2^j va bat dau o i  


// sparse table 
void preprocessing()
{
    for (int j = 0; (1 << j) <= n; j++)
    {
        for (int i = 0; i < n; i++)
            M[j][i] = -1;
    }

    for (int i = 0; i < n; i++)
        M[0][i] = i;
        // M[j][i] tim duoc bang cach tinh A cua 2 nua, moi nua có do dai 2^j-1 
    for (int j = 1; (1 << j) <= n; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            if (A[M[j - 1][i]] < A[M[j - 1][i + (1 << (j - 1))]])
            {
                M[j][i] = M[j - 1][i];
            }
            else
            {
                M[j][i] = M[j - 1][i + (1 << (j - 1))];
            }
        }
    }
}
// de tinh rmq, ta dua vao 2 doan con dai 2^k bao phu het doan can tim
// nhu vay k =(int) log2 (do dai doan can tim)  sau do so sanh A nhu tren  
int rmq(int i, int j)
{
    int k = log2(j - i + 1);
    int p2k = (1 << k); // pow(2,k) = 2^k 
    if (A[M[k][i]] <= A[M[k][j - p2k + 1]])
    {
        return M[k][i];
    }
    else
    {
        return M[k][j - p2k + 1];
    }
}

int main()
{
    cin >> n; 
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    preprocessing();

    int Q = 0;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Q += A[rmq(a, b)];
    }
    cout << Q;
    return 0;
}
