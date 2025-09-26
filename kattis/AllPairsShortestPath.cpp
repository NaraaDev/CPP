#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool first_test_case = true;

    while (true) {
        int n, m, q;
        cin >> n >> m >> q;
        if (n + m + q == 0) break;

        if (!first_test_case) cout << "\n";
        first_test_case = false;

        vector<vector<long long>> mat(n, vector<long long>(n, LLONG_MAX / 2));
        vector<vector<int>> neg_cycle(n, vector<int>(n, 0));
        vector<vector<int>> neg_mem(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) mat[i][i] = 0;

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if ((u != v || w < 0) && mat[u][v] > w) mat[u][v] = w;
        }

        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (mat[i][k] != LLONG_MAX / 2 && mat[k][j] != LLONG_MAX / 2 &&
                        mat[i][j] > mat[i][k] + mat[k][j])
                        mat[i][j] = mat[i][k] + mat[k][j];

        for (int i = 0; i < n; i++) {
            neg_mem[i][i] = 1;
            neg_cycle[i][i] = mat[i][i] < 0;
        }

        for (int i = 0; i < q; i++) {
            int u, v;
            cin >> u >> v;

            if (mat[u][v] >= LLONG_MAX / 2) {
                cout << "Impossible\n";
            } else if (neg_mem[u][v]) {
                if (neg_cycle[u][v]) cout << "-Infinity\n";
                else cout << mat[u][v] << "\n";
            } else {
                bool neg = false;
                for (int s = 0; s < n; s++) {
                    if (s == u || s == v) continue;
                    if (mat[u][s] < LLONG_MAX / 2 && mat[s][v] < LLONG_MAX / 2 && neg_cycle[s][s]) {
                        neg = true;
                        neg_cycle[u][v] = 1;
                        break;
                    }
                }
                if (!neg) neg_cycle[u][v] = 0;
                neg_mem[u][v] = 1;

                if (neg) cout << "-Infinity\n";
                else cout << mat[u][v] << "\n";
            }
        }
    }

    return 0;
}