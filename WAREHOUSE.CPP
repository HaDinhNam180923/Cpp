#include <bits/stdc++.h>
using namespace std;

int N, T, D;        
int a[1000];        
int t[1000];        
int dp[1000][1000]; 
// ans = max(dp[i][k]) với k = 0,1,2,...,T;i = 1,2,...,N
void input()
{
    cin >> N >> T >> D;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= N; i++)
        cin >> t[i];
}
void solve()
{
    for (int i = 1; i <= N; i++)
    {
        for (int k = 1; k <= T; k++)
        {
            if (k < t[i])
            {
                dp[i][k] = -1000000ll;
            }
            else
            {
                for (int j = i - D; j < i; j++)
                {
                    if (j >= 0)
                    {
                        dp[i][k] = max(dp[i][k], dp[j][k - t[i]] + a[i]);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= T; i++)
        for (int j = 1; j <= N; j++)
            ans = max(ans, dp[j][i]);
    printf("%d", ans);
}
int main()
{
    input();
    solve();
    return 0;
}