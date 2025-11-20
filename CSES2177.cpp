#include<bits/stdc++.h>


#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;

const ll MOD = 1e9 + 7;
const int N = 2e5 + 5;


ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

vector<vector<int> > nodes(N);
vector<int> color(N, 0);
vector<int> parent(N, 0);
int cycleStart, cycleEnd;
bool dfs(int v, int deed) {
    color[v] = 1;
    for(int u: nodes[v]) {
        if(color[u] == 0 && deed != u) {
            parent[u] = v;
            if(dfs(u, v))
                return true;
        } else if(color[u] == 1 && deed != u) {
            cycleEnd = v;
            cycleStart = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void uCan() {

    int n, m;
    cin >> n >> m;

    cycleStart = -1;
    int u , v;
    vector<pair<int, int> > routes;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        nodes[u].pb(v);
        nodes[v].pb(u);
        routes.pb({u, v});
    }

    for(int i = 1; i <= n; i++) {
        if(color[i] == 0 && dfs(i, -1))
            break;
    }

    if(cycleStart == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.pb(cycleStart);
        for(int v = cycleEnd; v != cycleStart; v = parent[v]) {
            cycle.pb(v);
        }
        cycle.pb(cycleStart);

        map<pair<int, int>, int> cache;
        
        for(int i = 0; i < cycle.size() - 1; i++) {
            int x = cycle[i];
            int u = cycle[i + 1];
            cache[{u, x}] = 1;
            cache[{x, u}] = 1;
            cout << x << ' ' << u << '\n';
        }

        for(int i = 0; i < m; i++) {
            auto [x, u] = routes[i];
            if(x > u) swap(x, u);
            if(cache.find({x, u}) == cache.end()) {
                cout << x << ' ' << u << '\n';
                cache[{x, u}] = 1;
                cache[{u, x}] = 1;
            }
        }
        
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    // cin >> t;
    t = 1;
    while(t--) {
        uCan();
    }

    return 0;

}

/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever our souls are made of, hers and mine are the same.
People aren’t prisoners of fate, they’re prisoners of their own minds.
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/