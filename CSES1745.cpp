#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

using namespace std;

const int MAX_N = 100;
const int MAX_SUM = 1e5;

bool dp[MAX_N + 1][MAX_SUM + 1];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> coins(n);

    for(int i = 0; i < n; i++)
        cin >> coins[i];
    
    dp[0][0] = true;

    for(int i = 1; i <= n; i++) {
        for(int curr = 0;  curr <= MAX_SUM; curr++) {
            dp[i][curr] = dp[i - 1][curr];
            int prev_sum = curr - coins[i - 1];
            if(prev_sum >= 0 && dp[i - 1][prev_sum]) {
                dp[i][curr] = true;
            }
        }
    }

    vector<int> possible;
	for (int sum = 1; sum <= MAX_SUM; sum++) {
		if (dp[n][sum]) { possible.push_back(sum); }
	}

	cout << (int)(possible.size()) << '\n';

	for (int sum : possible) { cout << sum << " "; }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/