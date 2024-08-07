#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back


ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    if (a == b)
        return a;
 
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

using namespace std;

vector<vector<int> > cities(100005);
vector<int> parent(100005, -1);
vector<int> cycle;

vector<bool> vis(100005);

vector<int> routes;

bool dfs(int u, int p) {
    vis[u] = true;
    parent[u] = p;

    for (int v : cities[u]) {
        if (!vis[v]) {
            if (dfs(v, u)) return true;
        } else if (v != p) {
            cycle.push_back(v);
            for (int x = u; x != v; x = parent[x])
                cycle.push_back(x);
            cycle.push_back(v);
            return true;
        }
    }
    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        cities[a].pb(b);
        cities[b].pb(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i, -1)) {
            cout << cycle.size() << '\n';
            for (int node : cycle)
                cout << node << ' ';
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
    
    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/