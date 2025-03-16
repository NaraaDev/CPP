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
using pii = pair<int, int>;

const int N = 1e5 + 5;

vector<vector<pair<int, int> > > nodes(N);

vector<ll> d(N);
vector<int> maxV;

void dijkstra(int n) {
    d[n] = 0;
    d.assign(n, LLONG_MAX);
    maxV.assign(n, - 1);
    priority_queue<pii, vector<pii>, greater<pii>> q;

    q.push({0, n});

    while(!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();

        if(d_v != d[v])
            continue;
        
        for(auto edge: nodes[v]) {
            int to = edge.first;
            int len = edge.second;

            if(d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push({d[to], to});
                maxV[to] = v;
            }
        }

    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        nodes[a].pb(mp(b,cost));
        nodes[b].pb(mp(a,cost));
        
    }

    dijkstra(n);
    
    cout << d[1] << ' ';

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/