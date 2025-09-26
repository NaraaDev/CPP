#include <bits/stdc++.h>
using namespace std;

using ld = long double;

vector<pair<ld, ld>> sides(int n) {
    ld ratio = 0.70710678118654746171500846685376018285751342773438L; // 2^(-1/2)
    vector<pair<ld, ld>> arr = {
        {0.42044820762685725101803768666286487132310867309570L, // 2^(-5/4)
         0.59460355750136051344867382795200683176517486572266L} // 2^(-3/4)
    };
    while ((int)arr.size() < n) {
        ld z = arr.back().first;
        arr.push_back({ratio * z, z});
    }
    return arr;
}

pair<bool, ld> merge(vector<ld> &arr, vector<pair<ld, ld>> &s) {
    ld needed = 2.0 - arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] >= 2.0 * needed) {
            arr[i] -= 2.0 * needed;
            arr[i-1] += needed;
            return {true, needed * s[i].second}; // i corresponds to arr[i] which is correct
        } else {
            needed = 2.0 * needed - arr[i];
        }
    }
    return {false, 0.0};
}

ld tape(int n, vector<ld> &arr) {
    if (n <= 0) return -1.0;
    ld length = 0.0;
    vector<pair<ld, ld>> s = sides(n-1);
    while (!arr.empty() && arr[0] < 2.0) {
        auto [m, l] = merge(arr, s);
        length += l;
        if (!m) break;
    }
    if (arr.empty() || arr[0] < 2.0) return -1.0;
    return s[0].second + length;
}

int trim_right(int n, vector<ld> &arr) {
    while (!arr.empty() && arr.back() == 0.0) {
        arr.pop_back();
        n--;
    }
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ld> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    n = trim_right(n, arr);
    ld t = tape(n, arr);
    if (t < 0) cout << "impossible\n";
    else cout << fixed << setprecision(20) << t << "\n";

    return 0;
}
