#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll INF = LLONG_MAX;

// ll gcd(ll a, ll b)
// {
//     if (a == 0)
//         return b;
//     if (b == 0)
//         return a;
 
//     if (a == b)
//         return a;
 
//     if (a > b)
//         return gcd(a - b, b);
//     return gcd(a, b - a);
// }

using namespace std;

vector<ll> d(100005, INF);
vector<vector<pair<int,ll> > > adj(100005);
int n,m;


void dijkstra(int s) {

    d[s] = 0;
    using pii = pair<ll,int>;

    priority_queue<pii, vector<pii>, greater<pii> > q;
    
    q.push(mp(0, s));

    while(!q.empty()) {
        auto [d_v, v] = q.top();
        q.pop();

        if(d_v != d[v]) continue;

        for(auto edge: adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if(d[v] + len < d[to]) {
                d[to] = d[v] + len;
                q.push(mp(d[to], to));
            }

        }   
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
    }

    dijkstra(1);

    for(int i = 1; i <= n; i++) {
        cout << d[i] << ' ';
    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
0 5 2
*/