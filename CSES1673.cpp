#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;


const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


const long long INF = LONG_MAX;

struct Edge {
    int from, to;
    long long weight;
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;

    for(int i = 0; i < m; i++) {
        int a, b;
        ll x;
        cin >> a >> b >> x;
        edges.pb({a, b, x});
    }


    vector<ll> dist(n + 1, -INF);
    dist[1] = 0;

    for(int i = 0; i < n - 1; i++) {
        for(auto e: edges) {
            if(dist[e.from] != -INF)
                dist[e.to] = max(dist[e.to], dist[e.from] + e.weight);
        }
    }

    vector<bool> in_cycle(n + 1, false);

    for (int i = 0; i < n; i++) {
        for (auto e : edges) {
            if (dist[e.from] == -INF) continue;
            if (dist[e.from] + e.weight > dist[e.to]) {
                dist[e.to] = INF;
                in_cycle[e.to] = true;
            }
            if (in_cycle[e.from])
                in_cycle[e.to] = true;
        }
    }

    if (in_cycle[n]) cout << -1 << '\n';
    else cout << dist[n] << '\n';

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/