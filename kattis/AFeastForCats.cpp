#include <bits/stdc++.h>
using namespace std;

bool prims(int n, vector<vector<int>>& adj, int m) {
    vector<int> best(n, 0);
    vector<bool> visited(n, false);
    visited[0] = true;

    set<int> remaining;
    for (int i = 1; i < n; i++) remaining.insert(i);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
    int edges = 0, dist = 0;

    for (int i = 1; i < n; i++) {
        heap.push({adj[0][i], i});
        best[i] = adj[0][i];
    }

    while (edges < n-1) {
        pair<int,int> top;
        while (true) {
            top = heap.top();
            heap.pop();
            if (!visited[top.second]) break;
        }
        int w = top.first, v = top.second;

        edges++;
        dist += w;
        if (dist + n > m) return false;

        visited[v] = true;
        remaining.erase(v);

        for (int u : remaining) {
            if (adj[v][u] < best[u]) {
                best[u] = adj[v][u];
                heap.push({adj[v][u], u});
            }
        }
    }
    return n + dist <= m;
}



void solve(int m, int c) {
    vector<vector<int>> adj(c, vector<int>(c, 0));
    for (int i = 0; i < (c*(c-1))/2; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    if (m < c) {
        cout << "no\n";
    } else {
        cout << (prims(c, adj, m) ? "yes\n" : "no\n");
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, c;
        cin >> m >> c;
        solve(m, c);
    }
    return 0;
}
