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

    pair<ll, ll> tree[n];

    for(int i = 0; i < n; i++)
        cin >> tree[i].F >> tree[i].S;
    
    int ans = 1;
    int nearestLeft = tree[0].F;

    vector<ll > v;

    for(int i = 1; i < n; i++)
        v.pb(tree[i].F);
    

    for(int i = 1; i < n; i++) {
        if(i == n - 1) {
            ans++;
            continue;
        }
        if(tree[i].F - tree[i].S > nearestLeft) {
            ans++;
            nearestLeft = tree[i].F;
        }
        else {
            if(tree[i].F + tree[i].S < tree[i + 1].F - tree[i + 1].S) {
                ans++;
                nearestLeft = tree[i].F + tree[i].S;
            } else {
                if(tree[i].F + tree[i].S < tree[i + 1].F) {
                    ans++;
                    nearestLeft = tree[i].F + tree[i].S;
                } else {
                    nearestLeft = tree[i].F;
                }
               
            }
        }
    }

    cout << ans;

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/