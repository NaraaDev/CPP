#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back

const ll MOD = 1e9 + 7;
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    if (a == b)
        return a;
 
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int ans = 0;

        int nums[n];
        int maxx = INT_MIN;
        int maxDifference = 0;

        for(int i = 0; i < n; i++) {
            cin >> nums[i];
            maxx = max(maxx, nums[i]);
            maxDifference = max(maxDifference, maxx - nums[i]);
        }
        
        while(maxDifference > 0) {
            maxDifference /= 2;
            ans++;
        }

        cout << ans << '\n';

    }

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
2
0
3
*/