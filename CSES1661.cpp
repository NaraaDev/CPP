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
    int n, x;
    cin >> n >> x;

    ll nums[n];

    for(int i = 0; i < n; i++)
        cin >> nums[i];
    
    ll curSum = 0, ans = 0;
    map<ll, int> sums;
    sums[0] = 1;
    for(int i = 0; i < n; i++) {
        curSum += nums[i];
        ans += sums[curSum - x]; 
        sums[curSum]++;
    }

    cout << ans;
    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/