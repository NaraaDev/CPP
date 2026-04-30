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

vector<vector<int> > divs(2e5 + 1, vector<int>() );

void solve() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(auto &p: nums)
        cin >> p;

    int ans = 0;

    
    for(int k : divs[n]) {
        int g = 0;
        for(int i = 0; i + k < n; i++) {
            g = gcd(g, abs(nums[i] - nums[i + k]));
        }
        if(g != 1) ans++;
    }

    cout << ans << '\n';

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    const int maxx = 2e5;
    for(int i = 1; i <= maxx; i++) {
        for(int j = i; j <= maxx; j += i) {
            divs[j].push_back(i);
        }
    }

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