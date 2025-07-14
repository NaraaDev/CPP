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

ll binpow(ll a, ll b, ll mod) {

    ll res = 1;

    while(b > 0) {
        if(b & 1) {
            res = res * a % mod;
        }
        a = a * a;
        a %= mod;
        b >>= 1;
    }

    return res % MOD;

}

void uCan() {

    ll a, b, c;
    cin >> a >> b >> c;

    ll exponent = binpow(b, c, MOD - 1);
    ll result = binpow(a, exponent, MOD);
    cout << result << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
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
*/