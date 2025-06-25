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
    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;
    vector<ll > dp(sum + 1, 0);

    if(sum % 2) {
        cout << 0;
        return;
    }
    dp[0] = 1;

    for(int i = 1; i < n; i++ ) {
        for(int j = sum / 2; j>= i; j--) {
            dp[j] += dp[j - i];
            dp[j] %= MOD;
        }
    }

    cout << dp[sum / 2];

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
*/