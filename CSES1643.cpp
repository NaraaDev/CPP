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
    int n;
    cin >> n;
    ll a[n];

    for(int i = 0; i < n; i++) 
        cin >> a[i];
    
    ll ans = INT_MIN;
    ll cur = 0;
    for(int i = 0; i < n; i++) {
        cur = max(cur + a[i], a[i]);
        ans = max(ans, cur);
    }


    cout << ans;

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/