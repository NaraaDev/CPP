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

bool isPrime(ll n) {
    if(n <= 2) return true;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }

    return true;

}

void solve() {

    ll n;
    cin >> n;

    if(isPrime(n)) {
        cout << 1 << ' ' << n - 1 << '\n';
        return;
    }

    if(n % 2 == 0) {
        cout << n / 2 << ' ' << n / 2 << '\n';
    } else {
        ll ans = LLONG_MAX;
        int a = -1, b = -1;
        vector<ll> div;
        for(int i = 3; i <= sqrt(n); i++) {
            if(n % i == 0) div.pb(i);
            if(n % i == 0 && n / i != i) {
                div.pb(n / i);
            }
        }

        for(int i = 0; i < div.size(); i++) {
            if(lcm(div[i], n - div[i]) <= ans) {
                ans = lcm(div[i], n - div[i]);
                a = div[i];
                b = n - div[i];
            }
        }

        cout << a << ' ' << b << '\n';

    }

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