#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int countPlans(int N, int K1, int K2) {
    vector<int> dp(N + 1);
    dp[0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = K1; j <= K2 && i - j >= 0; ++j) {
            dp[i] = (dp[i] + dp[i - j - 1]) % MOD;
        }
    }

    return dp[N];
}

int main() {
    int N, K1, K2;
    cin >> N >> K1 >> K2;

    int result = countPlans(N, K1, K2);
    cout << result << endl;

    return 0;
}
