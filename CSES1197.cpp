#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int,int,int>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    const long long INF = 1e18;
    vector<long long> dist(n+1, 0);
    vector<int> parent(n+1, -1);
    int x = -1;

    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto [u,v,w] : edges) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                x = v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        int y = x;
        for (int i = 0; i < n; i++) y = parent[y];

        vector<int> cycle;
        for (int cur = y;; cur = parent[cur]) {
            cycle.push_back(cur);
            if (cur == y && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }
}
