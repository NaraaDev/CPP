#include<bits/stdc++.h>


#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;


ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll binpow(ll a, ll b) {

    ll res = 1;

    while(b > 0) {
        if(b & 1) {
            res = res * a;
        }
        a = a * a;
        b /= 2;
    }
    return res;
}

void solve() {
    
    int n;
    cin >> n;

    vector<int> nums(n);

    for(auto &p: nums)
        cin >> p;

    ll ans = 0;

    vector<int> cnt(n + 1, 0);

    for(int i = 0; i < n; i++)
        cnt[nums[i]]++;

    sort(cnt.begin(), cnt.end());

    vector<bool> ok(n + 1, false);
    int maxx = INT_MAX;
    for(int i = n; i >= 1; i--) {
        if(maxx <= 0) break;
        if(maxx > cnt[i]) {
            maxx = cnt[i];
            ans += cnt[i];
        } else if(maxx == cnt[i]) {
            maxx = cnt[i] - 1;
            ans += cnt[i] - 1;
        } else {
            ans += maxx - 1;
            maxx--;            
        }
    }


    cout << ans << '\n';

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;

}

/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/