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

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,x;
    cin >> n >> x;

    int price[n], page[n];

    for(int i = 0; i < n; i++)
        cin >> price[i];
    for(int i = 0; i < n; i++)
        cin >> page[i];

    int dp[x + 1];

    for(int i = 0; i <= x; i++)
        dp[i] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
        }

    }

    cout << dp[x];
    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/