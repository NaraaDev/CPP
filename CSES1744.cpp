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
    int a, b;
    cin >> a >> b;

    vector<vector<int> > dp(a + 1, vector<int> (b + 1, INT_MAX));
    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            if(i == j || i == 0 || j == 0) dp[i][j] = 0;
        }
    }
    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            if(i == j) continue;
            for(int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
            for(int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
            }
        }
    }

    cout << dp[a][b];

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