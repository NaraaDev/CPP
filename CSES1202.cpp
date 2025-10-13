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
    
    vector<vector<pair<int, ll > > > nodes(n + 1);
    int a, b, c;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        nodes[a].pb({b, c});
    }

    vector<ll> maxx(n + 1, 0LL), minn(n + 1, LLONG_MAX), dist(n + 1, LLONG_MAX), ans(n + 1, 0);

    priority_queue<pair<ll, int> , vector<pair<ll, int>>, greater<pair<ll, int>> > pq;
    vector<bool> visited(n + 1, false);
    pq.push({0LL, 1});
    dist[1] = 0;
    ans[1] = 1;
    maxx[1] = 0;
    minn[1] = 0;
    while(!pq.empty()) {
        auto now = pq.top().second;
        pq.pop();
        if(visited[now] == true) continue;

        visited[now] = true;

        for(auto [to, cost]: nodes[now]) {
            ll alt = cost + dist[now];
            if(alt == dist[to]) {
                ans[to] = (ans[to] + ans[now]) % MOD;
                minn[to] = min(minn[to], minn[now] + 1);
                maxx[to] = max(maxx[to], maxx[now] + 1);
            } else if(alt < dist[to]) {
                minn[to] = minn[now] + 1;
                maxx[to] = maxx[now] + 1;
                dist[to] = dist[now] + cost;
                ans[to] = ans[now];
                pq.push({ dist[to], to});
            }
        }

    }

    cout << dist[n] << ' ' << (ans[n] % MOD) << ' ' << minn[n] << ' ' << maxx[n];

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