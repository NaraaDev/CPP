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

    vector<pair<int,int> > v;

    for(int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v.pb(mp(s, 1));
        v.pb(mp(e, -1));
    }

    sort(v.begin(), v.end());


    int cur = 0, ans = 0;

    for(int i = 0; i < v.size(); i++) {
        cur += v[i].S;
        ans = max(ans, cur);
    }

    cout << ans << '\n';

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
2
*/