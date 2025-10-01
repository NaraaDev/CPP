#include <bits/stdc++.h>
using namespace std;

int n;

bool cmp(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    string res;
    cin >> res;
    return res == "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> pos(n);
    iota(pos.begin(), pos.end(), 1);

    stable_sort(pos.begin(), pos.end(), cmp);

    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++) {
        ans[pos[i]] = i + 1;
    }

    cout << "!";
    for (int i = 1; i <= n; i++) {
        cout << " " << ans[i];
    }
    cout << endl;
    cout.flush();

    return 0;
}
