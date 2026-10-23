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
    ll x, y, z, k;
    cin >> x >> y >> z >> k;

    ll ans = 0;

    for (ll i = 1; i <= x; i++)
    {
        for (ll j = 1; j <= y; j++)
        {
            if (k % (i * j) != 0)
                continue;

            ll h = k / (i * j);

            if (h <= z)
            {
                ll ways = (x - i + 1) * (y - j + 1) * (z - h + 1);

                ans = max(ans, ways);
            }
        }
    }

    cout << ans << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;

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
Hoorhon nomio Zarimdaa aashtai nomio nebula
*/
