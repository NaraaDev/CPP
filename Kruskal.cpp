#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define edge tuple<int, int, int>

const int MAX_N = 1e5 + 5;
int parent[MAX_N], rank_arr[MAX_N];

int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]);
    return parent[u];
}

bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (rank_arr[u] < rank_arr[v]) swap(u, v);
    parent[v] = u;
    if (rank_arr[u] == rank_arr[v]) rank_arr[u]++;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<edge> edges;

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges.push_back({cost, u, v});
    }

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        rank_arr[i] = 0;
    }

    sort(edges.begin(), edges.end());

    long long total = 0;
    int count = 0;

    for (auto [cost, u, v] : edges) {
        if (unite(u, v)) {
            total += cost;
            count++;
            if (count == n - 1) break;
        }
    }

    cout << total << '\n';

    return 0;
}
