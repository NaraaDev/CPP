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

    int n,m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int> > > nodes(n + 1);

    int u, v, c;

    for(int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        nodes[u].pb({v, c});
    }

    vector<ll> ans;

    queue<tuple<int, int, int> > q;

    q.push(make_tuple(1, 0, 1));
    vector<map<pair<int, int>, int> > checkCycle(n + 1);

    while(!q.empty()) {

        auto [par, coin, len] = q.front(); q.pop();

        for(pair<int, int>  node: nodes[par]) {
            if(checkCycle[node.first].find({par, len + 1}) == checkCycle[node.first].end()) {
                checkCycle[node.first][{par, len + 1}] = 1;
                q.push(make_tuple(node.first, node.second + coin, len + 1));
                if(node.first == n) {
                    ans.push_back(node.second + coin);
                }
            }
        }

    }

    sort(ans.begin(), ans.end());

    for(ll num: ans)
        cout << num << ' ';

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