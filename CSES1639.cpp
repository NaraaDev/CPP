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

int dp[5005][5005];

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s, s1;
    cin >> s >> s1;
    vector<vector<int>> dp(s.size() + 1, vector<int>(s1.size() + 1, INT32_MAX));

    dp[0][0] = 0;

    for(int i = 0; i <= s.size(); i++) {
        for(int j = 0; j <= s1.size(); j++) {
            if(i != 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            }
            if(j != 0) {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
            if (i != 0 && j != 0) {
				int new_cost = dp[i - 1][j - 1] + (s[i - 1] != s1[j - 1]);
				dp[i][j] = min(dp[i][j], new_cost);
			}
        }
    }

    cout << dp[s.size()][s1.size()];

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
*/