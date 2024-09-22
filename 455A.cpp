#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    if (a == b)
        return a;
 
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    ll a[n + 1];
    ll num = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        num = max(num, a[i]);
    }
    ll cnt[num + 1];

    for(int i = 0; i <= num; i++)
        cnt[i] = 0;
    
    for(int i = 0; i < n; i++)
        cnt[a[i]]++;

    ll dp[num + 1];
    dp[0] = 0;
    dp[1] = cnt[1];

    for(int i = 2; i <= num; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);

    cout << dp[num];
    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
10
*/