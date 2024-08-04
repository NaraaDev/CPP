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
        v.pb(mp(s, e));
        
    }

    sort(v.begin(), v.end());

    int ans = 1;

    int em = v[0].S;
    for(int i = 1; i < n; i++) {
        if(v[i].F < em) {
            em = min(em, v[i].S);
        } else{
            ans++;
            em = v[i].S;
        }
    }


    cout << ans;

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/