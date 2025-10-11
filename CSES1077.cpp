#include<bits/stdc++.h>


#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;

const ll MOD = 1e9 + 7;
const int N = 2e5 + 5;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void uCan() {

    vector<int> ans;

    int n, k;
    cin >> n >> k;

    vector<ll> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    ll sum = 0;

    for(int i = 0; i < k; i++)
        sum += nums[i];

    ans.pb(sum / k);

    for(int i = k; i < n; i++) {
        sum += nums[i];
        sum -= nums[i - k];
        ans.pb(cur);
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    // cin >> t;
    t = 1;

    while(t--) {
        uCan();
    }

    return 0;

}

/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever our souls are made of, hers and mine are the same.
People aren’t prisoners of fate, they’re prisoners of their own minds.
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
*/