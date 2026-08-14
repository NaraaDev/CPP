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

    int n, r, b;
    cin >> n >> r >> b;

    string ans = "";

    int maxFreq = r / (b + 1) + (r % (b + 1) != 0);
    for(int i = 0; i < maxFreq; i++) {
        ans += "R";
    }
    ans += "B";
    r -= maxFreq;
    b --;
    while(r - maxFreq >= b && r - maxFreq >= 0 && b > 0) {
        for(int i = 0; i < maxFreq; i++)
            ans += "R";
        ans += "B";
        r -= maxFreq;
        b--;
    }

    while(b > 0 || r > 0) {
        if(r > 0) ans += "R";
        if(b > 0) ans += "B";
        b--;
        r--;
    }

    cout << ans << '\n';

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