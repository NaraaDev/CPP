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
    int n, k;
    cin >> n >> k;

    vector<int> nums(n), save(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    for (int i = 0; i < n; i++)
        cin >> save[i];

    ll base = 0;
    vector<ll> prefix(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        if (save[i] == 1)
            base += nums[i];

        prefix[i + 1] = prefix[i];
        if (save[i] == 0)
            prefix[i + 1] += nums[i];
    }

    ll extra = 0;

    for (int i = 0; i + k <= n; i++)
        extra = max(extra, prefix[i + k] - prefix[i]);

    cout << base + extra << '\n';
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
