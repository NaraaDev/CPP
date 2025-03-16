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
    
    ll ans = 0;

    set<int> s;

    int n, k;
    cin >> n >> k;

    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < k; i++) {
        s.insert(a[i]);
    }
    if(s.size() >= k) {
        ans += max((ll)((s.size() - k) * s.size()), (ll)1);
    }
    for(int i = k; i < n; i++) {
        s.insert(a[i]);
        if(s.size() >= k) {
            ans += max((ll)((s.size() - k) * s.size()), (ll)1);
        }
    }

    cout << ans;    

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/