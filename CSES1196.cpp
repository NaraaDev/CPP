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
 
struct Node {
    int to;
    ll len;
};
 
void uCan() {
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<vector<Node>> nodes(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        nodes[u].push_back({v, l});
    }
 
    vector<priority_queue<ll> > costs(n + 1);
    priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll, int> >> pq;
 
    pq.push({0, 1});
    costs[1].push(0);
 
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(costs[u].top() < d) continue;
        for (auto &edge : nodes[u]) {
            ll nd = d + edge.len;
 
            if ((int)costs[edge.to].size() < k) {
                costs[edge.to].push(nd);
                pq.push({nd, edge.to});
            } else {
                if (nd < costs[edge.to].top()) {
                    costs[edge.to].pop();
                    costs[edge.to].push(nd);
                    pq.push({nd, edge.to});
                }
            }
        }
    }
 
    vector<ll> ans;

    while(!costs[n].empty()) {
        ans.pb(costs[n].top());
        costs[n].pop();
    }

    sort(ans.begin(), ans.end());
    for (auto x : ans) cout << x << " ";
    cout << "\n";
 
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