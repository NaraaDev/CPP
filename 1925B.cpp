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

    ll x, n;
    cin >> x >> n;

    vector<ll> possible;

    if (n == 1)
    {
        cout << x << '\n';
        return;
    }

    if (x % n == 0)
    {
        cout << x / n << '\n';
        return;
    }

    for (ll i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            possible.pb(i);

            if (i != x / i)
            {
                possible.pb(x / i);
            }
        }
    }

    ll ans = 1;
    sort(possible.begin(), possible.end());
    for (int i = 0; i < possible.size(); i++)
    {
        if (possible[i] * n > x)
            break;
        ans = max(ans, possible[i]);
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
