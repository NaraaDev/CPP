#include<bits/stdc++.h>


#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

using namespace std;

const ll MOD = 1e9 + 7;
const int N = 5005;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


ll dp[N][N];

void uCan() {
    int n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++) dp[i][i] = a[i];

    for(int len = 2; len <= n; len++) {
        for(int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            if(len == 2) {
                dp[l][r] = max(a[l], a[r]);
            } else {
                dp[l][r] = max(
                    a[l] + min(dp[l+2][r], dp[l+1][r-1]),
                    a[r] + min(dp[l][r-2], dp[l+1][r-1])
                );
            }
        }
    }

    cout << dp[0][n-1] << "\n";
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