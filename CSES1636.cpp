#include<bits/stdc++.h>
 
#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back
 
 
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
 
const int MOD = 1e9 + 7;
 
int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,x;
    cin >> n >> x;
 
    int dp[x + 1];
    int coins[n];
    
    for(int i = 0; i < n; i++)
        cin >> coins[i];
    for(int i = 1; i <= x; i++)
        dp[i] = 0;
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = coins[i]; j <= x; j++) {
            dp[j] += dp[j - coins[i]];
            dp[j] %= MOD;
        }
    }
    cout << dp[x];
}
 
/*
RILY <3
NEVER GIVE UP!!!
3
*/