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

    ll n, p;
    cin >> n >> p;

    ll ans = 0;

    vector<pair<ll, ll> > nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i].ss;
    
    for(int i = 0; i < n; i++) {
        cin >> nums[i].ff;
    }
    if(n == 1) {
        cout << p << '\n';
        return;
    }
    sort(nums.begin(), nums.end());
    if(p <= nums[0].ff) {
        cout << n * p << '\n';
        return;
    }
    
    ll remainderP = n - 1, ogohHun = 0;
    ans += p;
    for(int i = 0; i < n; i++) {
        if(nums[i].ff >= p) {
            ans += p * remainderP;
            break;
        }
        if(nums[i].ss >= remainderP) {
            ans += nums[i].ff * remainderP;
            break;
        } else {
            ans += nums[i].ss * nums[i].ff;
            ogohHun += nums[i].ss;
            remainderP -= nums[i].ss;
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