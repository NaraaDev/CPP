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
ll INF = 1e9 + 5;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    int nums[n];

    for(int i = 0; i < n; i++)
        cin >> nums[i];
    
    vector<ll> dp(n + 1, INF);

    
    for(int i = 0; i < n; i++) {
        *lower_bound(dp.begin(), dp.end(), nums[i]) = nums[i];
    }

    cout << (lower_bound(dp.begin(), dp.end(), INF) - dp.begin());

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/