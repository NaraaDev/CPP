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

    int u, v;

    vector<pair<int, int> > ans;

    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        if(u > v) swap(u, v);

        ans.pb({u, v});
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i < m; i++)
        cout << ans[i].F << ' ' << ans[i].S << '\n';

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;

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