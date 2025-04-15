#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].pb(mp(b, cost));
    }

    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    dist[1][0] = 0;

    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [cost, u, used] = pq.top(); pq.pop();
        if (cost > dist[u][used]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v][used] > dist[u][used] + w) {
                dist[v][used] = dist[u][used] + w;
                pq.push({dist[v][used], v, used});
            }
            if (used == 0) {
                ll discounted = dist[u][used] + w / 2;
                if (dist[v][1] > discounted) {
                    dist[v][1] = discounted;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }

    cout << dist[n][1] << '\n';
    return 0;
}

/*
RILY <3
NEVER GIVE UP!!!
*/
