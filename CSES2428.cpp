#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;


const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;


    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 0;

    int left = 0;
    map<int, int> mp;
    for(int right = 0; right < n; right++) {
        mp[a[right]]++;
        while(mp.size() > k) {
            mp[a[left]]--;
            if(mp[a[left]] == 0) 
                mp.erase(a[left]);
            left++;
        }
        ans += (right - left + 1);
    }

    cout << ans;
    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/