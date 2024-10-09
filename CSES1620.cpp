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
    int n, t;
    cin >> n >> t;

    vector<ll> v(n);

    ll ans = 0;

    for(int i = 0;  i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    ll low = 0, high = v[0] * t;


    while(low <= high) {
        ll mid = low + (high - low) / 2;
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            sum += mid / v[i];
            if(sum >= t) break;
        }
        if(sum >= t) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    cout << ans;

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/