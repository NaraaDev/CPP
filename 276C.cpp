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
    int n, q;
    cin >> n >> q;

    int nums[n];

    ll ans = 0;
    ll cnt[n + 2];
    
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    for(int i = 0; i <= n + 1; i++)
        cnt[i] = 0;

    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cnt[l]++;
        cnt[r + 1]--;
    }

    for(int i = 1; i <= n; i++)
        cnt[i] += cnt[i - 1];
    
    sort(nums, nums + n);
    sort(cnt + 1, cnt + n + 1);

    for(int i = 1; i <= n; i++)
        ans += cnt[i] * nums[i - 1];

    cout << ans;

    return 0;

}

/*
RILY <3
NEVER GIVE UP!!!
25
*/