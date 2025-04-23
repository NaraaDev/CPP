#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    int rounds = 1;
    for (int i = 2; i <= n; i++) {
        if (pos[i] < pos[i - 1])
            rounds++;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;

        int x = arr[a], y = arr[b];

        set<int> affected;
        for (int d : {-1, 0, 1}) {
            if (1 <= x + d && x + d <= n) affected.insert(x + d);
            if (1 <= y + d && y + d <= n) affected.insert(y + d);
        }

        for (int i : affected) {
            if (i > 1 && pos[i] < pos[i - 1]) rounds--;
        }

        swap(arr[a], arr[b]);
        pos[x] = b;
        pos[y] = a;

        for (int i : affected) {
            if (i > 1 && pos[i] < pos[i - 1]) rounds++;
        }

        cout << rounds << '\n';
    }

    return 0;
}
