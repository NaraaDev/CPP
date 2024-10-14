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
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, int> > v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i].F;
        v[i].S = i + 1;
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            ll target = v[i].F + v[j].F;
            int left = j + 1, right = n - 1; 
            while(left < right) {
                ll sum = target + v[left].F + v[right].F;
                if(sum == x) {
                    cout << v[i].S << ' ' << v[j].S << ' ' << v[left].S << ' ' << v[right].S;
                    return 0;
                }
                else if(sum > x) right--;
                else left++;
            }
        }
    }

    cout << "IMPOSSIBLE";

}

/*
RILY <3
NEVER GIVE UP!!!
*/