#include<bits/stdc++.h>


#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;


ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll binpow(ll a, ll b) {

    ll res = 1;

    while(b > 0) {
        if(b & 1) {
            res = res * a;
        }
        a = a * a;
        b /= 2;
    }
    return res;
}

void solve() {

    int n;
    cin >> n;
    
    vector<int> nodes(n + 1, 0);

    int cnt = 0;
    int oldu, oldv;
    cin >> oldu >> oldv;
    if(oldu > oldv) swap(oldu, oldv);
    for(int i = 1; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        if(oldu != u && oldv != u && oldu != v && oldv != v) cnt++;
        oldu = u;
        oldv = v;
    }


    cout << cnt << '\n';

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;

}

/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/