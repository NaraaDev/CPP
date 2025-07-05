#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 2, 0));

    if (x[1] == 0) {
        for (int v = 1; v <= m; ++v) dp[1][v] = 1;
    } else {
        dp[1][x[1]] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        if (x[i] == 0) {
            for (int v = 1; v <= m; ++v) {
                dp[i][v] = ((dp[i - 1][v - 1] + dp[i - 1][v]) % MOD + dp[i - 1][v + 1]) % MOD;
            }
        } else {
            int v = x[i];
            dp[i][v] = ((dp[i - 1][v - 1] + dp[i - 1][v]) % MOD + dp[i - 1][v + 1]) % MOD;
        }
    }

    int result = 0;
    for (int v = 1; v <= m; ++v) {
        result = (result + dp[n][v]) % MOD;
    }

    cout << result << endl;
    return 0;
}
