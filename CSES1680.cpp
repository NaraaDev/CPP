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

void uCan() {

    int n, m;
    cin >> n >> m;

    vector<vector<int> > nodes(n + 1);
    vector<int> indeg(n + 1, 0);
    int a, b;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        nodes[a].pb(b);
        indeg[b]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) q.push(i);
    }

    vector<int> topo;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        topo.pb(u);
        for(int node: nodes[u]) {
            if(--indeg[node] == 0) q.push(node);
        }
    }

    vector<int> dp(n + 1, -1e9), parent(n + 1, -1);

    dp[1] = 1;
    for(int u: topo) {
        if(dp[u] < 0) continue;
        for(int v: nodes[u]) {
            if(dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                parent[v] = u;
            }
        }
    }

    if(dp[n] < 0) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    cout << dp[n] << '\n';
    vector<int> path;

    for(int v = n; v != -1; v = parent[v])
        path.pb(v);
    
    reverse(path.begin(), path.end());

    for(int v: path)
        cout << v << ' ';

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