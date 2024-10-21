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
    int n;
    cin >> n;

    int nums[n];

    for(int i = 0; i < n; i++)
        cin >> nums[i];
    
    ll ans = 0, sums = 0;
    map<ll, int> mp;
    mp[0] = 1;
    for(int i = 0; i < n; i++) {
        sums += nums[i];
        ans += mp[(sums % n + n) % n];
        mp[(sums % n + n) % n]++;
    }

    cout << ans;

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/