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

    int n, k;
    cin >> n >> k;

    ll x, a, b, c;
    cin >> x >> a >> b >> c;


    vector<ll> nums(n + 1);

    nums[1] = x;

    for(int i = 2; i <= n; i++)
        nums[i] = (nums[i - 1] * a + b) % c;

    vector<ll> prefixOr(n + 1, 0), suffixOr(n + 1, 0);

    for(int i = 1; i <= n; i++) {
        if((i - 1) % k == 0) prefixOr[i] = nums[i];
        else prefixOr[i] = prefixOr[i - 1] | nums[i];
    }
    ll ans = 0;

    for(int i = n; i >= 1; i--) {
        if(i % k == 0) suffixOr[i] = nums[i];
        else suffixOr[i] = suffixOr[i + 1] | nums[i];
    }

    for(int i = k; i <= n; i++) {
        if(i % k == 0) ans ^= prefixOr[i];
        else ans ^= prefixOr[i] | suffixOr[i - k + 1];
    }

    cout << ans;


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