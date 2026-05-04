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

vector<ll> twos;

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

    ll n, k;
    cin >> n >> k;

    vector<ll> ans;

    if(n % 2 == 1 && k == 3) {
        cout << n / 2 << ' ' << n / 2 << ' ' << 1 << '\n';
        return;
    } 
    else if(n % 2 == 0 && k == 3) {
        cout << (n - 1) / 2 << ' ' << (n - 1) / 2 <<  ' ' 
             << (n - ((n - 1) / 2) * 2) << '\n';
        return;
    } 
    else if(n % k == 0) {
        for(int i = 0; i < k; i++) {
            cout << n / k << ' ';
        }
        cout << '\n';
        return;
    }

    int pos = upper_bound(twos.begin(), twos.end(), (n - 1)) - twos.begin() - 1;

    while(pos >= 0 && k > 1) {
        if(twos[pos] <= n && n - twos[pos] >= k - 1) {
            n -= twos[pos];
            ans.pb(twos[pos]);
            k--;
        } else {
            pos--;
        }
    }

    if(k > 1) {
        for(int i = 1; i <= k; i++)
            ans.pb(1);
    } 
    else {
        ans.pb(n);
    }

    for(auto p: ans)
        cout << p << ' ';
    cout << '\n';
}

const ll MAXN = 2e9;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    ll pow = 1;

    while(pow <= MAXN / 2) {
        twos.pb(pow);
        pow *= 2;
    }

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