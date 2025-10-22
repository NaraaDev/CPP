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

int ans = INT_MAX;

void dfs(int u, int parent, vector<vector<int> > &nodes, vector<bool> &visited, int cnt) {


    if(ans < cnt) return;

    if(visited[u] && cnt > 2) {
        ans = min(ans, cnt);
    }

    visited[u] = true;
    for(auto v: nodes[u]) {
        if(parent != v) {
            dfs(v, parent, nodes, visited, cnt + 1);
        }
    }

}

void uCan() {

    int n, m;
    cin >> n >> m;

    vector<vector<int > > nodes(n + 1);

    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        nodes[u].pb(v);
        nodes[v].pb(u);
    }
    dfs(1, -1, nodes, visited, 0);

    cout << (ans == INT_MAX ? -1 : ans) << '\n';

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