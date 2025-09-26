#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'007;

pair<int, int> optimal(int n, long long time, vector<long long> &lis) {
    long long total_time = 0, penalty = 0;
    for (int i = 0; i < n; i++) {
        if (total_time + lis[i] > time) return {i, static_cast<int>(penalty)};
        total_time += lis[i];
        penalty = (penalty + total_time) % MOD;
    }
    return {n, static_cast<int>(penalty)};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long t;
    cin >> n >> t;

    long long a, b, c, t0;
    cin >> a >> b >> c >> t0;

    vector<long long> lis(n);
    lis[0] = t0;
    for (int i = 1; i < n; i++) {
        lis[i] = ((a * lis[i - 1] + b) % c) + 1;
    }

    sort(lis.begin(), lis.end());
    auto ans = optimal(n, t, lis);
    cout << ans.first << " " << ans.second << "\n";

    return 0;
}
