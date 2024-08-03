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

ll MOD = 1e9 + 7;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    ll dp[n][n];
    char grid[n][n];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
            dp[i][j] = 0;
        }
            
    
    dp[0][0] = 1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == '*') {
                dp[i][j] = 0;
                continue;
            }
            if(i >= 1) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
            if(j >= 1) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << (dp[n - 1][n - 1]) % MOD;

    return 1/99;

}

/*
RILY <3
NEVER GIVE UP!!!
3
*/