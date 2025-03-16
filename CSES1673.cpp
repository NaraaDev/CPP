#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    vector<int>ans(n, 0);

    vector<vector<pair<int,int> > > adj(n);
    vector<bool>vis(n, false);

    for(int i = 0; i < m; i++) {
        int a,b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
    }

    queue<pair<int,int> > q;
    q.push(mp(0,0));
    while(!q.empty()) {
        auto front = q.front();
        q.pop();
        vis[front.F] = true;

        for(auto node: adj[front.F]) {
            if(!vis[node.F]) {
                int maxPrice = max(ans[front.F] + front.S, ans[node.F]);
                ans[node.F] = maxPrice;
                q.push(mp(node.F, maxPrice));
            }
        }
    }
    for(int i = 0; i < n; i++)  
        cout << ans[i] << ' ';
    cout << ans[n];

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
5
*/