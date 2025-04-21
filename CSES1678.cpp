#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int vis[MAXN], parent[MAXN];
int cycle_start = -1, cycle_end = -1;

bool dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 0) {
            parent[v] = u;
            if (dfs(v)) return true;
        } else if (vis[v] == 1) {
            cycle_start = v;
            cycle_end = u;
            return true;
        }
    }
    vis[u] = 2;
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            if (dfs(i)) break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << '\n';
        for (int v : cycle)
            cout << v << ' ';
        cout << '\n';
    }

    return 0;
}
/*
RILY <3
NEVER GIVE UP!!!
*/