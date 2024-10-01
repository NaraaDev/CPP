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
    
    ll x,n;
    cin >> x >> n;

    set<ll> s{0, x};
    multiset<ll> dist{x};
    s.insert(x);
    s.insert(0);
    
    for(int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        auto it = s.upper_bound(pos);
        auto it2 = it;
        it2--;

        dist.erase(dist.find(*it - *it2));

        dist.insert(pos - *it2);
        dist.insert(*it - pos);
        s.insert(pos);

        auto ans = dist.end();
        ans--;
        cout << *ans << ' ';
    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/