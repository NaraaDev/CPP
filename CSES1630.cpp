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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, ans = 0;
    cin >> n;

    pair<ll, ll> p[n];

    for(int i = 0; i < n; i++)
        cin >> p[i].F >> p[i].S;

    sort(p, p + n);

    ll start = 0;

    for(int i = 0; i < n; i++) {
        start += p[i].F;
        ans += (p[i].S - start);
    }

    cout << ans;

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/