#include <bits/stdc++.h>

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll binpow(ll a, ll b)
{

    ll res = 1;

    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b /= 2;
    }
    return res;
}

void solve()
{

    int n;
    cin >> n;

    vector<ll> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    ll ans = 0;

    vector<ll> prefix(n + 1, 0), suffix(n + 2, 0);

    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + nums[i - 1];

    for (int i = n; i > 0; i--)
        suffix[i] = suffix[i + 1] + nums[i - 1];

    for (int i = 1; i <= n; i++)
    {
        auto it = lower_bound(suffix.begin() + i + 1, suffix.end(), prefix[i], greater<ll>());
        if (it != suffix.end() && *it == prefix[i])
            ans = max(ans, prefix[i]);
    }

    cout << ans << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}

/*
N - ee shalga
Bitgii buuj ug
Сая сая мөрөөдөл минь удахгүй нэг нэгээрэ биелэж эхлэх болно.
Whatever happened, Whatever was, Whatever you endured,
Whatever changed — You can do it, you will improve.
Hoorhon nomio Zarimdaa aashtai nomio
*/
