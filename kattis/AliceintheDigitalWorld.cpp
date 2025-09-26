#include <bits/stdc++.h>
using namespace std;

long long max_weight(long long lo, const vector<long long> &weights) {
    long long best = 0, pre = 0, run = 0;
    for (auto w : weights) {
        if (w < lo) {
            best = max(best, run ? run + pre : 0LL);
            pre = run = 0;
        } else if (w == lo) {
            best = max(best, run ? run + pre : 0LL);
            run = lo + pre;
            pre = 0;
        } else {
            pre += w;
        }
    }
    return run ? max(best, run + pre) : best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, lo;
        cin >> n >> lo;
        vector<long long> weights(n);
        for (int i = 0; i < n; i++) cin >> weights[i];

        cout << max_weight(lo, weights) << "\n";
    }

    return 0;
}
