#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>

const int MAX_N = 1e5 + 5;
vector<vector<pii>> adj(MAX_N);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int from, to, cost;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }

    vector<bool> used(n + 1, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});

    ll total_cost = 0;

    while (!pq.empty()) {
        auto [cost, u] = pq.top(); pq.pop();
        if (used[u]) continue;

        used[u] = true;
        total_cost += cost;

        for (auto [v, w] : adj[u]) {
            if (!used[v]) {
                pq.push({w, v});
            }
        }
    }

    cout << total_cost << '\n';

    return 0;
}
