#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair


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
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;
        ll a[n],b[n];

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        ll ans = 0;

        priority_queue<pair<ll,ll> > que;

        
        for(int i = 0; i < n; i++) {
            que.push(mp(a[i], b[i]));
        }
        

        while(k--) {
            pair<ll, ll> p = que.top();
            que.pop();
            if(p.first == 0) break;
            ans += p.first;
            que.push(mp(max((ll)0, p.first - p.second), p.second));
        }

        cout << ans << '\n';
    }

}

/*
RILY <3
NEVER GIVE UP!!!


21
349
27
500000500000
47

*/