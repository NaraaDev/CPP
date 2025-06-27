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

    int n , x;
    cin >> n >> x;
    
    vector<int> w(n);

    for(int &i: w)
        cin >> i;
    
    vector<pair<int ,int > > dp(1 << n, {1e9, 0});

    dp[0] = {1, 0};

    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            int weight = dp[mask].second;
            int rides = dp[mask].first;
            if(weight + w[i] <= x) {
                auto newState = mp(rides, weight + w[i]);
                dp[mask | (1 << i)] = min(dp[mask | (1 << i)], newState);
            } else {
                auto newState = mp(rides + 1, w[i]);
                dp[mask | (1 << i)] = min(dp[mask | (1 << i)], newState);
            }
        }
    }

    cout << dp[(1 << n) - 1].first;

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