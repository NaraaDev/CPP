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

ll dp[1000005][2];

void uCan() {

    int n;
    cin >> n;


    dp[n][1] = 1;
    dp[n][0] = 1;

    for(int i = n - 1; i >= 1; i--) {
        dp[i][0] = (2LL * dp[i + 1][0] + dp[i + 1][1]) % MOD;
        dp[i][1] = (4LL * dp[i + 1][1] + dp[i + 1][0]) % MOD;
    }

    cout << (dp[1][0] + dp[1][1]) % MOD << '\n';

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

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