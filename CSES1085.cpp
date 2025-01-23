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
    int n, k;
    cin >> n >> k;

    int a[n];
    ll l = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        l = max(l, (ll)a[i]);
    }
        
    
    ll r = accumulate(a, a + n, 0LL);
    ll ans = r;
    while(l <= r) {
        ll mid = (l + r) / 2;
        int team = 1;
        ll sum = 0;

        for(int i = 0; i < n; i++) {
            if(sum + a[i] > mid) {
                sum = a[i];
                team++;
            } else {
                sum += a[i];
            }
        }
        
        if(team <= k) {
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;


    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/