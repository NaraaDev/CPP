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
    int n, ind;
    cin >> n;
    multiset<int> values;
    
    pair<int, int> p[n];
    map<int, int> mp;
    vector< int > v[n + 1];

    for(int i = 0; i < n; i++) {
        cin >> p[i].F;
        p[i].S = i + 1;
    }

    sort(p, p + n);

    ind=1;
    mp[p[0].F]=1;
    for(int i=1; i<n; i++){
        if(p[i].F!=p[i-1].F){
            ind++;
            mp[p[i].F]=ind;
        }
    }

    for(int i=0; i<n; i++){
        v[mp[p[i].F]].pb(p[i].S);
    }
    int a[n];
    for(int i = 0; i < n; i++) {
        if(i > 0 && p[i-1].F != p[i].F){
            for(int j = 0; j < v[mp[p[i-1].F]].size(); j++) {
                values.insert(v[mp[p[i-1].F]][j]);
            }
        }
        auto it = values.lower_bound(p[i].second);
        
        if(it == values.begin()) {
            a[p[i].second - 1] = 0;
        } else {
            it--;
            a[p[i].second - 1] = *it;
        }

        

    }

    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/